
/**

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

/**

Ford Fulkerson

0 based indexing

**/

struct FordFulkerson
{
    typedef long long flow_type;

    struct Edge{
        int src,dst;
        flow_type capacity , flow;
        size_t rev; /// position of the reverse edge in destinations's adj list
    };

    int n, source, sink;
    vector<vector<Edge>> adj;
    vector<bool>vis;

    FordFulkerson(int n) : n(n) , adj(n) ,vis(n) {}

    void add_edge(int src,int dst,flow_type capacity)
    {
        Edge forward{src,dst,capacity,0,adj[dst].size()};
        Edge reverse{dst,src,0,0,adj[src].size()};

        adj[src].push_back(forward);
        adj[dst].push_back(reverse); /// adding this edge for reverse graph
    }

    flow_type dfs(int u,flow_type amount)
    {
        if(u==sink) return amount;

        vis[u] = true;

        for(auto &e:adj[u])
        {
            int v = e.dst;
            Edge &r = adj[v][e.rev];

            if(!vis[v] && e.capacity-e.flow > 0)
            {
                flow_type bottleneck = dfs(v,min(amount,e.capacity-e.flow));

                if(bottleneck>0)
                {
                    e.flow += bottleneck;
                    r.flow -= bottleneck;

                    return bottleneck;
                }
            }
        }

        return flow_type(0);
    }

    flow_type max_flow(int source,int sink)
    {
        this->source = source;
        this->sink = sink;

        flow_type MAXFLOW = 0;
        flow_type bottleneck = -1;

        while(bottleneck != 0)
        {
            fill(ALL(vis),false);
            bottleneck = dfs(source,LLONG_MAX);
            MAXFLOW += bottleneck;
        }

        return MAXFLOW;
    }
};

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int nodes;
        cin>>nodes;

        FordFulkerson dn(nodes);

        for(int i=0;i<nodes-1;i++)
        {
            int m;
            cin>>m;

            for(int j=1; j<=m; j++)
            {
                int v;
                cin>>v;

                v--;

                LL cap = 10;

                if(i==0 || v==nodes-1) cap = 1;
                dn.add_edge(i,v,cap);
            }
        }

        LL MAXFLOW = dn.max_flow(0,nodes-1);
        cout<<MAXFLOW<<endl;
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
