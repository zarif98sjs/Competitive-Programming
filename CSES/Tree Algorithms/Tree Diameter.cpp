
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
    vector<int>d;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);
        d = vector<int>(len);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    void dfs(int u,int p)
    {
        if(p != -1) d[u] = d[p] + 1;

        for(int v:adj[u])
        {
            if(v==p) continue;

            dfs(v,u);
        }
    }

    int diameter()
    {
        d[1] = 0;
        dfs(1,-1);

        int farthest1 = -1;
        int mx1 = -1;

        for(int i=1;i<=n;i++)
        {
            if(d[i]>mx1)
            {
                mx1 = d[i];
                farthest1 = i;
            }
        }

        d[farthest1] = 0;
        dfs(farthest1,-1);

        int farthest2 = -1;
        int mx2 = -1;

        for(int i=1;i<=n;i++)
        {
            if(d[i]>mx2)
            {
                mx2 = d[i];
                farthest2 = i;
            }
        }

        return mx2;
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

    int di = g.diameter();
    cout<<di<<endl;
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

