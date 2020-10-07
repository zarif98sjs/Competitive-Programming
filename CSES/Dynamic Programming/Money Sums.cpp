
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

const int nmax = 1e6+7;
const int mod = 1e9+7;

int add(int a,int b)
{
    return (1LL*a+b)%mod;
}

bool dp[nmax];

void solveTC()
{
    int n;
    cin>>n;

    int sum = 0;

    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i] , sum += coins[i];

    vector<int>dp(sum+1,false);

    dp[0] = true;

    for(int c:coins)
    {
        for(int i=sum;i>=0;i--)
        {
            if(dp[i]) dp[i+c] = true;
        }
    }

    vector<int>ans;

    for(int i=1;i<=sum;i++)
    {
        if(dp[i]) ans.push_back(i);
    }

    cout<<(int)ans.size()<<endl;

    for(int x:ans) cout<<x<<" ";
    cout<<endl;

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

