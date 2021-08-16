
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
const int INF = 2e9;

int n;
string s;
int dp[105][4];

/// 1 - B
/// 2 - R

int solve(int pos,int prvCol)
{
    if(pos >= n) return 0;

    int &ret = dp[pos][prvCol];
    if(ret != -1) return ret;

    ret = INF;

    if(s[pos] == '?')
    {
        ret = min(ret, solve(pos+1,1) + (prvCol == 1)); /// B
        ret = min(ret, solve(pos+1,2) + (prvCol == 2)); /// R
    }
    else
    {
        if(s[pos] == 'B') ret = min(ret, solve(pos+1,1) + (prvCol == 1)); /// B
        if(s[pos] == 'R') ret = min(ret, solve(pos+1,2) + (prvCol == 2)); /// R
    }

    return ret;
}

string solveString(int pos,int prvCol)
{
    if(pos >= n) return "";

    if(s[pos] == '?')
    {
        int val1 = solve(pos+1,1) + (prvCol == 1); /// B
        int val2 = solve(pos+1,2) + (prvCol == 2); /// R

        if(val1 < val2) return "B" + solveString(pos+1,1);
        else return "R" + solveString(pos+1,2);
    }
    else
    {
        if(s[pos] == 'B')
        {
            return "B" + solveString(pos+1,1);
        }
        if(s[pos] == 'R')
        {
            return "R" + solveString(pos+1,2);
        }
    }
}

void solveTC()
{
    cin>>n>>s;

    memset(dp,-1,sizeof dp);

    int ans = solve(0,0);
//    DBG(ans);
    string ansStr = solveString(0,0);
//    DBG(ansStr);
//
    cout<<ansStr<<endl;

}

int32_t main()
{
    optimizeIO();

    int tc = 1;
    cin>>tc;

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
