
/**

s(u) = v(u) + Summation all s(child)
dp(u) = Summation all [ dp(child) + s(child) ]

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

const int nmax = 2e5+7;

#define int long long

vector<vector<int>>adj;

vector<int>v;
vector<int>dp;
vector<int>s;

int ans = 0;

void init_s(int u,int p)
{
    s[u] = v[u];

    for(int v:adj[u])
    {
        if(v!=p)
        {
            init_s(v,u);

            s[u] += s[v];
        }
    }
}

void init_dp(int u,int p)
{
    dp[u] = 0;

    for(int v:adj[u])
    {
        if(v!=p)
        {
            init_dp(v,u);

            dp[u] += dp[v];
            dp[u] += s[v];
        }
    }
}

void change_root(int old_root,int new_root)
{
    /// removing new root's contribution
    s[old_root] -= s[new_root];
    dp[old_root] -= s[new_root];
    dp[old_root] -= dp[new_root];

    /// adding old root as a child of new root
    s[new_root] += s[old_root];
    dp[new_root] += s[old_root];
    dp[new_root] += dp[old_root];
}

void dfs(int u,int p)
{
    ans = max(ans,dp[u]);

    for(int v:adj[u])
    {
        if(v!=p)
        {
            change_root(u,v);

            dfs(v,u);

            change_root(v,u);
        }
    }
}

void INIT(int len)
{
    adj = vector<vector<int>>(len);
    dp = vector<int>(len,0);
    s = vector<int>(len,0);
    v = vector<int>(len,0);
}

int32_t main()
{
    optimizeIO();

    int n;
    cin>>n;

    INIT(n+1);

    for(int i=1;i<=n;i++)
        cin>>v[i];

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init_s(1,-1);
    DBG(s);
    init_dp(1,-1);
    DBG(dp);
    dfs(1,-1);
    cout<<ans<<endl;
    DBG(ans);

    return 0;
}

/**
6
5 2 3 3 2 4
1 2
2 3
2 4
3 5
3 6
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


