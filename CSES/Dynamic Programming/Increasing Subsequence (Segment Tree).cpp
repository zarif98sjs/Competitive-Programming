/**
Problem : Longest Increasing Subsequence
**/


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

const int nmax = 2e5+7;
const LL LINF = 1e17;

int n;

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    LL mx = 0;

    void create_leaf(LL val)
    {
        mx=val;
    }

    void merge_nodes(node &A,node &B)
    {
        mx = max(A.mx , B.mx);
    }

};

const int nmax2 = nmax<<2;
node Tree[nmax2];

void build(int cur,int start,int end) /** build the segment tree **/
{
    if(start==end)
    {
        Tree[cur].create_leaf(0);
        return;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    build(lc,start,mid);
    build(rc,mid+1,end);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);

}

void update(int cur, int start, int end, int updex, LL value) /** POINT update , replaces the current value **/
{
    if(start == end)
    {
        Tree[cur].create_leaf(value);
        return;
    }

    int mid = (start + end)>>1;
    int lc = cur<<1, rc = lc|1;

    if (updex <= mid)
        update(lc, start, mid, updex, value);
    else
        update(rc, mid+1, end, updex, value);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
}

void query(node &res,int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(l>r) return;

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

vector<int> compress(vector<int> &v) /// compress v to [1,max distinct number range]
{
    vector<int>c = v;
    map<int,int>m;

    for(int x:c) m[x] = 1;

    int val = 0;
    for(auto x:m) m[x.F] = ++val;

    for(int &x:c) x = m[x];

    return c;
}

int solveLIS(vector<PII>&v)
{

    vector<PII> sorted = v;
    sort(ALL(sorted));

    build(1,1,n);

    for(int i=1;i<=n;i++)
    {
        int id = -sorted[i].S;

        node q;
        query(q,1,1,n,1,id-1);
        int mx_till_now = q.mx;

//        cout<<mx_till_now<<endl;

//        if(i>0 && sorted[i].F==sorted[i-1].F) update(1,1,n,id,mx_till_now);
        update(1,1,n,id,mx_till_now+1);
    }

    node q;
    query(q,1,1,n,1,n);

    int lis = q.mx;
    return lis;
}

int main()
{
    optimizeIO();

    cin>>n;

    vector<int> v(n+1,0);

    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;

        v[i] = x;
    }

    v = compress(v);

    vector<PII>p(n+1);

    for(int i=1;i<=n;i++) p[i] = {v[i],-i};

    int ans = solveLIS(p);
    cout<<ans<<endl;

    return 0;
}
/**
5
1 6 2 3 5
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
    for(T i:v)
    {
        os<<i<<" " ;
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
