
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
    if(i>=0 && i<r && j>=0 && j<c && g[i][j]!='#')
        return true;

    return false;
}

vector<int>dx = {0,1,0,-1};
vector<int>dy = {1,0,-1,0};

PII par[nmax][nmax];
int dist[nmax][nmax];

void bfs(int x,int y)
{
    queue<PII>q;

    q.push({x,y}) , vis[x][y] = true;

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();
        int ux = u.F , uy = u.S;

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
}

void find_path(PII a,PII b)
{
    if(vis[b.F][b.S]==false)
    {
        cout<<"NO"<<endl;
        return;
    }

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
    reverse(ALL(v));
    for(string s:v)
        cout<<s;
    cout<<endl;
}

void solveTC()
{
    cin>>r>>c;

    for(int i=0; i<r; i++)
        cin>>g[i];

    PII a, b;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(g[i][j]=='A')
                a = {i,j};
            if(g[i][j]=='B')
                b = {i,j};

            if(ok(i,j) && !vis[i][j] && g[i][j]=='A')
                bfs(i,j) ;
        }
    }

    find_path(a,b);
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


