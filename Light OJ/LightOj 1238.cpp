#include<bits/stdc++.h>
using namespace std;

#define SIZE 25
#define INF  INT_MAX

#define BOUNDARY(a,b) ((a>=1 && a<=row) && (b>=1 && b<=col))

int row,col;
char grid[SIZE][SIZE];
int dist[SIZE][SIZE]; //distance from source node (house)
bool visited[SIZE][SIZE];

int X[]= {0,1,0,-1};
int Y[]= {-1,0,1,0};

void bfs(int x,int y)
{
    for(int i=1; i<=row; i++) // ditance inf
    {
        for(int j=1; j<=col; j++)
        {
            dist[i][j]=INF;
            visited[i][j]=false;
        }
    }

    // also memset(visited , 0 , sizeof visited);

    dist[x][y]=0;
    visited[x][y]=true;

    int prevx,prevy;

    queue< pair<int,int> > Q;
    Q.push(make_pair(x,y));

    while(!Q.empty())
    {
        prevx = Q.front().first;
        prevy = Q.front().second;

        Q.pop();

        for(int i=0; i<4; i++)
        {
            x = prevx + X[i];
            y = prevy + Y[i];

            if( BOUNDARY(x,y) && visited[x][y]!=true && grid[x][y]!='#' && grid[x][y]!='m')
            {
                dist[x][y] = min(dist[prevx][prevy]+1,dist[x][y]);
                visited[x][y] = true;
                Q.push(make_pair(x,y));

            }
        }
    }
}


int main()
{
    int t,ax,ay,bx,by,cx,cy,hx,hy;
    char ch;
    cin>>t;

    for(int k=1; k<=t; k++)
    {
        cin>>row>>col;

        for(int i=1; i<=row; i++)
        {
            for(int j=1; j<=col; j++)
            {
                cin>>ch;
                grid[i][j]=ch;

                if(ch=='a')
                    ax=i, ay=j;
                else if(ch=='b')
                    bx=i, by=j;
                else if(ch=='c')
                    cx=i, cy=j;
                else if(ch=='h')
                    hx=i, hy=j;

            }

        }

        bfs(hx,hy);

        int finalans = max(max(dist[ax][ay],dist[bx][by]),dist[cx][cy]);

        printf("Case %d: %d\n",k,finalans );

    }

    return 0;
}
