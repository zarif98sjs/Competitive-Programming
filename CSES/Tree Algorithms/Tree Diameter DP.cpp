
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

    /// diameter
    int diameter = 0;
    vector<int>f,g;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);
        f = vector<int>(len);
        g = vector<int>(len);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    void dfs(int u,int p)
    {
        vector<int>depths;

        for(int v:adj[u])
        {
            if(v==p) continue;

            dfs(v,u);

            depths.push_back(f[v]);

//            if(!depths.empty() && depths.back()>depths[0]) swap(depths.back(),depths[0]);
//            if(!depths.empty() && depths.back()>depths[1]) swap(depths.back(),depths[1]);
        }

        sort(ALL(depths));
        reverse(ALL(depths));

        DBG(u);
        DBG(depths);

        f[u] = 1;
        if(!depths.empty()) f[u] += depths[0];

        if((int)depths.size()>=2) g[u] = 1 + depths[0] + depths[1];

        diameter = max(diameter,max(f[u],g[u]));
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

    g.dfs(1,-1);
    cout<<g.diameter-1<<endl; /// as the answer is in terms of number of nodes
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


