
/**

Idea : Create DAG from SCC and just check if every node is reachable form
the starting node (i.e node 0) by a single dfs

**/

/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

int scc_num;

vector<int>graph[100010];
vector<int>rev_graph[100010];
vector<int>new_graph[100010];

//vector<int>Map(1010,-1);
//vector<int>SCCMap(1010,0);

int Map[1010];
int SCCMap[1010];

stack<int>stk;

bool visited[1010];

bool flag=true;

void forward_dfs(int node)
{
    visited[node]=true;

    for(int next:graph[node])
    {
        if(visited[next]==false)
            forward_dfs(next);
    }

    stk.push(node);
}

void rev_dfs(int node)
{
    visited[node]=true;
    SCCMap[node]=scc_num;

    for(int next:rev_graph[node])
    {
        if(visited[next]==false)
            rev_dfs(next);
    }
}

void dfs_check(int node)
{
    if(new_graph[node].size()>1)
    {
        flag=false;
        return;
    }

    visited[node]=true;
    for(int next:new_graph[node])
    {
        if(visited[next]==false)
            dfs_check(next);
    }

}

void init()
{
    for(int i=0; i<1010; i++)
    {
        graph[i].clear();
        rev_graph[i].clear();
        new_graph[i].clear();
    }

    fill(visited,visited+1010,false);

//    Map.clear();
//    Map(1010,-1);
//    SCCMap.clear();

    memset(Map,-1,sizeof Map);

    while(!stk.empty())
        stk.pop();

}

int main()
{
    //freopen("LightOj1168.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        init();

        int n,serial=0;
        scanf("%d",&n);

        Map[0]=serial++;

        for(int j=1; j<=n; j++)
        {
            int wish;
            scanf("%d",&wish);

            for(int k=1; k<=wish; k++)
            {
                int a,b;
                scanf("%d %d",&a,&b);

                if(Map[a]==-1)
                    Map[a]=serial++;
                if(Map[b]==-1)
                    Map[b]=serial++;

                int u=Map[a];
                int v=Map[b];

                //cout<<u<<" --> "<<v<<endl;

                graph[u].push_back(v);
                rev_graph[v].push_back(u);

            }
        }

        //cout<<"Serial "<<serial<<endl;

        for(int k=0; k<serial; k++)
        {
            if(visited[k]==false)
                forward_dfs(k);
        }

        fill(visited,visited+1010,false);

        scc_num=0;

        while(!stk.empty())
        {
            int now=stk.top();
            stk.pop();

            if(visited[now]==false)
            {
                rev_dfs(now);
                scc_num++;
            }
        }

        ///building the new graph (DAG) keeping every sccs as a node

        for(int now=0; now<serial; now++)
        {
            for(int next:graph[now])
            {
                if(SCCMap[now]!=SCCMap[next])
                    new_graph[SCCMap[now]].push_back(SCCMap[next]);
            }
        }

        fill(visited,visited+1010,false);

        //cout<<"SCC  "<<scc_num<<endl;

        flag=true;

        dfs_check(SCCMap[0]); ///  Initially the snake is at checkpoint 0.

        if(flag)
        {
            for(int now=0; now<scc_num; now++)
            {
                if(visited[now]==false)
                {
                    flag=false;
                    break;
                }
            }
        }

        if(flag)
            printf("Case %d: YES\n",i);
        else
            printf("Case %d: NO\n",i);

    }

    return 0;
}
