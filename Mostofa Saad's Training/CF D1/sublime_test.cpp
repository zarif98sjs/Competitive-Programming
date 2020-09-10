
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

const int nmax = 1e5+7;
const int INF = 1e9;

int solve(vector<int> &v)
{
    vector<int>dp(nmax);

    int ans = 0;

    for(int num:v)
    {   
        dp[num] = 1;

        vector<int>div;

        for(int i=2;i*i<=num;i++)
        {
            if(num%i==0)
            {
                div.push_back(i);
                if(i!=(num/i)) div.push_back(num/i);
            }
        }

        for(int d:div) dp[num] = max(dp[num],dp[d]+1);
        for(int d:div) dp[d] = dp[num]; // can do this as the numbers are sorted

        DBG(dp[num]);
        ans = max(ans,dp[num]);

        // for(int x:v) cout<<x<<" : "<<dp[x]<<endl;
    }

    DBG(ans);

    return ans;
}

int main()
{
    optimizeIO();

    // WRITE;

    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int ans = solve(v);
    cout<<ans<<endl;
    

    return 0;
}

/**
10
1 2 3 4 5 4 3 2 1 10
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


