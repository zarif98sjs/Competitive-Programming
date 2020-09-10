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

const int nmax = 2e5+7;

int r,c,k;
vector<string>g;
vector<vector<bool>>vis;
vector<vector<bool>>gamela;


//bool gamela[1005][1005];
int pic = 0;
vector<vector<int>>comp;
vector<int>dx = {-1,0,1,0};
vector<int>dy = {0,1,0,-1};

bool ok(int i,int j)
{
    if(i>=0 && i<r && j>=0 && j<c)
        return true;
    return false;
}

int COMP = 0;

void dfs(int x,int y)
{
    vis[x][y] = true;
    comp[x][y] = COMP;

    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(ok(nx,ny) && !vis[nx][ny] && g[nx][ny]=='.')
        {
            dfs(nx,ny);
        }
        if(ok(nx,ny) && g[nx][ny]=='*')
        {
            gamela[nx][ny]=true;
            pic++;
        }
    }
}

vector<int>ans;

int solve(int sx,int sy)
{
    int sc = comp[sx][sy];
    return ans[sc];
}

int main()
{
    optimizeIO();

    int tc = 1;

    while(tc--)
    {
        cin>>r>>c>>k;

        g = vector<string>(r);
        vis = vector<vector<bool>>(r,vector<bool>(c,false));
        gamela = vector<vector<bool>>(r,vector<bool>(c,false));

        comp = vector<vector<int>>(r,vector<int>(c,-1));

        for(int i=0;i<r;i++)
            cin>>g[i];

        DBG(g);

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(g[i][j]=='.' && vis[i][j]==false)
                {
                    dfs(i,j);
//                    DBG(vis);
                    COMP++;
                    DBG(pic);
                    ans.push_back(pic);
                    pic = 0;
                }
            }
        }

        DBG(comp);

        while(k--)
        {
            int sx,sy;
            cin>>sx>>sy;
            sx--,sy--;

            int res = solve(sx,sy);
            cout<<res<<endl;
            DBG(res);
        }


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
