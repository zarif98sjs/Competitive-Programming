
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#endif

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e4+7;

LL ara[nmax];

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    LL sum ;
    LL lazy;
    bool assignment;

    node()
    {
        sum = 0;
        lazy = 0;

        assignment = false;
    }

    void create_leaf(LL val)
    {
        sum = val;
        lazy = 0;

        assignment = false;
    }

    void merge_nodes(node &A,node &B)
    {
        sum = A.sum + B.sum;
    }

};

const int nmax2 = nmax<<2;
node Tree[nmax2];

void build(int cur,int start,int end) /** build the segment tree **/
{
    if(start==end)
    {
        Tree[cur].create_leaf(ara[start]);
        return;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    build(lc,start,mid);
    build(rc,mid+1,end);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);

}

void push_assign(int v,int st,int mid,int en)
{
    int lc = v<<1, rc = lc|1;

    if(Tree[v].assignment)
    {
        Tree[lc].sum = (mid-st+1)*Tree[v].lazy;
        Tree[rc].sum = (en-mid)*Tree[v].lazy;

        Tree[lc].lazy = Tree[rc].lazy = Tree[v].lazy;
        Tree[v].lazy = 0;

        Tree[lc].assignment = Tree[rc].assignment = true;
        Tree[v].assignment = false;
    }
}

void update(int cur, int start, int end, int l,int r, LL value)
{
    if(l>r)
        return;

    if (l==start && r==end)
    {
        Tree[cur].sum = (r-l+1)*value;
        Tree[cur].lazy = value;
        Tree[cur].assignment = true;
    }
    else
    {
        int mid = (start + end)>>1;
        int lc = cur<<1, rc = lc|1;

        push_assign(cur,start,mid,end);

        update(lc, start, mid,l,min(r,mid), value);
        update(rc, mid+1, end,max(l,mid+1),r, value);

        Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
    }
}

LL query(int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(l>r)
        return 0;

    if(start>=l && end<=r)
    {
        return Tree[cur].sum;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    push_assign(cur,start,mid,end);

    LL p1 = query(lc,start,mid,l,min(r,mid));
    LL p2 = query(rc,mid+1,end,max(l,mid+1),r);

    return p1+p2;

}

void CLEAR()
{
    for(int i=0;i<nmax2;i++)
        Tree[i].create_leaf(0);
}

void DEBUG(int n)
{
    cout<<"Current State : ";
    for(int i=1;i<=n;i++)
    {
        LL t = query(1,1,n,i,i);

        cout<<t<<" ";
    }
    cout<<endl;
}

/** Bit Sieve **/

const int pnmax = 1e8+7;
LL LIM;
bitset<pnmax> bs;   /// can sieve upto 1e8 in ~ 1 sec

void bit_sieve(LL upperbound)
{
    LIM = upperbound + 1;
    bs.set();                                     /// set all bits to 1
    bs[0] = bs[1] = 0;
    for (LL i = 2; i*i <= LIM; i++) /** If I don't want to know the primes , it is enough to loop upto sqrt(LIM) here **/
        if (bs[i])
        {
            for (LL j = i * i; j <= LIM; j += i)
                bs[j] = 0;
        }
}

bool isPrime(LL N)
{
    if (N <= LIM)
        return bs[N];                   /// O(1) for small primes
}

int main()
{
    optimizeIO();

    bit_sieve(1e6);

    int tc;
    scanf("%d",&tc);

    int cs = 1;

    while(tc--)
    {
        CLEAR();

        int n,q;
        scanf("%d %d",&n,&q);

        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);

            ara[i] = isPrime(x);
        }

        build(1,1,n);

        cout<<"Case "<<cs<<":\n";
        cs++;

        while(q--)
        {
//            DEBUG(n);

            int type;
            scanf("%d",&type);

            if(type==0)
            {
                int l,r,val;
                scanf("%d %d %d",&l,&r,&val);

                update(1,1,n,l,r,isPrime(val));
            }
            else
            {
                int l,r;
                scanf("%d %d",&l,&r);

                LL t = query(1,1,n,l,r);

                cout<<t<<"\n";
            }
        }
    }

    return 0;
}

/**

5
1 2 3 4 5

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


