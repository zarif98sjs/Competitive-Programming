
/**

Solve(i,j) = maximum score for the range [i,j]

Option 1 : take i , solve(i+1,j) is opponent's maximum score . So my score is v[i] + sum(i+1,j) - solve(i+1,j)
Option 2 : take j , solve(i,j-1) is opponent's maximum score . So my score is v[j] + sum(i,j-1) - solve(i,j-1)

**/


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

#define int long long
const int nmax = 5007;
const int INF = 1e15;

vector<int>v;
vector<int>p;

int dp[nmax][nmax];

int sum(int l,int r)
{
    return p[r] - p[l-1];
}

int solve(int i,int j)
{
    if(i==j) return v[i];

    int &ret = dp[i][j];
    if(ret != -1) return ret;

    ret = -INF;

    int op_mx_1 = solve(i+1,j);
    int me_mx_1 = v[i] + sum(i+1,j) - op_mx_1;
    ret = max(ret,me_mx_1);

    int op_mx_2 = solve(i,j-1);
    int me_mx_2 = v[j] + sum(i,j-1) - op_mx_2;
    ret = max(ret,me_mx_2);

    return ret;
}

void solveTC()
{
    int n;
    cin>>n;

    v = vector<int>(n+1);
    p = vector<int>(n+1);

    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) p[i] = p[i-1] + v[i];

    memset(dp,-1,sizeof dp);

    int ans = solve(1,n);
    cout<<ans<<endl;

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
