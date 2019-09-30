
/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e3+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

vector<PII>adj[nmax];

void init()
{
    for(int i=0; i<nmax; i++)
        adj[i].clear();

}

void dfs(int u,int par,int &cost)
{
    if(u==1)
        return;

    for(PII x:adj[u])
    {
        int v = x.F;
        int w = x.S;

        if(v!=par)
        {
            cost += w;
            dfs(v,u,cost);
        }
    }
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        init();

        int n;
        cin>>n;

        int total = 0;

        for(int i=1; i<=n; i++)
        {
            int a,b,w;
            cin>>a>>b>>w;

            total += w;

            adj[a].push_back({b,0});
            adj[b].push_back({a,w});
        }

        /// DFS FROM 2 adjacent vertices , clockwise and anticlockwise

        int ans1 = adj[1][0].S;
        dfs(adj[1][0].F,1,ans1);

        int ans2 = adj[1][1].S;
        dfs(adj[1][1].F,1,ans2);

        //cout<<ans1<<"  --  "<<ans2<<endl;
        cout<<"Case "<<q<<": "<<min(ans1,ans2)<<endl;

    }

    return 0;
}
