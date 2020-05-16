
/**

Topic : Bridge , Odd Cycle / Bi-colorable

hint 1:

Show that, without bridges you can find two paths from a to b if they are connected.

hint 2:

Show that, in any non-bicolorable graph there is a cycle of odd length.

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

vector<int>adj[nmax];
set<int>newGraph[nmax];

vector<bool>visited;
vector<int>color;
vector<int>cycleMap;
vector<int>dist;

vector<int> discov; /** Discovery time in DFS **/
vector<int> low; /** min(all discovery time of subtree of a vertex u including the back-edge ancestors) **/
vector<PII> articulationBridge;
int timer;
int cnt = 0;
bool oddCycle = false;

void initialize()
{
    timer = 0;
    visited.assign(nmax,false);
    color.assign(nmax,0);
    cycleMap.assign(nmax,-1);
    dist.assign(nmax,0);
    discov.assign(nmax,-1);
    low.assign(nmax,-1);
    articulationBridge.clear();

    for(int i=0; i<nmax; i++)
        adj[i].clear() , newGraph[i].clear();
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

            if(discov[v]<low[next])
            {
                articulationBridge.push_back({v,next});
//                cout<<v<<"---"<<next<<endl;
                newGraph[v].erase(next);
                newGraph[next].erase(v);
            }

        }
    }
}

void cycle_dfs(int u,int p,int len)
{
    cnt++;
    dist[u] = len;
    visited[u] = true;

    for(int next:newGraph[u])
    {
        if(!visited[next])
            cycle_dfs(next,u,len+1);
        else if (visited[next] && (dist[next]-dist[u])%2==0) /** check the length of the loop defined by each back-edge **/
            oddCycle = true;
    }
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1;q<=tc;q++)
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

            newGraph[a].insert(b);
            newGraph[b].insert(a);
        }

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                dfs(i,-1);
        }

        visited.assign(nmax,false);

        int ans = 0;

        for(int i=0; i<n; i++)
        {
            cnt = 0;
            oddCycle = false;
            if(!visited[i])
                cycle_dfs(i,-1,0);

            if(oddCycle)
                ans += cnt;
        }

        cout<<"Case "<<q<<": ";
        cout<<ans<<endl;
    }

    return 0;
}

/**
4

4 6
3 0
0 1
1 2
0 2
1 3
2 3

6 7
4 1
1 0
2 3
0 4
0 2
5 3
0 5

6 12
2 1
0 5
5 4
1 5
2 5
2 3
4 0
0 2
3 0
1 3
3 5
1 4

8 13
1 3
7 4
0 2
5 3
3 0
5 7
1 2
1 0
5 6
1 6
4 5
0 6
6 2
**/


