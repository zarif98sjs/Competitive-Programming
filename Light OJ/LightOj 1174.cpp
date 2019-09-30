
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL  long long
#define PII pair<int,int>
#define PIL pair<int,LL>

#define MP  make_pair
#define F first
#define S second
#define LINF LLONG_MAX
#define INF INT_MAX

vector<PII>adj[30010];
bool visited[110];
int dist[110];
int dist2[110];

void init()
{
    for(int i=0; i<30010; i++)
        adj[i].clear();
}

void dijkstra(int node,int node_num)
{
    fill(visited,visited+110,0);
    fill(dist,dist+110,INF);

    dist[node]=0;
    priority_queue< PII,vector<PII>,greater<PII> >PQ;
    PQ.push(MP(dist[node],node));

    while(!PQ.empty())
    {
        int now = PQ.top().S;
        int temp_dist=PQ.top().F;

        PQ.pop();

        if(visited[now])
            continue;
        visited[now]=true;

        for(auto x:adj[now])
        {
            int next = x.F;
            int ed = x.S;

            if(temp_dist+ed<dist[next])
            {
                dist[next]=temp_dist+ed;
                PQ.push(MP(dist[next],next));
            }
        }
    }

}

void dijkstra2(int node,int node_num)
{
    fill(visited,visited+110,0);
    fill(dist2,dist2+110,INF);

    dist2[node]=0;
    priority_queue< PII,vector<PII>,greater<PII> >PQ;
    PQ.push(MP(dist2[node],node));

    while(!PQ.empty())
    {
        int now = PQ.top().S;
        int temp_dist=PQ.top().F;

        PQ.pop();

        if(visited[now])
            continue;
        visited[now]=true;

        for(auto x:adj[now])
        {
            int next = x.F;
            int ed = x.S;

            if(temp_dist+ed<dist2[next])
            {
                dist2[next]=temp_dist+ed;
                PQ.push(MP(dist2[next],next));
            }
        }
    }
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        init();

        int nodes,edges,a,b,w=1;
        scanf("%d %d",&nodes,&edges);

        for(int i=1; i<=edges; i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].push_back(MP(b,w));
            adj[b].push_back(MP(a,w));
        }

        int start,target;
        scanf("%d %d",&start,&target);

//        PII step1;
//        int val1,val2;
//
//        step1=dijkstra(start,nodes);
//        val1=step1.S;
//        //cout<<"step1.first -->> "<<step1.F<<" step1.second  --> "<<step1.S<<endl;
//        val2=dijkstra2(step1.F,nodes,target);

        dijkstra(start,nodes);
        dijkstra2(target,nodes);

        int ans=0;

        for(int i=0;i<nodes;i++)
            ans=max(ans,dist[i]+dist2[i]);

        printf("Case %d: %d\n",q,ans);

    }

    return 0;
}
