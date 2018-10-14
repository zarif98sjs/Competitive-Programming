
/* Which of the favors of your Lord do you deny ? */

#include<bits/stdc++.h>
using namespace std;

int nodeMoney[1010];
vector <int> adj[1010];
bool visited[1010];
vector <int> comp[1010]; //components
double Avg[1010];

int node,edge,conComp,willdo,sum;

void intialize()
{
    for(int i=1;i<=node;i++)
        visited[i]=false;

    for(int i=1;i<=1000;i++)
    {
        comp[i].clear();
    }
    //comp.clear();
}

void dfs(int node)
{
    visited[node]=true;
    comp[conComp].push_back(node) ;//connected Components are taken in one row

    for(int j=0;j<adj[node].size();j++)
    {
        if(visited[ adj[node][j] ]==false)
        {
            dfs(adj[node][j]);
        }
    }
}

int main()
{
    //freopen("outty.txt","w",stdout);

    int t,cnt;
    double tt;
    scanf("%d",&t);

    for(int q=1;q<=t;q++)
    {
        sum=0,conComp=1,cnt=0;

        scanf("%d %d",&node,&edge);

        for(int j=1;j<=node;j++)
        {
            scanf("%d",&nodeMoney[j]);
        }

        //adjacency list needs to be cleared
        //adj.clear()

        for(int i=1;i<=1001;i++)
        {
            adj[i].clear();
        }

        for(int j=1;j<=edge;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        intialize();

        for(int j=1;j<=node;j++)
        {
            if(visited[j]==false)
                {
                    //conComp=0;
                    dfs(j);
                    conComp++;
                }
        }

        for(int k=1;k<=conComp-1;k++)
        {
            sum = 0;

            int g = comp[k].size();

            for(int l=0;l<g;l++)
                sum = sum + nodeMoney[comp[k][l]];


            tt = sum*(1.0)/g;

            //cout<<"****"<<tt<<endl;

            if ((int)tt == tt)
                Avg[k]=tt;
            else
                Avg[k]=-1;
        }

        //cout<<"*###*"<<tt<<endl;

        for(int k=1;k<=conComp-1;k++)
        {
            if(Avg[k]==Avg[k+1])
                cnt++;
        }

        if(cnt==0 && conComp-1==1 &&(int)tt==tt)
        {
            //cout<<"***********"<<tt<<endl;
             printf("Case %d: Yes\n",q);

        }

        else if(cnt!=0 && (cnt+1)==(conComp-1))
        {
            //cout<<"**"<<cnt+1<<"  "<<conComp-1<<endl;
            printf("Case %d: Yes\n",q);
        }

        else
        {
            //cout<<"**"<<cnt+1<<"  "<<conComp-1<<endl;
            printf("Case %d: No\n",q);

        }
    }

    return 0;
}
