
/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define pi       acos(-1)

#define SI(n)    scanf("%d",&n)
#define SLL(n)   scanf("%lld",&n)
#define SULL(n)   scanf("%llu",&n)
#define SC(n)    scanf("%c",&n)
#define SD(n)    scanf("%lf",&n)

#define fr(i,a,b) for(int i=a ,_b=(b) ;i<= _b;i++)

#define LL      long long
#define PUB     push_back
#define POB     pop_back
#define MP      make_pair
#define PII     pair<int,int>
#define PLL     pair<ll,ll>

#define GCD     __gcd
#define DEBUG   cout<<"aw"<<endl;

#define MAX 510
#define LINF LLONG_MAX

int n,m;
vector<PII>adj[MAX];
LL dist[MAX];
LL min_cost[MAX];

void init()
{
    fr(i,0,MAX)
    {
        adj[i].clear();
        min_cost[i] = LINF;

    }

}

void dijkstra(int par)
{
    fill(dist,dist+MAX,LINF);

    dist[par] = 0;

    priority_queue< PII,vector<PII>,greater<PII> >PQ;
    PQ.push(MP(dist[par],par));

    while(!PQ.empty())
    {
        int now = PQ.top().second;
        int nd = PQ.top().first;
        PQ.pop();

        //cout<<"!!"<<now<<" "<<dist[now]<<" "<<nd<<endl;

        if(dist[now]<nd)
            continue;

        for(int i=0;i<adj[now].size();i++)
        {
            int next = adj[now][i].first;
            int ed = adj[now][i].second;

            //cout<<"**"<<now<<" "<<next<<" "<<dist[now]+ed<<endl;
            //LL temp = min((LL)ed,dist[now]);
            //min_cost[next] = min(min_cost[next],(LL)ed);

            if(dist[next]>max(nd,ed))
            {
                //cout<<"##"<<next<<" "<<endl;
                dist[next] = max(nd,ed);
                PQ.push(MP(dist[next],next));
            }
        }
    }
}

int main()
{
    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        init();
        SI(n),SI(m);

        int a,b,weight;

        fr(j,1,m)
        {
            SI(a),SI(b),SI(weight);
            adj[a].PUB(MP(b,weight));
            adj[b].PUB(MP(a,weight));
        }

        int home;
        SI(home);

        dijkstra(home);

        printf("Case %d:\n",i);

        fr(q,0,n-1)
        {
            if(dist[q]==LINF)
                printf("Impossible\n");
            else
                printf("%lld\n",dist[q]);
        }

    }

    return 0;
}
