
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
const int mod = 1e9+7;

int add(int a,int b)
{
    return (1LL*a+b)%mod;
}

int n;
int dp[nmax][nmax];
string g[nmax];

bool ok(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<n && g[i][j]!='*') return true;

    return false;
}

void solveTC()
{
    cin>>n;

    for(int i=0;i<n;i++) cin>>g[i];

    if(ok(0,0)) dp[0][0] = 1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!ok(i,j)) continue;

            if(ok(i-1,j)) dp[i][j] = add(dp[i][j],dp[i-1][j]);
            if(ok(i,j-1)) dp[i][j] = add(dp[i][j],dp[i][j-1]);
        }
    }

    cout<<dp[n-1][n-1]<<endl;
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

