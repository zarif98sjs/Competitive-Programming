
/**

Idea :
We need to know if there is a cycle in the path a->b.
Now , we find all the nodes that are part of the negative cycle in the original graph . Then we have to check
if there is a path from these negative cycle nodes to b .
To do this efficiently , my idea is to reverse the graph and check if there exists a path from b to any of these nodes

**/

/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;


inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 3e3+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

struct edge
{
    int a,b,w;
};

int n,m;
vector<edge>e;

struct Graph
{
    int n;
    bool dir;
    vector<vector<int>>adj;

    vector<bool>vis;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);
        vis = vector<bool>(len,false);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    void dfs(int u)
    {
        vis[u] = true;

        for(int v:adj[u])
        {
            if(!vis[v])
                dfs(v);
        }
    }
};


void bellman_ford(int s,Graph &revg)
{
    vector<LL>dist(nmax,LINF);
    bool is_negcycle;

    dist[s] = 0;

    set<int>negative_nodes;

    for(int i=1; i<=n; i++) /** n-1 + 1 times , last 1 time is to check if there is a negative weight cycles **/
    {
        is_negcycle = false;

        for(int j=0; j<m; j++)
        {
            if(dist[e[j].a]<LINF)
            {
                if(dist[e[j].a] + e[j].w < dist[e[j].b])
                {
                    dist[e[j].b] = max(-LINF, dist[e[j].a] + e[j].w);
                    is_negcycle = true; /** if there is a relaxation in nth iteration this will become true **/

                    if(i==n)
                    {
                       negative_nodes.insert(e[j].a);
                       negative_nodes.insert(e[j].b);
                    }
                }
            }
        }
    }


    for(int x:negative_nodes)
    {
        if(revg.vis[x])
        {
            cout<<-1<<endl;
            return;
        }
    }

    cout<<-1*dist[n]<<endl;
}


int main()
{
    optimizeIO();

    cin>>n>>m;

    Graph revg(n,true);

    for(int i=0; i<m; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;

        e.push_back({a,b,-1*w}); /** Directed **/

        revg.add_edge(b,a);
    }

    revg.dfs(n);

    bellman_ford(1,revg);

    return 0;
}


