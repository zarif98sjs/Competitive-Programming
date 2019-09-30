
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

const int nmax = 1e4+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

vector<int>adj[nmax];
vector<PII>lok;
bool visited[nmax][105];
int city[nmax];

void init()
{
    for(int i=0; i<nmax; i++)
    {
        adj[i].clear();
        city[i] = 0;
    }

    lok.clear();

    for(int i=0; i<nmax; i++)
        for(int j=0;j<=102;j++)
            visited[i][j] = false;

}

void dfs(int u,int id)
{
    visited[u][id] = true;
    city[u]++;

    for(int v:adj[u])
    {
        if(!visited[v][id])
        {
            //city[v]++;
            dfs(v,id);
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

        int k ,n , m;
        cin>>k>>n>>m;

        for(int i=1;i<=k;i++)
        {
            int x;
            cin>>x;
            lok.push_back({x,i});
        }

        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;

            adj[a].push_back(b);
        }

        for(auto x:lok)
        {
            int u = x.F;
            int id = x.S;
            dfs(u,id);
        }

        int ans = 0;

        for(int i=1;i<=n;i++)
        {
            //cout<<"  -> "<<city[i]<<endl;
            ans += (city[i]==k);
        }

        cout<<"Case "<<q<<": "<<ans<<endl;
    }

    return 0;
}
