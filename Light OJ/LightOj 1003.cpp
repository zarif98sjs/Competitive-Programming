
/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

enum Color {WHITE, GRAY, BLACK};

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

vector<int>adj[10010];
map<string,int>M;

//bool visited[10010];
int color[10010];

bool checkCycle(int node)
{
    color[node]=GRAY;

    for(int next:adj[node])
    {
        if(color[next]==GRAY)
            return true;
        else if(color[next]==WHITE && checkCycle(next))
            return true;
    }

    color[node]=BLACK;

    return false;
}

void init()
{
    for(int i=0;i<10010;i++)
        adj[i].clear();

    M.clear();
}

int main()
{
    //freopen("LightOj1003.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int i=1;i<=tc;i++)
    {
        init();

        int edges;
        scanf("%d",&edges);

        int cnt=0;

        for(int j=1;j<=edges;j++)
        {
            string a,b;
            cin>>a>>b;

            if(M.count(a)){}
            else M[a]=cnt , cnt++;

            if(M.count(b)){}
            else M[b]=cnt , cnt++;

            int x=M[a];
            int y=M[b];

            adj[x].push_back(y);
        }

        bool cycle_ase_ki=false;

        for(int j=0;j<cnt;j++)
            color[j]=WHITE;

        for(int j=0;j<cnt;j++)
        {
            if(color[j]==WHITE)
            {
                if(checkCycle(j))
                    cycle_ase_ki=true;
            }

        }

        if(cycle_ase_ki)
            printf("Case %d: No\n",i);
        else
            printf("Case %d: Yes\n",i);


    }

    return 0;
}
