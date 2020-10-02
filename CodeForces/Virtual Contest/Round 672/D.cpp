
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
const int nmax = 2e5+7;
const int MOD = 998244353;

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


/** nCr : O(n) **/

const int fnmax = 1e6+7;
LL facto[fnmax];

void precalc(LL lim,LL m)
{
    facto[0] = 1;

    for(LL i=1; i<=lim; i++)
        facto[i]=((facto[i-1]%m)*(i%m))%m; /// (facto[i-1]*i)%m
}

LL nCr(LL n,LL r,LL m)
{
    LL up = facto[n];
    LL d1 = facto[n-r];
    LL d2 = facto[r];

    d1 = invMod_general(d1,m);
    d2 = invMod_general(d2,m);

    LL ans = (up * d1)%m;
    ans = (ans * d2)%m;

    return ans;
}

void solveTC()
{

    int n,k;
    cin>>n>>k;

    precalc(n,MOD);

    vector<int>all;
    vector<PII>segment(n);
    for(int i=0;i<n;i++)
    {
        int s,e;
        cin>>s>>e;

        all.push_back(s);
        all.push_back(e);

        segment[i] = {s,e};
    }

    map<int,int>m;

    for(int x:all) m[x] = 1;

    int val = 0;
    for(auto x:m) m[x.F] = ++val;

//    for(auto x:m) DBG(m[x.F]);
    vector<int>st(val+2,0),en(val+2,0);

    for(int i=0;i<n;i++)
    {
        int s = segment[i].F;
        int e = segment[i].S;

        segment[i] = {m[s],m[e]};
        DBG(segment[i]);

        st[m[s]]++;
        en[m[e]]++;
    }

    int cur = 0;
    int ans = 0;
    int sum1 = 0;
    int sum2 = 0;

    DBG(val);

    for(int i=1;i<=val;i++)
    {
        int now = st[i];
        DBG(now);

        cur += now;
        DBG(cur);
        DBG(k-1);

        sum1 = 0;
        if(cur>=k)sum1 = nCr(cur,k,MOD);
        sum1 %= MOD;

        sum2 = 0;
        if(cur-now>=k)sum2 = nCr(cur-now,k,MOD);
        sum2 %= MOD;

        ans = (ans + sum1)%MOD;
        ans = (ans - sum2 + MOD)%MOD;

        cur -= en[i];
    }

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
