
/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e6+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

#define SIZE 25
#define INF  INT_MAX

#define BOUNDARY(a,b) ((a>=0 && a<row) && (b>=0 && b<col))

int row,col;
string grid[SIZE];

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

struct Rider
{
    int x,y,k;

    Rider() {}
    Rider(int a, int b, int c) : x(a), y(b), k(c) {}
};

vector<vector<int>> dist(SIZE, vector<int>(SIZE, 0));
vector<vector<int>> riders(SIZE, vector<int>(SIZE, 0));

void bfs(Rider rid)
{
    vector<vector<bool> > vis(SIZE, vector<bool>(SIZE, false));

    int k = rid.k;

    queue<Rider> q;
    q.push(Rider(rid.x,rid.y,0));

    while (!q.empty())
    {
        Rider cur = q.front();
        q.pop();

        //cout<<cur.x<<" "<<cur.y<<" "<<cur.k<<endl;

        if (vis[cur.x][cur.y])
            continue;

        vis[cur.x][cur.y] = true;

        int mv = (cur.k + k - 1) / k; /// CEIL (cur.k/k)  , this much min move will be needed
        dist[cur.x][cur.y] += mv;
        riders[cur.x][cur.y]++;

        for (int i = 0; i < 8; ++i)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(!BOUNDARY(nx,ny))
                continue;

            if (!vis[nx][ny])
                q.push(Rider(nx, ny, cur.k + 1));
        }
    }
}

void init()
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            /// WILL GET WA if clear is used
            dist[i][j] = 0;
            riders[i][j] = 0;
        }
    }
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        init();

        cin>>row>>col;

        string s;

        for(int i=0; i<row; i++)
        {
            cin>>s;
            grid[i] = s;
        }

        int total = 0;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]!='.')
                {
                    total++;
                    Rider temp = Rider(i,j,grid[i][j]-'0');
                    bfs(temp);
                    //cout<<"asdasdas"<<endl;
                }
            }
        }

        int best = INT_MAX;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (riders[i][j] == total && dist[i][j] < best)
                    best = dist[i][j];
            }
        }

        if (best != INT_MAX)
            cout<<"Case "<<q<<": "<<best<<endl;
        else
            cout<<"Case "<<q<<": "<<-1<<endl;

//        for(int i=0;i<row;i++)
//        {
//            for(int j=0;j<col;j++)
//                cout<<grid[i][j]<<" ";
//            cout<<endl;
//        }



    }

    return 0;
}
