
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

int n;
vector<int>v;
int dp[nmax][3];

int solve(int pos,int turn)
{
    if(pos==n) return 0;

    int &ret = dp[pos][turn];
    if(ret != -1) return ret;

    ret = INT_MAX;
    if(turn==0)
    {
        ret = min(ret,(v[pos]==1)+solve(pos+1,turn^1));
        ret = min(ret,(v[pos]==1)+(v[pos+1]==1)+solve(pos+2,turn^1));
    }
    else
    {
        ret = min(ret,solve(pos+1,turn^1));
        ret = min(ret,solve(pos+2,turn^1));
    }

    return ret;
}

void solveTC()
{

    cin>>n;

    v = vector<int>(n);

    for(int i=0;i<n;i++) cin>>v[i];

    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=1;j++)
            dp[i][j] = -1;

    int ans = solve(0,0);
    cout<<ans<<endl;
    DBG(ans);

}

int32_t main()
{
    optimizeIO();

    int tc;
    cin>>tc;

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
