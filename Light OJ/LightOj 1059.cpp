
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX
#define V 10010

int nodes;

vector<PII>adj[100010];
bool visited[V];

LL MinST(int start)
{
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

//    for(int i=2;i<=nodes;i++)
//        min_ans+=parent[i].S;

    for(int i=1;i<=nodes;i++)
    {
        if(inMinST[i])
            min_ans+=parent[i].S;
    }


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
    for(int i=0; i<100010; i++)
        adj[i].clear();

    fill(visited,visited+V,false);

}

int main()
{
    //freopen("LightOj1059.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        init();

        int roads,airport_cost;
        scanf("%d %d %d",&nodes,&roads,&airport_cost);

        for(int i=1;i<=roads;i++)
        {
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);

            if(w>=airport_cost)
                continue;

            adj[a].push_back(MP(b,w));
            adj[b].push_back(MP(a,w));
        }

        LL comp=0;

        LL ans=0;

        for(int j=1;j<=nodes;j++)
        {
            if(visited[j]==false)
            {
                comp++;
                dfs(j);
                ans+=MinST(j);
            }
        }

        ans+=comp*(LL)airport_cost;

        printf("Case %d: %lld %lld\n",i,ans,comp);

    }

    return 0;
}
