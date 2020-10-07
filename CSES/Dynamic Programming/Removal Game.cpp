

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

const int nmax = 5e2+7;
const int mod = 1e9+7;

int add(int a,int b)
{
    return (1LL*a+b)%mod;
}

/// ax + by = GCD(a,b)
/// r2 is GCD(a,b) and X & Y will be the co-eff of a and b respectively
template <class T>
T ext_gcd ( T A, T B, T &X, T &Y )
{
    T x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1;
    y2 = 0;
    x1 = 0;
    y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y )
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    X = x2;
    Y = y2;
    return r2;
}

template <class T>
T invMod_general(T a,T m) /// when inverse of a (w.r.to mo) && mo is not prime
{
    T x, y;
    ext_gcd( a, m, x, y );

    /// Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 )
        x += m;
    return x;
}


int n;
vector<int>v;

int dp[nmax][130000];

int solve(int pos,int s1,int s2)
{
    if(pos>n) return (s1-s2)==0;

    int &ret = dp[pos][s1];
    if(ret != -1) return ret;

    ret = 0;

    ret = add(ret,solve(pos+1,s1+v[pos],s2));
    ret = add(ret,solve(pos+1,s1,s2+v[pos]));

    return ret;
}

void solveTC()
{
    cin>>n;

    v = vector<int>(n+1);
    for(int i=1;i<=n;i++) v[i] = i;

    memset(dp,-1,sizeof dp);
    LL ans = solve(1,0,0);

    LL x = invMod_general(2,mod);
    ans = (ans*x)%mod;

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
