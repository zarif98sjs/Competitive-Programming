
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL  long long
#define PII pair<int,int>
#define PIL pair<int,LL>

#define MP  make_pair

vector<PII>adj[30010];
bool visited[30010];
LL dist[30010];

void init()
{
    for(int i=0; i<=30005; i++)
        adj[i].clear();
}


PIL bfs(int node,int node_num)
{
    fill(visited,visited+30010,0);
    //fill(dist,dist+30010,0);

    dist[node]=0;
    queue<int>Q;
    Q.push(node);

    while(!Q.empty())
    {
        int now = Q.front();
        visited[now]=true;
        Q.pop();

        for(int i=0; i<adj[now].size(); i++)
        {
            int next = adj[now][i].first;
            if(visited[next])
                continue;
            int ed = adj[now][i].second;

            visited[next]=true;
            dist[next]=dist[now]+ed;

            Q.push(next);
        }
    }

    LL max_dist=-1;
    int max_dist_node=-1;

    for(int i=0; i<node_num; i++)
    {
        //cout<<dist[i]<<endl;

        if(dist[i]>max_dist)
        {
            max_dist=dist[i];
            max_dist_node=i;
        }
    }

    return MP(max_dist_node,max_dist);

}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        init();

        int node_num,a,b,w;
        scanf("%d",&node_num);

        for(int i=1; i<=node_num-1; i++)
        {
            scanf("%d %d %d",&a,&b,&w);
            adj[a].push_back(MP(b,w));
            adj[b].push_back(MP(a,w));
        }

        PIL step1,step2;

        step1=bfs(0,node_num);
        step2=bfs(step1.first,node_num);

        //cout<<step2.first<<" "<<step2.second<<endl;

        printf("Case %d: %lld\n",q,step2.second);

    }

    return 0;
}

