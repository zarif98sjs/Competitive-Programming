
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

    /// for bipartite check
    vector<int>col,vis;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);
        col = vector<int>(len,0);
        vis = vector<int>(len,0);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    bool bipartite(int u)
    {
        vis[u] = true;

        for(int v:adj[u])
        {
            if(!vis[v])
            {
                col[v] = !col[u];

                if(bipartite(v)==false)
                    return false;
            }
            else if(col[v]==col[u])
                return false;
        }

        return true;
    }

    void solve()
    {
        bool ok = true;

        for(int i=1;i<=n;i++)
        {
            if(!vis[i] && !bipartite(i))
                ok = false;
        }

        if(!ok) cout<<"IMPOSSIBLE"<<endl;
        else
        {
            for(int i=1;i<=n;i++) cout<<col[i]+1<<" ";
            cout<<endl;
        }
    }
};

void solveTC()
{
    int n,m;
    cin>>n>>m;

    Graph g(n,false);

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
