
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
const LL mod = 1e9+7;

LL add(LL a,LL b)
{
    return (a+b)%mod;
}

struct Graph
{
    int n;
    bool dir;
    vector<vector<PII>>adj;

    vector<LL>dist;

    /// problem
    vector<LL>minp_num;
    vector<LL>minf;
    vector<LL>maxf;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<PII>>(len);
        dist = vector<LL>(len,INF);

        minp_num = vector<LL>(len,0);
        minf = vector<LL>(len,0);
        maxf = vector<LL>(len,0);
    }

    void add_edge(int u,int v,int c)
    {
        adj[u].push_back({v,c});
        if(!dir) adj[v].push_back({u,c});
    }

    void dijkstra(int s)
    {
        priority_queue< PLL,vector<PLL>,greater<PLL> >PQ;
        dist[s] = 0;
        minp_num[s] = 1;
        PQ.push({0,s});

        while(!PQ.empty())
        {
            int now = PQ.top().S;
            LL now_d = PQ.top().F;
            PQ.pop();

            if(now_d > dist[now]) continue; /// OPTIMIZATIONNNNNNNNNNN : WOAH . DIDNT KNOW IT BEFORE

            for(auto x:adj[now])
            {
                int next = x.F;
                LL ed = x.S;

                if(dist[now] + ed < dist[next])
                {
                    dist[next] = dist[now] + ed;
                    minp_num[next] = minp_num[now];
                    minf[next] = minf[now]+1;
                    maxf[next] = maxf[now]+1;

                    PQ.push({dist[next],next});
                }
                else if(dist[now] + ed == dist[next])
                {
                    minp_num[next] = add(minp_num[next],minp_num[now]);
                    minf[next] = min(minf[next],minf[now]+1);
                    maxf[next] = max(maxf[next],maxf[now]+1);
                }
            }
        }
    }

    void solve()
    {
        dijkstra(1);
        cout<<dist[n]<<endl;
        cout<<minp_num[n]<<endl;
        cout<<minf[n]<<endl;
        cout<<maxf[n]<<endl;
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

