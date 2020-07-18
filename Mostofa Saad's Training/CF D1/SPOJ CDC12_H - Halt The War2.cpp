
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

const int nmax = 1e5+7;
LL ara[nmax];

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    LL sum ;
    LL lazy;

    node()
    {
        sum = 0;
        lazy = 0;
    }

    void create_leaf(LL val)
    {
        sum = val;
        lazy = 0;
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

void push(int v) {

    int lc = v<<1, rc = lc|1;

    Tree[lc].sum += Tree[v].lazy;
    Tree[lc].lazy += Tree[v].lazy;

    Tree[rc].sum += Tree[v].lazy;
    Tree[rc].lazy += Tree[v].lazy;

    Tree[v].lazy = 0;

}

void update(int cur, int start, int end, int l,int r, LL add)
{
    if(l>r)
        return;

    if (l==start && r==end)
    {
        Tree[cur].sum += (r-l+1)*add;
        Tree[cur].lazy += add;
    }
    else
    {
        push(cur);

        int mid = (start + end)>>1;
        int lc = cur<<1, rc = lc|1;

        update(lc, start, mid,l,min(r,mid), add);
        update(rc, mid+1, end,max(l,mid+1),r, add);

        Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
    }
}

LL query(int cur,int start,int end,int l,int r) /** RANGE query **/
{
//    DBG(cur);
//    DBG(start);
//    DBG(end);
//    DBG(l);
//    DBG(r);

    if(l>r)
        return 0;

    if(start>=l && end<=r)
    {
//        DBG(Tree[cur].sum);
//        DBG(Tree[cur].lazy);
        return Tree[cur].sum;
    }

    push(cur);

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

//    LL p1 = 0 , p2 = 0;
//
//    if(r<=mid)
//        p1 = query(lc,start,mid,l,r);
//    else if(l>mid)
//        p2 = query(rc,mid+1,end,l,r);
//    else
//    {
//        p1 = query(lc,start,mid,l,r);
//        p2 = query(rc,mid+1,end,l,r);
//    }

    LL p1 = query(lc,start,mid,l,min(r,mid));
    LL p2 = query(rc,mid+1,end,max(l,mid+1),r);

    return p1+p2; /// sum

}

void CLEAR()
{
    for(int i=0;i<nmax2;i++)
        Tree[i].create_leaf(0);
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    int cs = 1;

    while(tc--)
    {
        int n,q;
        cin>>n>>q;

        for(int i=1;i<=n;i++)
            ara[i] = 0;

        CLEAR();
//        build(1,1,n);

        cout<<"Scenario #"<<cs<<":\n";
        cs++;

        while(q--)
        {
            string s;
            int l,r;
            cin>>s>>l>>r;

            if(s=="modification")
            {
                update(1,1,n,l,r,1);
                cout<<"OK\n";
            }
            else
            {
                LL t = query(1,1,n,l,r);
                cout<<t<<"\n";
            }
        }
    }

    return 0;
}

/**

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


