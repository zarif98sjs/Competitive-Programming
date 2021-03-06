
/**

Maximum Flow Dinic
===================

Complexity : O(V^2 * E)

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

Dinic

0 based indexing

**/

struct Dinic
{
    typedef long long flow_type;

    struct Edge
    {
        int src,dst;
        flow_type capacity, flow;
        size_t rev; /// position of the reverse edge in destinations's adj list
    };

    int n, source, sink;
    vector<vector<Edge>> adj;
    vector<int>level, iter;

    Dinic(int n) : n(n), adj(n), level(n), iter(n) {}

    void add_edge(int src,int dst,flow_type capacity)
    {
        Edge forward{src,dst,capacity,0,adj[dst].size()};
        Edge reverse{dst,src,0,0,adj[src].size()};

        adj[src].push_back(forward);
        adj[dst].push_back(reverse); /// adding this edge for reverse graph
    }

    int level_graph()
    {
        level.assign(n,-1);
        level[source] = 0;

        queue<int>Q;
        Q.push(source);

        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            if(u==sink) break;

            for(auto &e:adj[u])
            {
                if(level[e.dst] == -1 && e.capacity - e.flow > 0)
                {
                    level[e.dst] = level[u] + 1;
                    Q.push(e.dst);
                }
            }
        }

        return level[sink];
    }

    flow_type dfs(int u,flow_type amount)
    {
        if(u==sink) return amount;
        for(int &it = iter[u] ; it<(int)adj[u].size(); it++)
        {
            Edge &e = adj[u][it], &r = adj[e.dst][e.rev];
            int v = e.dst;

            if(level[v]>level[u] && e.capacity-e.flow > 0)
            {
                flow_type sent = dfs(v,min(amount,e.capacity-e.flow));

                if(sent>0)
                {
                    e.flow += sent;
                    r.flow -= sent;

                    return sent;
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
        flow_type sent = -1;

        while(level_graph() >= 0)
        {
            sent = -1;
            fill(ALL(iter),0);

            while(sent != 0)
            {
                sent = dfs(source,LLONG_MAX);
                MAXFLOW += sent;
            }
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

        Dinic dn(nodes);

        for(int i=0;i<nodes-1;i++)
        {
            int m;
            cin>>m;

            for(int j=1; j<=m; j++)
            {
                int v;
                cin>>v;

                v--;

                LL cap = INT_MAX;

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
