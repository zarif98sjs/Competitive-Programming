
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

struct Graph
{
    int n;
    bool dir;
    vector<vector<int>>adj;
    vector<int>sz;
    vector<LL>dp;
    vector<LL>ans;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);
        sz = vector<int>(len);
        dp = vector<LL>(len);
        ans = vector<LL>(len);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    void dfs(int u,int p)
    {
        sz[u] = 1;

        for(int v:adj[u])
        {
            if(v!=p)
            {
                dfs(v,u);

                sz[u] += sz[v];
            }
        }
    }

    void init(int u,int p)
    {
        dp[u] = 0;

        for(int v:adj[u])
        {
            if(v!=p)
            {
                init(v,u);

                dp[u] += sz[v];
                dp[u] += dp[v];
            }
        }
    }

    void change_root(int old_root,int new_root)
    {
        /// removing new root's contribution
        sz[old_root] -= sz[new_root];
        dp[old_root] -= sz[new_root];
        dp[old_root] -= dp[new_root];

        /// adding old root as a child of new root
        sz[new_root] += sz[old_root];
        dp[new_root] += sz[old_root];
        dp[new_root] += dp[old_root];
    }

    void reroot(int u,int p)
    {
        ans[u] = dp[u];

        for(int v:adj[u])
        {
            if(v==p)
                continue;

            change_root(u,v);

            reroot(v,u);

            change_root(v,u);
        }
    }

    void solve()
    {
        dfs(1,-1);
        init(1,-1);
        reroot(1,-1);

        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
};

void solveTC()
{
    int n;
    cin>>n;

    Graph g(n,false);

    int m = n-1;

    while(m--)
    {
        int a,b;
        cin>>a>>b;

        g.add_edge(a,b);
    }

    g.solve();
}

int32_t main()
{
    optimizeIO();

    int tc = 1;
//    cin>>tc;

    while(tc--)
    {
        solveTC();
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

