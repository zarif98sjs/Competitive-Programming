
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

int mx = 0;

vector<PII> compress(vector<PII> &v) /// compress v to [1,max distinct number range]
{
    vector<PII>c = v;
    map<int,int>m;

    for(auto x:c) m[x.F] = 1 , m[x.S] = 1;

    int val = 0;
    for(auto x:m) m[x.F] = ++val;
    mx = val;

    for(auto &x:c) x.F = m[x.F] , x.S = m[x.S];

    return c;
}

void solveTC()
{
    int n;
    cin>>n;

    vector<PII>v(n);
    vector<int>p(n);

    for(int i=0;i<n;i++) cin>>v[i].F>>v[i].S>>p[i];

    v = compress(v);

    vector<vector<PII>>projects(mx+2);

    for(int i=0;i<n;i++)
    {
        auto x = v[i];
        projects[x.S].push_back({x.F,p[i]});
    }

//    DBG(mx);

    vector<LL>dp(mx+2,0);

    for(int i=1;i<=mx;i++)
    {
        dp[i] = dp[i-1]; /// no project done , so same gain as previous day

        for(auto x:projects[i])
        {
            dp[i] = max(dp[i],dp[x.F-1] + x.S); /// max upto this project's staring time + this project's money
        }

//        DBG(dp[i]);
    }

    cout<<dp[mx]<<endl;
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
