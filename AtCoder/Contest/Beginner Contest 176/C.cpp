
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
const int MOD = 1e9+7;

int add(int a,int b)
{
    return (a+b) % MOD;
}

int mul(int a,int b)
{
    return (1LL*a*b) % MOD;
}

int32_t main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int>v(n+10);
    for(int i=1;i<=n;i++) cin>>v[i];

    vector<int>p(n+10);
    for(int i=1;i<=n;i++) p[i] = add(p[i-1] ,v[i]);

    int ans = 0;

    for(int i=1;i<=n;i++)
    {
        int sum = (p[n] - p[i] + MOD)%MOD;
        DBG(sum);
        int ad = mul(v[i],sum);

        ans = add(ans,ad);
        ans %= MOD;
    }

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
