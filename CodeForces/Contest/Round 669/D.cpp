
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

const int nmax = 3e5+7;
const int INF = 1e9;

vector<int>adj[nmax];

void build_graph(vector<int>&h)
{
    int n = h.size();

    vector<PII>stk;

    /// first largest from right
    for(int i=n-1;i>=0;i--)
    {
        while(!stk.empty() && h[i] > stk.back().F)
            stk.pop_back();

        if(!stk.empty()) adj[i].push_back(stk.back().S); /// jump over lower ones

        stk.push_back({h[i],i});
    }

    /// first smallest from right
    for(int i=n-1;i>=0;i--)
    {
        while(!stk.empty() && h[i] < stk.back().F)
            stk.pop_back();

        if(!stk.empty()) adj[i].push_back(stk.back().S); /// jump over higher ones

        stk.push_back({h[i],i});
    }


    /// first largest from left
    for(int i=0;i<n;i++)
    {
        while(!stk.empty() && h[i] > stk.back().F)
            stk.pop_back();

        if(!stk.empty()) adj[stk.back().S].push_back(i); /// jump over lower ones

        stk.push_back({h[i],i});
    }

    /// first smallest from left
    for(int i=0;i<n;i++)
    {
        while(!stk.empty() && h[i] < stk.back().F)
            stk.pop_back();

        if(!stk.empty()) adj[stk.back().S].push_back(i); /// jump over higher ones

        stk.push_back({h[i],i});
    }
}

int solve(int n)
{
    vector<int>dp(nmax,INF);
    dp[0] = 0;
    for(int i=0;i<n;i++)
        for(int to:adj[i])
            dp[to] = min(dp[to],dp[i]+1);

    return dp[n-1];

}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int>h(n);
    for(int i=0;i<n;i++) cin>>h[i];

    build_graph(h);

    int ans = solve(n);
    cout<<ans<<endl;

    DBG(ans);

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
