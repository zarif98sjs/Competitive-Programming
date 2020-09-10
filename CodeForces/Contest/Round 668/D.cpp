
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
int n,sta,stb,da,db;

vector<vector<int>>adj;
vector<int>d;

void dfs(int u,int p)
{
    if(p!=-1) d[u] = d[p] + 1;

    for(int v:adj[u])
        if(v!=p)
            dfs(v,u);
}

int diameter(int n)
{
    d[1] = 0;
    dfs(1,-1);

    int farthest1 = -1;
    int mx = 0;

    for(int i=1;i<=n;i++)
    {
        if(d[i]>mx)
        {
            farthest1 = i;
            mx = d[i];
        }
    }

    d[farthest1] = 0;
    dfs(farthest1,-1);

    mx = 0;

    for(int i=1;i<=n;i++)
    {
        if(d[i]>mx)
        {
            farthest1 = i;
            mx = d[i];
        }
    }

    return mx;
}

void init(int len)
{
    adj = vector<vector<int>>(len);
    d = vector<int>(len);
}

bool solveTC()
{
    cin>>n>>sta>>stb>>da>>db;

    init(n+1);

    int edges = n-1;

    while(edges--)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int di = diameter(n);

    d[sta] = 0;
    dfs(sta,-1);

    /**
    op 1 : catch in the first move
    op 2 : catch in the second move
    op 3 : catch if possible or move one vertex closer
    **/
    if(da>=d[stb] || 2*da>=di || 2*da>=db) return true;
    return false;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        bool ans = solveTC();

        if(ans) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
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
