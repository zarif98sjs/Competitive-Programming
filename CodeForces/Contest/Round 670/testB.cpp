
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
const int mod = 1e9+7;

int ans;
int k;

int mul(int a,int b)
{
    a %= mod;
    b %= mod;

    return (a*b)%mod;
}

void solve(int i,int j,int cnt,int now,vector<int>&v)
{
    if(cnt==k)
    {
        ans = max(ans,now);
        return;
    }

    solve(i+1,j,cnt+1,mul(now,v[i]),v);
    solve(i,j-1,cnt+1,mul(now,v[j]),v);
}

void solveTC()
{
    int n;
    cin>>n>>k;

    ans = LLONG_MIN;

    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(ALL(v));

    solve(0,n-1,0,1,v);
}

int32_t main()
{
    optimizeIO();

    int tc=1;

    while(tc--)
    {
        solveTC();
        DBG(ans);
        cout<<ans<<endl;
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

