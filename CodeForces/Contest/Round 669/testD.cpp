
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> hs(n);
    for (int& h : hs)
        cin >> h;

    vector<int> lows, highs;
    vector<int> dp(n, n);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        // Jump over taller buildings
        while (! lows.empty() && hs[lows.back()] > hs[i])
        {
            dp[i] = min(dp[i], dp[lows.back()] + 1);
            lows.pop_back();
        }
        if (! lows.empty())
        {
            dp[i] = min(dp[i], dp[lows.back()] + 1);
            if (hs[lows.back()] == hs[i])
                lows.pop_back();
        }
        lows.push_back(i);

        // Jump over lower buildings
        while (! highs.empty() && hs[highs.back()] < hs[i])
        {
            dp[i] = min(dp[i], dp[highs.back()] + 1);
            highs.pop_back();
        }
        if (! highs.empty())
        {
            dp[i] = min(dp[i], dp[highs.back()] + 1);
            if (hs[highs.back()] == hs[i])
                highs.pop_back();
        }
        highs.push_back(i);


        DBG(lows);
        DBG(highs);
    }
    cout << dp[n-1] << '\n';
}

/**
15
2 3 4 5 6 5 4 1 4 3 2 3 4 5 6
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
