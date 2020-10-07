
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
const int INF = 1e9;

string s,t;
int dp[5005][5005];

int solve(int i,int j)
{
    if(i<0) return j+1; /// remaining length
    if(j<0) return i+1; /// remaining length

    int &ret = dp[i][j];
    if(ret != -1) return ret;

    ret = INF;

    if(s[i]==t[j]) ret = min(ret,solve(i-1,j-1));
    else
    {
        ret = min(ret,1+solve(i-1,j)); /// add / remove
        ret = min(ret,1+solve(i,j-1)); /// add / remove
        ret = min(ret,1+solve(i-1,j-1)); /// replace
    }

    return ret;
}

void solveTC()
{
    cin>>s>>t;

    int n = s.size();
    int m = t.size();

    memset(dp,-1,sizeof dp);
    cout<<solve(n-1,m-1)<<endl;
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

