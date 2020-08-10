
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

const int nmax = 505+7;

string g[nmax];
bool vis[nmax][nmax];

vector<int>dx = {-1,0,1,0};
vector<int>dy = {0,1,0,-1};

int r,c,k;

bool ok(int x,int y)
{
    if(x>=0 && x<r && y>=0 && y<c && g[x][y]=='.')
        return true;
    return false;
}

int tot = 0;

void dfs1(int x,int y)
{
    vis[x][y] = true;
    ++tot;

    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(ok(nx,ny) && !vis[nx][ny])
            dfs1(nx,ny);
    }
}

int cnt = 0;

void dfs2(int x,int y)
{
    if(cnt==tot-k)
        return;

    vis[x][y] = true;
    ++cnt;

    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(ok(nx,ny) && !vis[nx][ny])
            dfs2(nx,ny);
    }
}

int main()
{
    optimizeIO();

    cin>>r>>c>>k;

    for(int i=0; i<r; i++)
        cin>>g[i];

    bool done = false;

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(!vis[i][j] && g[i][j]!='#' && !done)
                dfs1(i,j), done = true;

    memset(vis,0,sizeof vis);

    done = false;

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(!vis[i][j] && g[i][j]!='#' && !done)
                dfs2(i,j), done = true;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(g[i][j]!='#' && vis[i][j]==false)
                g[i][j] = 'X';
            cout<<g[i][j];
        }
        cout<<endl;
    }

    return 0;
}

/**
3 3 0
###
###
##.
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
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
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


