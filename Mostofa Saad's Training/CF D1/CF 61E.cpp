
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
#define endl "\n"
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

const int nmax = 1e6+7;

#define int long long

vector<int>ara;

/** Merge Sort Tree **/

struct node
{
    vector<int>v;

    void create_leaf(int val)
    {
        v.push_back(val);
    }

    void merge_nodes(node &A,node &B)
    {
        merge(ALL(A.v),ALL(B.v),back_inserter(v));
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

int query(int cur,int start,int end,int l,int r,int k) /** RANGE query <=k **/
{
    if(end<l || start>r)
        return 0;

    if(start>=l && end<=r)
    {
        return upper_bound(ALL(Tree[cur].v),k) - Tree[cur].v.begin();
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    int p1 = query(lc,start,mid,l,r,k);
    int p2 = query(rc,mid+1,end,l,r,k);

    return p1 + p2;
}

int solve(int n)
{
    int ans = 0;

    for(int i=2;i<=n-1;i++)
    {
        int cnt_large = i-1 - query(1,1,n,1,i-1,ara[i]);
        DBG(cnt_large);
        int cnt_less = query(1,1,n,i+1,n,ara[i]);   
        DBG(cnt_less);

        ans += cnt_less*cnt_large;
    }

    return ans;
}

int32_t main()
{
    optimizeIO();

    int n;
    cin>>n;

    ara = vector<int>(n+1);

    for(int i=1;i<=n;i++)
        cin>>ara[i];

    build(1,1,n);

    int ans = solve(n);
    cout<<ans<<endl;
    DBG(ans);

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


