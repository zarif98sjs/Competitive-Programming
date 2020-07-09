
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
const LL LINF = 1e18+7;

LL h[nmax];
LL dp[nmax];
LL prv[nmax];
map<LL,LL>M;

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    PLL mx; /// {mx,mx_id}

    node()
    {
        mx = {0,0};
    }

    void create_leaf(LL val,LL id)
    {
        mx = {val,id};
    }

    void merge_nodes(node &A,node &B)
    {
        mx = max(A.mx,B.mx);
    }

};

const int nmax2 = nmax<<2;
node Tree[nmax2];

void update(int cur, int start, int end, int updex, LL value,LL id) /** POINT update , replaces the current value **/
{
    if (start == end)
    {
        Tree[cur].create_leaf(value,id); /// {value,id} , NOT {value,start}
        return;
    }

    int mid = (start + end)>>1;
    int lc = cur<<1, rc = lc|1;

    if (updex <= mid)
        update(lc, start, mid, updex, value,id);
    else
        update(rc, mid+1, end, updex, value,id);

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

int main()
{
    optimizeIO();

    LL n,d;
    cin>>n>>d;

    for(LL i=1;i<=n;i++)
        cin>>h[i] , M[h[i]] = 0 , dp[i] = 0;

    int id = 0;

    for(auto &x:M) x.S = ++id;

    M[-LINF] = 0;
    M[LINF] = id+1;

    for(LL i=1;i<=n;i++)
    {
        int ID = M[h[i]];
        int l = (--M.upper_bound(h[i]-d))->S; /// <= h[i] - d
        int r = (M.lower_bound(h[i]+d))->S; /// >= h[i] + d

        node t1,t2;
        if(l>=1) query(t1,1,1,n,1,l);
        if(r<=n)   query(t2,1,1,n,r,n);

        PLL p = max(t1.mx,t2.mx);

        dp[i] = p.F + 1;
        prv[i] = p.S;

        update(1,1,n,ID,dp[i],i);
    }

    PII ans = {0,0};

    for(LL i=1;i<=n;i++)
    {
        if(dp[i]>ans.F)
            ans = {dp[i],i};
    }

    vector<LL>route;
    int p = ans.S;
    while(p!=0)
    {
        route.push_back(p);
        p = prv[p];
    }

    cout<<ans.F<<endl;

    reverse(ALL(route));
    for(LL x:route)
        cout<<x<<" ";
    cout<<endl;

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


