
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

    /// for lca
    vector<int>parent;
    vector<int>L;
    vector<vector<int>>sptable;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);

        parent = vector<int>(len);
        L = vector<int>(len);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir)
            adj[v].push_back(u);
    }

    void dfs(int u,int par,int lvl)
    {
        parent[u] = par;
        L[u] = lvl;

        for(int v:adj[u])
        {
            if(v!=par)
                dfs(v,u,lvl+1);
        }
    }

    void lca_init()
    {
        sptable = vector<vector<int>>(n+1,vector<int>(20,-1));

        for(int i=1; i<=n; i++)
            sptable[i][0] = parent[i];

        for(int j=1; (1<<j)<n; j++)
            for(int i=1; i<=n; i++)
                if(sptable[i][j-1]!=-1)
                    sptable[i][j] = sptable[sptable[i][j-1]][j-1];
    }

    int Lift(int node,int level) /// lift the node up by this many level
    {
        int log;
        for(log = 1; (1<<log)<=L[node]; log++);
        log--;

        for(int i=log; i>=0; i--)
            if(level&(1<<i))
                node = sptable[node][i];

        return node;
    }

    int solve(int u,int k)
    {
        if(k>L[u]) return -1;

        return Lift(u,k);
    }
};

void solveTC()
{
    int n,q;
    cin>>n>>q;

    Graph g(n,false);

    for(int i=2; i<=n; i++)
    {
        int p;
        cin>>p;
        g.add_edge(i,p);
    }

    g.dfs(1,-1,0);
    g.lca_init();

    while(q--)
    {
        int u,k;
        cin>>u>>k;

        cout<<g.solve(u,k)<<endl;
    }
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
