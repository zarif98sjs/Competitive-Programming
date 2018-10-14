
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 20010

vector<int>adj[MAX];
int visited[MAX];
int color[MAX];

void init()
{
    for(int i=0;i<MAX;i++)
        adj[i].clear();

    fill(visited,visited+MAX,0);
    fill(color,color+MAX,3);
}

int p1,p2;

void dfs(int now,int col)
{
    visited[now]=2;
    color[now]=col;

    if(col==0)
        p1++;
    else
        p2++;

    for(int i=0;i<adj[now].size();i++)
    {
        int next=adj[now][i];

        if(visited[next]==1)
        {
            dfs(next,(col+1)%2);
        }
    }


}

int main()
{
    //freopen("LOJ1009.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        init();

        int edge;
        scanf("%d",&edge);

        int a,b;

        for(int i=1;i<=edge;i++)
        {
            scanf("%d %d",&a,&b);
            visited[a]=1;
            visited[b]=1;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int ans=0;

        for(int i=1;i<=MAX;i++)
        {
            if(visited[i]==1)
            {
                p1=0;
                p2=0;
                dfs(i,0);

                ans+=max(p1,p2);

            }
        }

        printf("Case %d: %d\n",q,ans);
    }

    return 0;
}

