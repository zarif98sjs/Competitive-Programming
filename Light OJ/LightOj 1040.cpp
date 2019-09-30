
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX
#define V 55

int nodes;

vector<PII>adj[55];
int graph[V][V];
bool visited[55];

LL MinST()
{
    int start=1;

    priority_queue< PII,vector<PII>,greater <PII> >PQ;
    vector<bool> inMinST(V, false);
    vector<PII> parent(V, MP(-1,0));
    vector<int>mind(V,INF);

    mind[start]=0;
    PQ.push(MP(0,start));

    while(!PQ.empty())
    {
        int now=PQ.top().S;
        PQ.pop();

        inMinST[now]=true;

        for(auto x:adj[now])
        {
            int next=x.F;
            int weight=x.S;

            if(inMinST[next]==false && weight<mind[next])
            {
                mind[next]=weight;
                PQ.push(MP(mind[next],next));
                parent[next]=MP(now,mind[next]);
            }
        }
    }

    LL min_ans=0;

    for(int i=2; i<=nodes; i++)
        min_ans+=parent[i].S;


    return min_ans;
}



void dfs(int node)
{
    visited[node]=true;

    for(auto x:adj[node])
    {
        int next=x.F;

        if(visited[next]==false)
            dfs(next);
    }
}



void init()
{
    for(int i=0; i<55; i++)
        adj[i].clear();

    fill(visited,visited+55,false);

}

int main()
{
    //freopen("LightOj1041.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        init();

        scanf("%d",&nodes);

        int total=0;


        for(int i=1; i<=nodes; i++)
        {
            for(int j=1; j<=nodes; j++)
            {
                scanf("%d",&graph[i][j]);

                total+=graph[i][j];

                if(i!=j && graph[i][j]>0)
                {
                    adj[i].push_back(MP(j,graph[i][j]));
                    adj[j].push_back(MP(i,graph[i][j]));
                }
            }
        }

        int comp=0;

        for(int j=1; j<=nodes; j++)
        {
            if(visited[j]==false)
            {
                comp++;
                dfs(j);
            }
        }

        if(comp>1)
            printf("Case %d: -1\n",i);
        else
        {
            LL ans=total-MinST();

            printf("Case %d: %lld\n",i,ans);

        }
    }

    return 0;
}
