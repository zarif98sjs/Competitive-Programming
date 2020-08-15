
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

#define int long long

const int nmax = 2e5+7;
const LL INF = 1e18;

int n,m,need;
vector<int>c;
vector<vector<int>>cost;

int dp[105][105][105];

int solve(int pos,int prev,int beauty)
{
    if(pos==n)
    {
        if(beauty == need) return 0;
        return INF;
    }

    int &ret = dp[pos][prev][beauty];
    if(ret != -1) return ret;

    ret = INF;

    if(c[pos]!=0)
    {
        ret = min(ret,solve(pos+1,c[pos], c[pos]==prev ? beauty : beauty +1 ));
    }
    else
    {
        for(int col=1;col<=m;col++)
             ret = min(ret,cost[pos][col-1] + solve(pos+1,col, col==prev ? beauty : beauty+1 ));
    }

    return ret;

}

int32_t main()
{
    optimizeIO();

    cin>>n>>m>>need;

    c = vector<int>(n);
    cost = vector<vector<int>>(n,vector<int>(m));

    for(int i=0;i<n;i++)
        cin>>c[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>cost[i][j];

    memset(dp,-1,sizeof dp);
    int ans = solve(0,101,0);

    if(ans>=INF) ans = -1;

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



