
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

enum Color {WHITE, GRAY, BLACK};

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second
#define V 55
#define INF INT_MAX

int nodes;

vector<PII>adj[55];
map<string,int>M;

bool visited[55];

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

LL MinST()
{
    int power=0;

    priority_queue< PII,vector<PII>,greater <PII> >PQ;
    vector<bool> inMinST(V, false);
    vector<PII> parent(V, MP(-1,0));
    vector<int>mind(V,INF);

    mind[power]=0;
    PQ.push(MP(0,power));

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

    for(int i=1;i<nodes;i++)
        min_ans+=parent[i].S;


    return min_ans;
}


void init()
{
    for(int i=0;i<55;i++)
        adj[i].clear();

    fill(visited,visited+55,false);

    M.clear();
}

int main()
{
    //freopen("LightOj1003.txt","w",stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int tc;
    scanf("%d",&tc);

    for(int i=1;i<=tc;i++)
    {
        init();

        int edges;
        scanf("%d",&edges);

        nodes=0;

        for(int j=1;j<=edges;j++)
        {
            string a,b;
            cin>>a>>b;

            int w;
            scanf("%d",&w);

            if(M.count(a)){}
            else M[a]=nodes++;

            if(M.count(b)){}
            else M[b]=nodes++;

            int x=M[a];
            int y=M[b];

            adj[x].push_back(MP(y,w));
            adj[y].push_back(MP(x,w));
        }

        int comp=0;

        for(int j=0;j<nodes;j++)
        {
            if(visited[j]==false)
            {
                comp++;
                dfs(j);
            }
        }

        if(comp>1)
        {
            printf("Case %d: Impossible\n",i);
        }

        else
        {
            LL ans=MinST();
            printf("Case %d: %lld\n",i,ans);

        }
    }

    return 0;
}
