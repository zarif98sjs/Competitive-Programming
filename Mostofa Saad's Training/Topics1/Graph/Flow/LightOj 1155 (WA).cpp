
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("in.txt", "r", stdin)
#define WRITE       freopen("way1.txt", "w", stdout)

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

#define int long long

struct Dinic
{
    typedef long long flow_type;

    struct Edge{
        int src,dst;
        flow_type capacity , flow;
        size_t rev; /// position of the reverse edge in destinations's adj list
    };

    int n, source, sink;
    vector<vector<Edge>> adj;
    vector<int>level , next_iter;
    vector<flow_type>node_cap;
    /// next_iter : Shimon Even and Alon Atai Optmization

    Dinic(int n) : n(n) , adj(n) , level(n) , next_iter(n) ,node_cap(n) {}

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
                flow_type max_possible = min(node_cap[u],e.capacity-e.flow); /// if possible , then only go to next level
                if(level[e.dst] == -1 && max_possible > 0)
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
        for(int &it = next_iter[u] ;it<(int)adj[u].size();it++) /// by tracking iterator this way , we won't have to delete the edges with bottleneck capacity : Shimon Even and Alon Atai Optmization
        {
            Edge &e = adj[u][it] , &r = adj[e.dst][e.rev];
            int v = e.dst;
            flow_type max_possible = min(node_cap[u],e.capacity-e.flow); /// can't overflow node capacity
//            cout<<u<<" -> "<<v<<" : "<<fl<<endl;

            if(level[v]>level[u] && max_possible > 0)
            {
                flow_type bottleneck = dfs(v,min(amount,max_possible));

                if(bottleneck>0)
                {
//                    cout<<u<<" --> "<<v<<endl;

                    node_cap[u] -= bottleneck;
//                    node_cap[v] += bottleneck;

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

        while(level_graph() >= 0)
        {
            bottleneck = -1;
            fill(ALL(next_iter),0);

            while(bottleneck != 0)
            {
                bottleneck = dfs(source,LLONG_MAX);
//                DBG(bottleneck);
                MAXFLOW += bottleneck;
            }
        }

        DBG(node_cap);

        return MAXFLOW;
    }
};

int32_t main()
{
    optimizeIO();

//    READ;
//    WRITE;

    int tc;
    cin>>tc;

    int cs = 0;

    while(tc--)
    {
        int nodes;
        cin>>nodes;

        nodes += 2;

        Dinic dn(nodes);

        dn.node_cap[0] = dn.node_cap[nodes-1] = INT_MAX;
        for(int i=1;i<nodes-1;i++) cin>>dn.node_cap[i];

        int edges;
        cin>>edges;

        while(edges--)
        {
            int a , b, cap;
            cin>>a>>b>>cap;

            dn.add_edge(a,b,cap);
        }

        int B,D;
        cin>>B>>D;

        for(int i=1;i<=B;i++)
        {
            int v;
            cin>>v;
            dn.add_edge(0,v,INT_MAX);
        }

        for(int i=1;i<=D;i++)
        {
            int v;
            cin>>v;
            dn.add_edge(v,nodes-1,INT_MAX);
        }

        LL MAXFLOW = dn.max_flow(0,nodes-1);

        cout<<"Case "<<++cs<<": "<<MAXFLOW<<endl;
    }
    return 0;
}

/**
1
4
100 100 100 100
5
1 2 3
1 3 2
2 3 5
2 4 2
3 4 3
1 1
1 4

1
4
2 3 2 3
5
1 2 3
1 3 2
4 2 5
2 4 2
3 4 3
1 1
1 4

148 says: node_cap = [ 2147483494 0 45 74 0 0 15 0 0 57 67 0 24 21 2147483647  ]
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
