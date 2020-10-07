
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

int n,max_cost;
vector<int>cost,page;

int dp[1002][100002];

int solve(int pos,int sum)
{
    if(sum<0) return INT_MIN;

    if(pos<0)
    {
        return sum>=0 ? 0 : INT_MIN;
    }

    int &ret = dp[pos][sum];
    if(ret != -1) return ret;

    int inc = solve(pos-1,sum-cost[pos]) + page[pos];
    int exc = solve(pos-1,sum);

    return ret = max(inc,exc);
}

void solveTC()
{
    cin>>n>>max_cost;

    cost = vector<int>(n+1);
    page = vector<int>(n+1);

    for(int i=1;i<=n;i++)cin>>cost[i];
    for(int i=1;i<=n;i++)cin>>page[i];

    dp[0][0] = 0;

    for(int i=1;i<=n;i++)
    {
        for(int s=1;s<=max_cost;s++)
        {
            dp[i][s] = max(dp[i][s],dp[i-1][s]);
            if(s-cost[i]>=0) dp[i][s] = max(dp[i][s],dp[i-1][s-cost[i]]+page[i]);
        }
    }

    cout<<dp[n][max_cost]<<endl;
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

