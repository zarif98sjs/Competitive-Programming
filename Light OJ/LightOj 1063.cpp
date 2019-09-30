
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e4+10;

vector<int>adj[nmax];
vector<bool>visited;

vector<int> discov,low,dhongsho;
int timer,ans;

void initialize()
{
    timer = 0;
    ans=0;
    visited.assign(nmax,false);
    discov.assign(nmax,-1);
    low.assign(nmax,-1);
    dhongsho.assign(nmax,-1);

    for(int i=0;i<nmax;i++)
        adj[i].clear();
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
            {
                dhongsho[v]=1;
            }

            if(discov[v]<low[next] &&p!=-1)
            {
                //bridge
                dhongsho[v]=1;
//                if((int)adj[v].size()>1 && p!=-1)
//                {
//                    dhongsho[v]=1;
//                }
//                if((int)adj[next].size()>1 && dhongsho[next]!=1)
//                {
//                    dhongsho[next]=1;
//                    ans++;
//                }


            }
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
        initialize();

        int n,m,a,b;
        cin>>n>>m;

        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
                dfs(i,-1);
        }


        for(int i=1; i<=n; i++)
        {
            if(dhongsho[i]==1)
                ans++;
        }

        cout<<"Case "<<q<<": ";
        cout<<ans<<endl;

    }

    return 0;
}
