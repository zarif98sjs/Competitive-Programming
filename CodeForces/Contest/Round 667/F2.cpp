
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

string s,t;
int n,k;
int dp[205][205][205];

int solve(int pos,int mv,int cnt0)
{
    if(pos==(int)s.size()) return 0;

    int &ret = dp[pos][mv][cnt0];
    if(~ret) return ret;

    ret = solve(pos+1,mv, cnt0 + (s[pos]==t[0])) + (s[pos]==t[1]) * cnt0; /// stay same , for each t[1] the number adds to ans is the current count of t[0]

    if(mv<k)
    {
        ret = max(ret,solve(pos+1,mv+1,cnt0+1)); /// change to t[0]
        ret = max(ret,solve(pos+1,mv+1,cnt0 + (t[1]==t[0]) ) + cnt0) ; /// change to t[1]
    }

    return ret;
}

int main()
{
    optimizeIO();

    cin>>n>>k;
    cin>>s>>t;

    memset(dp,-1,sizeof dp);
    int ans = solve(0,0,0);
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
