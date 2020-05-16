/**

LightOj 1308
============

Firstly there are 2 case :

1 ) No Articulation point . Then there must be at least 2 shaft such that if one fails , other works

2 ) Articulation point is present in the graph.
No articulation point can have shaft in order to minimize the number of shafts.
So , delete the articulation points and make a new Graph without them.
Create a compressed SCC graph from that.
If a SCC is connected to multiple Articulation Point , then it can use other shaft connected through one other articulation point .
So , we only need to consider SCC's which are connected to less than 2 Articulation point.
For the number of ways , one can put the shaft in any of the nodes in a SCC . So , the number of way is basically the multiplication of the sizes of all valid SCCs.

Rest of the implementation is trivial.

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

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

const int nmax = 1e4+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

vector<PII>edges;

vector<int>adj[nmax];
vector<int>newGraph[nmax];
vector<bool>visited;
vector<int>SCCMap;

vector<int> discov; /** Discovery time in DFS **/
vector<int> low; /** min(all discovery time of subtree of a vertex u including the back-edge ancestors) **/
vector<bool> isArticulationPoint;
int timer;
int scc = 0;
int numArticulationPoint = 0;

void initialize()
{
    timer = 0;
    visited.assign(nmax,false);
    SCCMap.assign(nmax,-1);
    discov.assign(nmax,-1);
    low.assign(nmax,-1);
    isArticulationPoint.assign(nmax,false);
    edges.clear();

    for(int i=0; i<nmax; i++)
        adj[i].clear(), newGraph[i].clear();
}

void dfs(int v,int p)
{
    visited[v] = true;
    discov[v] = low[v] = timer++;
    int child = 0;

    for(int next:adj[v])
    {
        child++;

        if(next==p)
            continue;
        if(visited[next])
            low[v] = min(low[v],discov[next]);
        else
        {
            dfs(next,v);
            low[v] = min(low[v],low[next]);

            if(child>1 && p==-1)
                isArticulationPoint[v] = true, numArticulationPoint++;  /** ROOT **/

            if(discov[v]<=low[next] && p!=-1)
                isArticulationPoint[v] = true, numArticulationPoint++;
        }
    }
}

void scc_dfs(int u)
{
    visited[u] = true;
    SCCMap[u] = scc;

    for(int next:newGraph[u])
    {
        if(!visited[next])
            scc_dfs(next);
    }
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        initialize();

        int n,m;
        cin>>n>>m;

        for(int i=1; i<=m; i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);

            edges.push_back({a,b});
        }

        numArticulationPoint = 0;

        for(int i=0; i<n; i++)
            if(!visited[i])
                dfs(i,-1);

        //DBG(numArticulationPoint);

        if(numArticulationPoint==0)
        {
            cout<<"Case "<<q<<": ";
            LL ans = 2;
            LL way = (n*(n-1))/2;

            cout<<ans<<" "<<way<<endl;
            continue;
        }

        for(auto e:edges)
        {
            if(isArticulationPoint[e.F] || isArticulationPoint[e.S])
                continue;
            newGraph[e.F].push_back(e.S);
            newGraph[e.S].push_back(e.F);
        }

        visited.assign(nmax,false);

        scc = 0;
        for(int i=0; i<n; i++)
        {
            if(isArticulationPoint[i])
                continue;

            if(!visited[i])
            {
                scc_dfs(i);
                scc++;
            }
        }

        //DBG(scc);

        vector<int>cntInSCC(scc,0);

        for(int i=0; i<n; i++)
            if(SCCMap[i]!=-1) cntInSCC[SCCMap[i]]++;

        set<int> numArticulationPointInComp[scc];

        for(auto e:edges)
        {
            if(isArticulationPoint[e.F] && isArticulationPoint[e.S])
                continue;
            if(SCCMap[e.F]==SCCMap[e.S])
                continue;

            int ap = -1, op = -1;

            if(isArticulationPoint[e.F])
                ap = e.F, op = e.S;
            if(isArticulationPoint[e.S])
                ap = e.S, op = e.F;

            numArticulationPointInComp[SCCMap[op]].insert(ap);
        }

        LL ans = 0;
        unsigned LL way = 1;

        for(int i=0;i<scc;i++)
        {
            if(numArticulationPointInComp[i].size()<=1)
                ans++ , way *= cntInSCC[i];
        }

        cout<<"Case "<<q<<": ";
        cout<<ans<<" "<<way<<endl;
    }


    return 0;
}
