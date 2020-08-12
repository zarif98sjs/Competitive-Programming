
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

const int nmax = 1e4+7;
const int MIN = -1e9;

vector<int>p,f;
int money,n;
int dp[105][nmax];

int solve(int pos,int P)
{
    if(pos==n)
    {
        if(P>2000) P -= 200;

        if(P<=money) return 0;
        return MIN;
    }

    if(P>=nmax) return MIN;

    int &ret = dp[pos][P];
    if(~ret) return ret;

    int inc = f[pos] + solve(pos+1,P + p[pos]);
    int exc = solve(pos+1,P);

    return ret = max(inc,exc);
}

int main()
{
    optimizeIO();

    while(cin>>money>>n)
    {
        p = vector<int>(n);
        f = vector<int>(n);

        for(int i=0;i<n;i++)
            cin>>p[i]>>f[i];

        memset(dp,-1,sizeof dp);
        int ans = solve(0,0);
        DBG(ans);
        cout<<ans<<"\n";
    }

    return 0;
}

/**
500 4
100 2
100 3
200 3
400 4
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


