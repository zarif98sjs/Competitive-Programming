
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
#define WRITE       freopen("way2.txt", "w", stdout)

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
    /// next_iter : Shimon Even and Alon Atai Optmization

    Dinic(int n) : n(n) , adj(n) , level(n) , next_iter(n) {}

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
        for(int &it = next_iter[u] ;it<(int)adj[u].size();it++) /// by tracking iterator this way , we won't have to delete the edges with bottleneck capacity : Shimon Even and Alon Atai Optmization
        {
            Edge &e = adj[u][it] , &r = adj[e.dst][e.rev];
            int v = e.dst;

            if(level[v]>level[u] && e.capacity-e.flow > 0)
            {
                flow_type bottleneck = dfs(v,min(amount,e.capacity-e.flow));

                if(bottleneck>0)
                {
//                    cout<<u<<" --> "<<v<<endl;

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

        return MAXFLOW;
    }
};


int32_t main()
{
    optimizeIO();
    READ;
    WRITE;

    int tc;
    cin>>tc;

    int cs = 0;

    while(tc--)
    {
        int nodes;
        cin>>nodes;

        Dinic dn(2*nodes + 2);

        for(int i=1;i<=nodes;i++)
        {
            int cap;
            cin>>cap;

            dn.add_edge(i,i+nodes,cap);
        }

        int edges;
        cin>>edges;

        while(edges--)
        {
            int a , b, cap;
            cin>>a>>b>>cap;

            dn.add_edge(a+nodes,b,cap);
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
            dn.add_edge(v+nodes,2*nodes+1,INT_MAX);
        }

        LL MAXFLOW = dn.max_flow(0,2*nodes+1);

        cout<<"Case "<<++cs<<": "<<MAXFLOW<<endl;
    }
    return 0;
}

/**
1
13
1 45 74 35 19 66 13 82 57 69 2 92 54
37
11 8 43
2 3 47
2 11 47
4 12 80
6 9 51
4 11 72
8 7 46
3 9 13
9 12 22
12 1 66
8 5 54
10 8 39
7 9 7
5 13 30
3 5 50
2 13 93
11 9 92
1 6 57
9 4 31
4 3 3
5 12 94
13 12 33
2 4 16
1 12 8
1 4 65
11 7 96
8 13 45
10 7 49
10 11 92
3 10 94
4 6 95
9 1 50
1 3 38
8 6 96
7 2 87
8 9 63
8 12 19
5 8
4 13 8 10 1 6 5 12 2 9 7 3 11

25 --> 27
12 --> 25
17 --> 12
4 --> 17
0 --> 4
134 says: bottleneck = 35
25 --> 27
12 --> 25
26 --> 12
13 --> 26
0 --> 13
134 says: bottleneck = 33
20 --> 27
7 --> 20
21 --> 7
8 --> 21
0 --> 8
134 says: bottleneck = 13
18 --> 27
5 --> 18
21 --> 5
8 --> 21
0 --> 8
134 says: bottleneck = 19
19 --> 27
6 --> 19
21 --> 6
8 --> 21
0 --> 8
134 says: bottleneck = 50
24 --> 27
11 --> 24
23 --> 11
10 --> 23
0 --> 10
134 says: bottleneck = 2
19 --> 27
6 --> 19
14 --> 6
1 --> 14
0 --> 1
134 says: bottleneck = 1
134 says: bottleneck = 0
19 --> 27
6 --> 19
21 --> 6
7 --> 21
23 --> 7
10 --> 23
0 --> 10
134 says: bottleneck = 13
134 says: bottleneck = 0
Case 1: 166
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
