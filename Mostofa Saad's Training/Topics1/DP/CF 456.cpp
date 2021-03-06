
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

const int nmax = 1e5+7;

LL n;
vector<LL>v;
vector<LL>cnt(nmax);

LL dp[nmax];

LL solve(LL i)
{
    if(i<=0) return 0;
    if(i==1) return 1LL*cnt[1];

    LL &ret = dp[i];
    if(~ret) return ret;

    ret = 0;

    ret = max(ret,i*cnt[i] + solve(i-2));
    ret = max(ret,solve(i-1));

    return ret;
}

int main()
{
    optimizeIO();

    cin>>n;
    v = vector<LL>(n);

    LL mx = 0;

    for(int i=0; i<n; i++)
        cin>>v[i], cnt[v[i]]++ , mx = max(mx,v[i]);

    memset(dp,-1,sizeof dp);
    LL ans = solve(mx);
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
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
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


