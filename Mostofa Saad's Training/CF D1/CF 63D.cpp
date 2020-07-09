
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

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

int g[150][150];
bool vis[150][150];

/// up move , then down move
vector<int>dx = {1,-1,0,0};
vector<int>dy = {0,0,+1,-1};

bool isOk(int i,int j,int r,int c)
{
    if(i>=0 && i<r && j>=0 && j<c)
        return true;
    return false;
}

int now = 0;

void dfs(int x,int y,int r,int c, vector<int>&v)
{
    vis[x][y] = true;
    g[x][y] = now;

    v[now]--;
    if(v[now]==0)
        now++;

    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(isOk(nx,ny,r,c) && vis[nx][ny]==false)
            dfs(nx,ny,r,c,v);
    }
}

int main()
{
    optimizeIO();

    int a,b,c,d,n;
    cin>>a>>b>>c>>d>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    int col = a+c;
    int ro = max(b,d);
    int mnro = min(b,d);

    for(int i=0; i<ro; i++)
        for(int j=0; j<col; j++)
            g[i][j] = -1 , vis[i][j] = false;

    int st = -1 , en = -1;

    if(mnro==d) st = a , en = col;
    if(mnro==b) st = 0 , en = a;

    for(int i=mnro;i<ro;i++)
    {
        for(int j=st;j<en;j++)
        {
            vis[i][j] = true;
        }
    }

    cout<<"YES"<<endl;

    if(a&1) dfs(b-1,0,ro,col,v); /// 1,1
    else dfs(0,0,ro,col,v);  /// b,1

    for(int i=0; i<ro; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(g[i][j]==-1) cout<<".";
            else cout<<char(g[i][j]+'a');
        }
        cout<<endl;
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


