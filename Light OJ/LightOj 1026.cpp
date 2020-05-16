
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


inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e4+10;

vector<int>adj[nmax];
vector<bool>visited;

vector<int> discov,low;
vector<PII>articulationBridge;
int timer;

void initialize()
{
    timer = 0;
    visited.assign(nmax,false);
    discov.assign(nmax,-1);
    low.assign(nmax,-1);
    articulationBridge.clear();

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

            if(discov[v]<low[next])
            {
                ///bridge
                int minn = min(v,next) , maxx = max(v,next);
                articulationBridge.push_back({minn,maxx});
            }
        }
    }
}

bool cmp(const PII &A,const PII &B)
{
    if(A.F==B.F)
        return A.S<B.S;
    return A.F<B.F;
}


int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        initialize();

        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            int u,cnt;
            scanf("%d (%d)",&u,&cnt);

            for(int j=0;j<cnt;j++)
            {
                int v;
                scanf("%d",&v);
                adj[u].push_back(v);
            }

        }

        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
                dfs(i,-1);
        }

        cout<<"Case "<<q<<":"<<endl;

        sort(ALL(articulationBridge),cmp);

        int sz = articulationBridge.size();

        cout<<sz<<" "<<"critical links"<<endl;

        for(auto x:articulationBridge)
            cout<<x.F<<" - "<<x.S<<endl;

    }

    return 0;
}
