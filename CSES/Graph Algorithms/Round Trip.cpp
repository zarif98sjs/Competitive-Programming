
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

    /// for cycle check
    vector<int>vis,par;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);
        vis = vector<int>(len,0);
        par = vector<int>(len,0);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    int cycle_start = -1 , cycle_end = -1;

    bool noCycle(int u,int p)
    {
        vis[u] = true;
        par[u] = p;

        for(int v:adj[u])
        {
            if(!vis[v])
            {
                if(noCycle(v,u)==false)
                    return false;
            }
            else if(v != p)
            {
                cycle_start = v;
                cycle_end = u;

                par[v] = u;
                return false;
            }
        }

        return true;
    }

    void print_cycle()
    {
        vector<int>path;
        int v = cycle_end;

        path.push_back(cycle_start);
        while(v!=cycle_start)
        {
            path.push_back(v);
            v = par[v];
        }
        path.push_back(cycle_start);

        cout<<path.size()<<endl;
        for(int x:path) cout<<x<<" ";
        cout<<endl;
//        DBG(path);
    }

    void solve()
    {
        bool cycle = false;

        for(int i=1;i<=n;i++)
        {
            if(!vis[i] && !noCycle(i,-1))
            {
                cycle = true;
                print_cycle();
                break;
            }
        }

        if(!cycle) cout<<"IMPOSSIBLE"<<endl;
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
