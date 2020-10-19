
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e3+7;

string g[nmax];
bool vis[nmax][nmax];
int r,c;

bool ok(int i,int j)
{
    if(i>=0 && i<r && j>=0 && j<c && g[i][j]!='#') return true;

    return false;
}

vector<int>dx = {0,1,0,-1};
vector<int>dy = {1,0,-1,0};

int cc = 0;

void dfs(int x,int y)
{
    vis[x][y] = true;

    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(ok(nx,ny) && !vis[nx][ny])
            dfs(nx,ny);
    }
}

void solveTC()
{
    cin>>r>>c;

    for(int i=0;i<r;i++)
        cin>>g[i];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(ok(i,j) && !vis[i][j])
                dfs(i,j) , cc++ ;
        }
    }

    cout<<cc<<endl;
}

int32_t main()
{
    optimizeIO();

    int tc = 1;
//    cin>>tc;

    while(tc--)
    {
        solveTC();
    }

    return 0;
}

/**

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}

