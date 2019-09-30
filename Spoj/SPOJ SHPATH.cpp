#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int>

#define SIZE 10005

vector<PII>adj[SIZE];
int dist[SIZE];

void initialize()
{
    for(int i=0;i<SIZE;i++)
        adj[i].clear();

}

void dijkstra(int par) //parent
{
    fill(dist,dist+SIZE,INT_MAX);
    priority_queue< PII,vector<PII>,greater<PII> > PQ;

    dist[par]=0;
    PQ.push(make_pair(dist[par],par));

    while(!PQ.empty())
    {
        int now = PQ.top().second; //not front
        PQ.pop();

        for(int i=0;i<adj[now].size();i++)
        {
            int next = adj[now][i].first;
            int ed = adj[now][i].second;

            if(dist[now]+ed<dist[next])
            {
                dist[next] = dist[now]+ed;
                PQ.push(make_pair(dist[next],next));
            }
        }
    }
}

int main()
{
    map<string,int> city;

    int tc;
    scanf("%d",&tc);

    for(int i=1;i<=tc;i++)
    {
        initialize();

        int num;
        scanf("%d",&num);

        for(int j=1;j<=num;j++)
        {
            string name;
            cin>>name;
            city.insert(make_pair(name,j));

            int neighbour;
            scanf("%d",&neighbour);

            for(int z=1;z<=neighbour;z++)
            {
                int nc,cost;
                scanf("%d %d",&nc,&cost);

                adj[j].push_back(make_pair(nc,cost));
                adj[nc].push_back(make_pair(j,cost));

            }
        }

        int query;
        scanf("%d",&query);

        for(int q=1;q<=query;q++)
        {
            string source,destination;
            cin>>source>>destination;

            dijkstra(city[source]);

            cout<<dist[city[destination]]<<endl;
        }
    }

    return 0;
}
