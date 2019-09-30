
/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF 1e9

#define BOUNDARY(a,b) ((a>=0 && a<row) && (b>=0 && b<col))

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

const int nmax = 2e2+7;
const LL LINF = 1e17;

int row,col;
PII jane;
vector<PII>fire;

string graph[nmax];
int dist[nmax][nmax][2];
//bool visited[nmax][nmax][2];

int X[]= {0,1,0,-1};
int Y[]= {-1,0,1,0};

void bfs(int x,int y,int id)
{
    //cout<<x<<" , "<<y<<endl;

    dist[x][y][id]=0;
    //visited[x][y][id]=true;

    int prevx,prevy;

    queue< PII > Q;
    Q.push(MP(x,y));

    while(!Q.empty())
    {
        prevx = Q.front().F;
        prevy = Q.front().S;

        Q.pop();

        for(int i=0; i<4; i++)
        {
            x = prevx + X[i];
            y = prevy + Y[i];

            if( BOUNDARY(x,y) && dist[prevx][prevy][id]+1<dist[x][y][id] && graph[x][y]!='#')
            {
                dist[x][y][id] = min(dist[prevx][prevy][id]+1,dist[x][y][id]);
                //visited[x][y][id] = true;
                //cout<<dist[x][y][id]<<endl;
                Q.push(MP(x,y));
            }
        }
    }
}

void init()
{
    for(int i=0; i<row; i++) // ditance inf
    {
        for(int j=0; j<col; j++)
        {
            dist[i][j][0]=INF;
            dist[i][j][1]=INF;
            //visited[i][j][0]=false;
            //visited[i][j][1]=false;
        }
    }

    fire.clear();
}


int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {

        cin>>row>>col;

        for(int i=0;i<row;i++)
            cin>>graph[i];

        init();

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(graph[i][j]=='J')
                    jane = {i,j};
                if(graph[i][j]=='F')
                    fire.push_back({i,j});
            }
        }

        bfs(jane.F,jane.S,0);

        for(auto fi:fire)
            bfs(fi.F,fi.S,1);

        bool parbe = false;
        int minn = INT_MAX;

//        for(int i=0;i<row;i++)
//        {
//            for(int j=0;j<col;j++)
//            {
//                cout<<dist[i][j][0]<<"\t";
//            }
//
//            cout<<endl;
//        }
//
//        for(int i=0;i<row;i++)
//        {
//            for(int j=0;j<col;j++)
//            {
//                cout<<dist[i][j][1]<<"\t";
//            }
//
//            cout<<endl;
//        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 || i==row-1)
                {
                    if(dist[i][j][0]<dist[i][j][1])
                    {
                        parbe = true;
                        minn = min(minn,dist[i][j][0]);
                        //break;
                    }
                }
                else if(j==0 || j==col-1)
                {
                    if(dist[i][j][0]<dist[i][j][1])
                    {
                        parbe = true;
                        minn = min(minn,dist[i][j][0]);
                       // break;
                    }
                }
            }
        }

        if(parbe)
            cout<<"Case "<<q<<": "<<minn+1<<endl;
        else
            cout<<"Case "<<q<<": "<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
