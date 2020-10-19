
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
const int INF = 1e9;

string g[nmax];
bool vis[nmax][nmax];
int r,c;

bool ok(int i,int j)
{
    if(i>=0 && i<r && j>=0 && j<c && g[i][j]!='#')
        return true;

    return false;
}

vector<int>dx = {0,1,0,-1};
vector<int>dy = {1,0,-1,0};

PII par[nmax][nmax];
int dist[nmax][nmax];

PII start;

bool bfs(int x,int y)
{
//    cout<<x<<" , "<<y<<endl;

    /// normal looping gets TLE
    memset(vis,0,sizeof vis);

    queue<PII>q;

    q.push({x,y}) , vis[x][y] = true;
    dist[x][y] = 0;

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();

        int ux = u.F , uy = u.S;

        if(u==start) return true;
        if(g[ux][uy]=='M') return false;

        for(int i=0;i<4;i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];

            if(ok(vx,vy)==false)
                continue;
            if(vis[vx][vy])
                continue;

            dist[vx][vy] = dist[ux][uy] + 1;
            vis[vx][vy] = true;
            par[vx][vy] = {ux,uy};
            q.push({vx,vy});
        }
    }

    return false;
}

void find_path(PII a,PII b)
{
    swap(a,b);

    cout<<"YES"<<endl;

    PII p = b;
    vector<string>v;

    while(p != a)
    {
        PII prv = p;
        p = par[p.F][p.S];

        if(prv.F == p.F)
        {
            if(prv.S>p.S)
                v.push_back("R");
            if(prv.S<p.S)
                v.push_back("L");
        }

        if(prv.S == p.S)
        {
            if(prv.F>p.F)
                v.push_back("D");
            if(prv.F<p.F)
                v.push_back("U");
        }

        DBG(v);
    }

    cout<<v.size()<<endl;
    for(string s:v)
    {
        if(s=="L") cout<<"R";
        if(s=="R") cout<<"L";
        if(s=="U") cout<<"D";
        if(s=="D") cout<<"U";
    }
    cout<<endl;
}

void solve()
{
    bool done = false;

    for(int j=0,i=0;j<c;j++) if(g[i][j] != 'M' && ok(i,j)) if(bfs(i,j)) {find_path({start.F,start.S},{i,j}) , done = true; return;}
    for(int j=0,i=r-1;j<c;j++) if(g[i][j] != 'M' && ok(i,j))  if(bfs(i,j)) {find_path({start.F,start.S},{i,j}) , done = true; return;}
    for(int i=0,j=0;i<r;i++) if(g[i][j] != 'M' && ok(i,j))  if(bfs(i,j)) {find_path({start.F,start.S},{i,j}) , done = true; return;}
    for(int i=0,j=c-1;i<r;i++) if(g[i][j] != 'M' && ok(i,j))  if(bfs(i,j)) {find_path({start.F,start.S},{i,j}) , done = true; return;}

    if(!done) cout<<"NO"<<endl;
}

void solveTC()
{
    cin>>r>>c;

    for(int i=0; i<r; i++)
        cin>>g[i];

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(g[i][j]=='A')
            {
                start = {i,j};
                break;
            }
        }
    }

    solve();
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



