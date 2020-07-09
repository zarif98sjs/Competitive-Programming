
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

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
LL mod = 1e9+7;

LL dp[nmax];
LL ans[nmax];

int main()
{
    optimizeIO();

    int tc,k;
    cin>>tc>>k;
    LL n = 1e5;

    dp[0] = 1;

    for(LL i=1;i<=n;i++)
    {
        LL way1 = 0, way2 = 0;

        way1 = dp[i-1]; /// ith one is Red , no condition here
        if(i-k>=0) way2 = dp[i-k]; /// ith one is White , We have to have K Whites including the ith one

        dp[i] = (way1%mod + way2%mod)%mod;

        ans[i] = (ans[i-1]%mod + dp[i]%mod)%mod;
    }

    while(tc--)
    {
        int l,r;
        cin>>l>>r;

        LL res = (ans[r] - ans[l-1] + mod)%mod;

        cout<<res<<endl;
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


