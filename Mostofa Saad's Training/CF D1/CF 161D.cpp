
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

#define int long long

int n,k;
vector<vector<int>>adj;
vector<vector<int>>dp;

int ans = 0;

void dfs(int u,int p=-1)
{
    dp[u][0] = 1;

    for(int v:adj[u])
    {
        if(v!=p)
        {
            dfs(v,u);

            int s = 0;
            int need = k-2;
            for(int i=1;i<=k;i++) dp[u][i] += dp[v][i-1];
            for(int x=0;x<=need;x++) s += (dp[v][x]*(dp[u][need-x+1] - dp[v][need-x]));
            DBG(s);
            ans += s;
        }
    }

    ans += dp[u][k];
}

void INIT(int len,int kk)
{
    adj = vector<vector<int>>(len);
    dp = vector<vector<int>>(len,vector<int>(kk));

    for (int i = 0; i < len; i++)
    {
        dp[i][0] = 0;
    }
    
}

int32_t main()
{
    optimizeIO();

    cin>>n>>k;

    INIT(n+1,k+1);

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    DBG(dp);

    cout<<ans<<endl;
    DBG(ans);
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


