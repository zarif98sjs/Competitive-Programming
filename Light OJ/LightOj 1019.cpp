
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLI pair<LL,int>
#define LPII pair<LL, pair<int,int> >
#define MP make_pair
#define F first
#define S second
#define LINF LLONG_MAX

vector<PII>adj[100010];
bool visited[5010];

LL dist[5010];

void init()
{
    for(int i=0; i<100010; i++)
        adj[i].clear();

    //fill(visited,visited+5010,false);
    memset(visited,0,sizeof visited);

}

void dijkstra(int par)
{
    fill(dist,dist+5010,LINF);

    priority_queue< PLI,vector<PLI>,greater<PLI> >PQ;
    dist[par] = 0;
    PQ.push(MP(dist[par],par));

    while(!PQ.empty())
    {
        int now = PQ.top().S;
        LL temp_dist=PQ.top().F;

        //cout<<"temp  ------------->> "<<temp_dist<<endl;

        PQ.pop();

//        if(visited[now]==true)
//            continue;
//
//        visited[now]=true;

        if(temp_dist>dist[now])
            continue;

        for(auto x:adj[now])
        {
            int next = x.F;
            LL ed = (LL)x.S;

            if(temp_dist+ed<dist[next])
            {
                dist[next]=temp_dist+ed;
                PQ.push(MP(dist[next],next));
            }

        }
    }
}

int main()
{
    //freopen("LightOj1099.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        init();

        int nodes,edges;
        scanf("%d %d",&nodes,&edges);

        for(int j=1; j<=edges; j++)
        {
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);

            adj[a].push_back(MP(b,w));
            adj[b].push_back(MP(a,w));

        }

        dijkstra(1);

        if(dist[nodes]==LINF)
            printf("Case %d: Impossible\n",i);
        else
            printf("Case %d: %lld\n",i,dist[nodes]);

    }

    return 0;
}
