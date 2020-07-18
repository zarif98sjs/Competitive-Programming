
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

const int nmax = 2e6+7;

LL ara[nmax];

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    LL sum ;
    LL lazy;

    bool assignment;
    bool flip;

    node()
    {
        sum = 0;
        lazy = 0;

        assignment = false;
        flip = false;
    }

    void create_leaf(LL val)
    {
        sum = val;
        lazy = 0;

        assignment = false;
        flip = false;
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

void push_flip(int v,int st,int mid,int en)
{
    int lc = v<<1, rc = lc|1;

    if(Tree[v].flip)
    {
        Tree[lc].sum = (mid-st+1) - Tree[lc].sum;
        Tree[rc].sum = (en-mid) - Tree[rc].sum;

        Tree[lc].flip = Tree[rc].flip = true;
        Tree[v].flip = false;
    }
}

void update_assign(int cur, int start, int end, int l,int r, LL value)
{
    if(l>r)
        return;

    if (l==start && r==end)
    {
        int mid = (start + end)>>1;
        push_flip(cur,start,mid,end);

        Tree[cur].sum = (r-l+1)*value;
        Tree[cur].lazy = value;
        Tree[cur].assignment = true;
    }
    else
    {
        int mid = (start + end)>>1;
        int lc = cur<<1, rc = lc|1;

        push_assign(cur,start,mid,end);

        update_assign(lc, start, mid,l,min(r,mid), value);
        update_assign(rc, mid+1, end,max(l,mid+1),r, value);

        Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
    }
}

void update_flip(int cur, int start, int end, int l,int r, int value = 1)
{
    if(l>r)
        return;

    if (l==start && r==end)
    {
        int mid = (start + end)>>1;
        push_assign(cur,start,mid,end);
        Tree[cur].sum = (r-l+1) - Tree[cur].sum;
        Tree[cur].flip = true;
    }
    else
    {
        int mid = (start + end)>>1;
        int lc = cur<<1, rc = lc|1;

        push_flip(cur,start,mid,end);

        update_flip(lc, start, mid,l,min(r,mid), value);
        update_flip(rc, mid+1, end,max(l,mid+1),r, value);

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
    push_flip(cur,start,mid,end);

    LL p1 = query(lc,start,mid,l,min(r,mid));
    LL p2 = query(rc,mid+1,end,max(l,mid+1),r);

    return p1+p2; /// sum

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

void DEBUG2(int n)
{
    for(int i=1;i<=n;i++)
    {
        query(1,1,n,i,i);
    }
}

int main()
{
    optimizeIO();

    WRITE;

    int tc;
    cin>>tc;

    int cs = 0;

    while(tc--)
    {
        CLEAR();

        int num;
        cin>>num;

        string f = "";

        for(int i=1;i<=num;i++)
        {
            int c;
            string s;
            cin>>c>>s;

            for(int j=1;j<=c;j++)
                f += s;

        }

        int n = f.size();
//        DBG(f);

        for(int i=1;i<=n;i++)
            ara[i] = f[i-1]-'0';

        build(1,1,n);

        cout<<"Case "<<++cs<<":\n";

        int q;
        cin>>q;

        int ql = 0;

        while(q--)
        {
//            DEBUG(n);

            string type;
            cin>>type;

            int l,r;
            cin>>l>>r;

            l++,r++;

            if(type=="F")
            {
                update_assign(1,1,n,l,r,1);
            }
            else if(type=="E")
            {
                update_assign(1,1,n,l,r,0);
            }
            else if(type=="I")
            {
                update_flip(1,1,n,l,r);
            }
            else
            {
                LL v = query(1,1,n,l,r);
                cout<<"Q"<<++ql<<": "<<v<<"\n";
            }
        }

    }

    return 0;
}

/**

2
2
5
10
2
1000
5
F 0 17
I 0 5
S 1 10
E 4 9
S 2 10
3
3
1
4
0
2
0
2
I 0 2
S 0 8
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


