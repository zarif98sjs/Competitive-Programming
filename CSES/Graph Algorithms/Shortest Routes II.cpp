
/**
Complexity : O(V^3)
Note : Works with negative weight , but not with negative cycle
Can be used to detect negative cycles (the main diagonal i.e dis[i][i] will have at least one negative value
                                       which will indicate the presence of at least one negative cycle)
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

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing
*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e3+7;
const LL LINF = 1e17;

double eps = 1e-6;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

struct Edge
{
    int u,v;
    LL w;
};

int nVertices,m;

vector<Edge>adjList[nmax];
LL distanceMatrix[nmax][nmax];
int parentMatrix[nmax][nmax];

void floydWarshall()
{
    for(int u=0; u<nVertices; u++)
    {
        int len = adjList[u].size();

        for(int j=0; j<len; j++)
        {
            int v = adjList[u][j].v;
            distanceMatrix[u][v] = min(distanceMatrix[u][v],adjList[u][j].w);
            parentMatrix[u][v] = u;
        }
    }

    for(int i=0; i<nVertices; i++)
    {
        for (int j = 0; j <nVertices; j++)
        {
            if(i==j) distanceMatrix[i][j] = 0;
        }
    }

    for(int k=0; k<nVertices; k++)
    {
        for(int i=0; i<nVertices; i++)
        {
            for (int j = 0; j <nVertices; j++)
            {
                if (distanceMatrix[i][k]<LINF  && distanceMatrix[k][j]<LINF)
                {
                    if(distanceMatrix[i][k] + distanceMatrix[k][j] < distanceMatrix[i][j])
                    {
                        distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                        parentMatrix[i][j] = parentMatrix[k][j];
                    }
                }
            }
        }
    }
//    cout<<"Floyd Warshall Algorithm implemented"<<endl;
}

void init()
{
    for(int i=0; i<nVertices; i++)
    {
        for(int j=0; j<nVertices; j++)
        {
            distanceMatrix[i][j] = LINF;
            parentMatrix[i][j] = -1;
        }
    }
}


int main()
{
    //optimizeIO();

    int q;
    cin>>nVertices>>m>>q;

    for(int i=0; i<m; i++)
    {
        int a,b;
        double w;
        cin>>a>>b>>w;

        a--,b--; /** making 0 based **/

        adjList[a].push_back({a,b,w});  /** Directed **/
        adjList[b].push_back({b,a,w});  /** Directed **/
        //adj[b].push_back({a,w});
    }

    init();

    floydWarshall();

    while(q--)
    {

        int src,des;
        cin>>src>>des;
        src--,des--; /** making 0 based **/

        LL ans = distanceMatrix[src][des];

        cout<< (ans>=LINF ? -1 : ans) <<endl;

    }


    return 0;
}

