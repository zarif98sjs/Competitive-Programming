
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
const int MOD = 1e9+7;

int dp[nmax][5];

string t = "abc";
int n;
string s;

int add(int a,int b)
{
    return (a+b) % MOD;
}

int solve(int pos,int milse)
{
    if(pos==n) return milse==3;

    int &ret = dp[pos][milse];
    if(ret != -1) return ret;

    ret = 0;

    if(s[pos]!='?')
    {
        if(milse<3 && s[pos]==t[milse]) ret = add(ret,solve(pos+1,milse+1));
        ret = add(ret,solve(pos+1,milse));
    }
    else
    {
        for(char z ='a';z<='c';z++)
        {
            if(milse<3 && z==t[milse]) ret = add(ret,solve(pos+1,milse+1));
            ret = add(ret,solve(pos+1,milse));
        }
    }

    return ret;
}

void solveTC()
{
    cin>>n>>s;

    memset(dp,-1,sizeof dp);
    int ans = solve(0,0);
    cout<<ans<<endl;
    DBG(ans);
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
