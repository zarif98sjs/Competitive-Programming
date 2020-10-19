
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

    vector<vector<LL>>dp;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<PII>>(len);
        dp = vector<vector<LL>>(len,vector<LL>(2,INF));
    }

    void add_edge(int u,int v,int c)
    {
        adj[u].push_back({v,c});
        if(!dir) adj[v].push_back({u,c});
    }

    void dijkstra(int s)
    {
        priority_queue< PLL,vector<PLL>,greater<PLL> >PQ;

        dp[s][0] = 0; /// 0 -> no coupon until now
        dp[s][1] = 0; /// 1 -> used up a coupon

        PQ.push({0,s});

        while(!PQ.empty())
        {
            int u = PQ.top().S;
            LL now_d = PQ.top().F;
            PQ.pop();

            if(now_d!=dp[u][1])
                continue; /// OPTIMIZATIONNNNNNNNNNN : WOAH . DIDNT KNOW IT BEFORE

            for(auto x:adj[u])
            {
                int v = x.F;
                LL ed = x.S;

                bool relax = false;

                if(dp[u][0] + ed < dp[v][0]) /// haven't used coupon yet
                {
                    dp[v][0] = dp[u][0] + ed;
                    relax = true;
                }
                if(dp[u][0] + ed/2 < dp[v][1]) /// haven't used coupon yet , using coupon in this edge
                {
                    dp[v][1] = dp[u][0] + ed/2;
                    relax = true;
                }
                if(dp[u][1] + ed < dp[v][1]) /// already used coupon
                {
                    dp[v][1] = dp[u][1] + ed;
                    relax = true;
                }

                if(relax)
                {
                    PQ.push({dp[v][1],v});
                }
            }
        }
    }

    void solve()
    {
        dijkstra(1);
        cout<<dp[n][1]<<endl;
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

