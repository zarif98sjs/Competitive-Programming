
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
const LL INF = 1e15;

struct Graph
{
    int n;
    bool dir;
    vector<vector<PII>>adj;

    vector<LL>dist;

    /// for topsort
    vector<int>stk;
    vector<bool>vis;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<PII>>(len);
        dist = vector<LL>(len,INF);
        vis = vector<bool>(len,false);
    }

    void add_edge(int u,int v,int c)
    {
        adj[u].push_back({v,c});
        if(!dir) adj[v].push_back({u,c});
    }

    /// topsort
    void dfs(int u)
    {
        vis[u]=true;

        for(auto next:adj[u])
        {
            int v = next.F;

            if(!vis[v])
                dfs(v);
        }

        stk.push_back(u);
    }

    void relax_in_topological_order()
    {

       for(int i=1;i<=n;i++)
            if(!vis[i])
                dfs(i);
//        dfs(1); /// connected , so only 1 dfs is enough

        int st = stk.back();
        dist[st] = 0;

        while(!stk.empty())
        {
            int u = stk.back();
            stk.pop_back();

            DBG(u);

            for(auto x:adj[u])
            {
                int v = x.F;
                int ed = x.S;

                if(dist[u]+ed < dist[v])
                    dist[v] = dist[u] + ed;
            }
        }

        for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
        cout<<endl;
    }



};

void solveTC()
{
    int n,m;
    cin>>n>>m;

    Graph g(n,true);

    for(int i=0; i<m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        g.add_edge(a,b,c);
    }

    g.relax_in_topological_order();
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


