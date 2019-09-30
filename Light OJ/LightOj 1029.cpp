
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

struct Edge {
    int src, dest, weight;
};

// Comparison object to be used to order the Edges
struct compare1
{
    inline bool operator() (Edge const &a, Edge const &b)
    {
        return (a.weight > b.weight);
    }
};

struct compare2
{
    inline bool operator() (Edge const &a, Edge const &b)
    {
        return (a.weight < b.weight);
    }
};

class DisjointSet
{
    unordered_map<int, int> parent;
public:

    void makeSet(int N)
    {
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }

    int Find(int k)
    {
        // if k is root
        if (parent[k] == k)
            return k;

        return Find(parent[k]);
    }

    void Union(int a, int b)
    {
        int x = Find(a);
        int y = Find(b);

        parent[x] = y;
    }
};

// construct MST using Kruskal's algorithm
vector<Edge> KruskalAlgoMinST(vector<Edge> edges, int N)
{
    sort(edges.begin(), edges.end(), compare1());
    // stores edges present in MST
    vector<Edge> MST;

    // initialize DisjointSet class
    DisjointSet ds;

    // create singleton set for each element of universe
    ds.makeSet(N);

    // MST contains exactly V-1 edges
    while (MST.size() != N - 1)
    {
        // consider next edge with minimum weight from the graph
        Edge next_edge = edges.back();
        edges.pop_back();

        // find root of the sets to which two endpoint
        // vertices of next_edge belongs
        int x = ds.Find(next_edge.src);
        int y = ds.Find(next_edge.dest);

        // if both endpoints have different parents, they belong to
        // different connected components and can be included in MST
        if (x != y)
        {
            MST.push_back(next_edge);
            ds.Union(x, y);
        }
    }
    return MST;
}

vector<Edge> KruskalAlgoMaxST(vector<Edge> edges, int N)
{
    sort(edges.begin(), edges.end(), compare2());
    // stores edges present in MST
    vector<Edge> MST;

    // initialize DisjointSet class
    DisjointSet ds;


    // create singleton set for each element of universe
    ds.makeSet(N);



    // MST contains exactly V-1 edges
    while (MST.size() != N - 1)
    {
        // consider next edge with minimum weight from the graph
        Edge next_edge = edges.back();
        edges.pop_back();

        // find root of the sets to which two endpoint
        // vertices of next_edge belongs
        int x = ds.Find(next_edge.src);
        int y = ds.Find(next_edge.dest);

        // if both endpoints have different parents, they belong to
        // different connected components and can be included in MST
        if (x != y)
        {
            MST.push_back(next_edge);
            ds.Union(x, y);
        }
    }
    return MST;
}

vector<Edge>adj;
int nodes;

int main()
{
    //freopen("LightOj1029.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        adj.clear();

        scanf("%d",&nodes);

        while(1)
        {
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);
            if(a==0 && b==0 && w==0)
                break;

            adj.push_back({a,b,w}); // although undirected edge is pushed once to avoid cycle of x->y & y->x
        }

        vector<Edge>MinST = KruskalAlgoMinST(adj,nodes+1);
        vector<Edge>MaxST = KruskalAlgoMaxST(adj,nodes+1);

        LL minn = 0,maxx=0;

        for(auto e:MinST)
            minn += e.weight;

        for(auto e:MaxST)
            maxx += e.weight;

        LL ans=minn+maxx;

        if(ans%2==0)
            printf("Case %d: %lld\n",i,ans/(LL)2);
        else
            printf("Case %d: %lld/2\n",i,ans);

    }

    return 0;
}
