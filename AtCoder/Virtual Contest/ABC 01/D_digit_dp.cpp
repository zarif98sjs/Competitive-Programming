
/// https://codeforces.com/blog/entry/71647#comment-559893

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

const int MOD = 1e9+7;
const int MAXBIT = 60;

int n;
int dp[70][3][3];

int solve(int pos,int carry,int ok)
{
    if(pos==MAXBIT) return (carry==0 && ok==1);

    int &ret = dp[pos][carry][ok];
    if(ret != -1) return ret;

    int nthbit = (n>>pos)&1;

    ret = 0;

    for(int a=0;a<2;a++)
    {
        for(int b=0;b<=a;b++)
        {
            int curbit = (a+b+carry)%2;
            int ncarry = (a+b+carry)/2;

            int nok = ok;

            if(curbit < nthbit) nok = 1;
            if(curbit > nthbit) nok = 0;

            ret += solve(pos+1,ncarry,nok);
            ret %= MOD;
        }
    }

    return ret;
}

int32_t main()
{
    optimizeIO();
    cin>>n;

    memset(dp,-1,sizeof dp);
    int ans = solve(0,0,1);
    DBG(ans);
    cout<<ans<<endl;

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
