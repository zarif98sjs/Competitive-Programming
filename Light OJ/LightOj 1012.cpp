
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define SIZE 25
#define BOUNDARY(i,j) ((i >= 1 && i <= row) && (j >= 1 && j <= col))

int row,col,ans;
char graph[SIZE][SIZE];
bool visited[SIZE][SIZE];

int X[]={0,1,0,-1};
int Y[]={-1,0,1,0};

void dfs(int x , int y)
{
    for(int i=0;i<4;i++)
    {
        if( BOUNDARY(x+X[i] , y+Y[i]) && (!visited [x+X[i]][y+Y[i]]) && (graph [x+X[i]][y+Y[i]]=='.'))
        {
            visited [x+X[i]][y+Y[i]] = true;
            ans++;
            dfs(x+X[i] , y+Y[i]);
        }

    }

}

int main()
{
    int t,x,y,cnt=0;
    char ch;
    scanf("%d",&t);

    for(int k=1;k<=t;k++)
    {
        //int row,col;
        scanf("%d %d",&col,&row);
        memset(visited, 0, sizeof visited);

        //cout<<row<<" "<<col;

        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                //scanf("%c ",&ch);
                cin>>ch;
                graph[i][j]=ch;

                if(graph[i][j]=='@')
                {
                    x=i;
                    y=j;

                    visited[x][y]=true;
                }

            }
        }

        ans=1;

        //cout<<cnt<<endl;

        dfs(x,y);

        printf("Case %d: %d\n", k, ans);

    }
    return 0;

}
