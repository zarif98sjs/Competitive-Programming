
/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

int scc_num;

vector<int>graph[50010];
vector<int>rev_graph[50010];
vector<int>new_graph[50010];

int inDegree[20010];
int outDegree[20010];

//vector<int>Map(1010,-1);
//vector<int>SCCMap(1010,0);

int nodes,roads;
int SCCMap[20010];

stack<int>stk;

bool visited[20010];

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

//void in_out_count_dfs(int node)
//{
//    visited[node]=true;
//    for(int next:new_graph[node])
//    {
//        if(visited[next]==false)
//        {
//            inDegree[next]++;
//            outDegree[node]++;
//            in_out_count_dfs(next);
//        }
//    }
//}

void in_out_count_dfs2()
{
    for(int now=1;now<=nodes;now++)
    {
        for(int next:new_graph[now])
        {
            inDegree[next]++;
            outDegree[now]++;
        }
    }

}

void init()
{
    for(int i=0; i<50010; i++)
    {
        graph[i].clear();
        rev_graph[i].clear();
        new_graph[i].clear();
    }

    fill(visited,visited+20010,false);

//    Map.clear();
//    Map(1010,-1);
//    SCCMap.clear();

    memset(inDegree,0,sizeof inDegree);
    memset(outDegree,0,sizeof outDegree);

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

        scanf("%d %d",&nodes,&roads);

        for(int k=1; k<=roads; k++)
        {
            int a,b;
            scanf("%d %d",&a,&b);

            graph[a].push_back(b);
            rev_graph[b].push_back(a);

        }

        //cout<<"Serial "<<serial<<endl;

        for(int k=1; k<=nodes; k++)
        {
            if(visited[k]==false)
                forward_dfs(k);
        }

        fill(visited,visited+20010,false);

        scc_num=0;

        while(!stk.empty())
        {
            int now=stk.top();
            stk.pop();

            if(visited[now]==false)
            {
                scc_num++;
                rev_dfs(now);
            }
        }

        //building the new DAG keeping every sccs as a node

        for(int now=1; now<=nodes; now++)
        {
            for(int next:graph[now])
            {
                if(SCCMap[now]!=SCCMap[next])
                    new_graph[SCCMap[now]].push_back(SCCMap[next]);
            }
        }

        fill(visited,visited+20010,false);

        //cout<<"SCC  "<<scc_num<<endl;

//        for(int now=1; now<=scc_num; now++)
//        {
//            if(visited[now]==false)
//                in_out_count_dfs(now);
//        }

        in_out_count_dfs2();

        int in_lagbe=0,out_lagbe=0;

        for(int now=1; now<=scc_num && scc_num>1 ; now++)
        {
            //cout<<"now  "<<now<<"   "<<inDegree[now]<<"     "<<outDegree[now]<<endl;

            if(inDegree[now]==0)
                in_lagbe++;
            if(outDegree[now]==0)
                out_lagbe++;
        }

        //cout<<in_lagbe<<"   "<<out_lagbe<<endl;

        printf("Case %d: %d\n",i,max(in_lagbe,out_lagbe));

    }

    return 0;
}
