
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

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
    LL g;

    void create_leaf(LL val)
    {
        g=val;
    }

    void merge_nodes(node &A,node &B)
    {
        g = __gcd(A.g,B.g);
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

void query(node &res,int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(start>=l && end<=r)
    {
        res = Tree[cur];
        return;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    if(r<=mid)
        query(res,lc,start,mid,l,r);
    else if(l>mid)
        query(res,rc,mid+1,end,l,r);
    else
    {
        node left,right;
        query(left,lc,start,mid,l,r);
        query(right,rc,mid+1,end,l,r);
        res.merge_nodes(left,right);
    }
}


struct nodeM
{
    vector<int>v;

    void create_leaf(int val)
    {
        v.push_back(val);
    }

    void merge_nodes(nodeM &A,nodeM &B)
    {
        merge(ALL(A.v),ALL(B.v),back_inserter(v));
    }

};

//const int nmax2 = nmax<<2;
nodeM TreeM[nmax2];

void buildM(int cur,int start,int end) /** build the segment tree **/
{
    if(start==end)
    {
        TreeM[cur].create_leaf(ara[start]);
        return;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    buildM(lc,start,mid);
    buildM(rc,mid+1,end);

    TreeM[cur].merge_nodes(TreeM[lc],TreeM[rc]);

}

int queryM(int cur,int start,int end,int l,int r,int a,int b) /** RANGE query **/
{
    if(end<l || start>r)
        return 0;

    if(start>=l && end<=r)
    {
        return upper_bound(ALL(TreeM[cur].v),b) - lower_bound(ALL(TreeM[cur].v),a);
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    int p1 = queryM(lc,start,mid,l,r,a,b);
    int p2 = queryM(rc,mid+1,end,l,r,a,b);

    return p1 + p2;
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>ara[i];

    build(1,1,n);
    buildM(1,1,n);

    int q;
    cin>>q;

    while(q--)
    {
        int l ,r;
        cin>>l>>r;

        node t;
        query(t,1,1,n,l,r);

        int gcd = t.g;

        int live = queryM(1,1,n,l,r,gcd,gcd);
        int die = (r-l+1) - live;

        cout<<die<<endl;
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


