
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

const int nmax = 2e5+7;

vector<string> v1 , v2;

void Process(string s,vector<string>&v)
{
    for(auto &ch:s)
        if(!isalnum(ch))
            ch = ' ';

    v.clear();
    stringstream ss(s);

    while(ss>>s)
        v.push_back(s);
}

int dp[1005][1005];

int solve(int i,int j)
{
    if(i>=(int)v1.size() || j>=(int)v2.size())
        return 0;

    int &ret = dp[i][j];
    if(~ret) return ret;

    if(v1[i]==v2[j]) ret = 1 + solve(i+1,j+1);
    else ret = max(solve(i,j+1) , solve(i+1,j));

    return ret;
}

int main()
{
    optimizeIO();

    int cs = 0;
    string s1,s2;

    while(getline(cin,s1))
    {
        getline(cin,s2);

        if(s1.empty() || s2.empty())
        {
            printf("%2d. Blank!\n",++cs);
            continue;
        }

        Process(s1,v1);
        Process(s2,v2);

        memset(dp,-1,sizeof dp);
        int ans = solve(0,0);

        printf("%2d. Length of longest match: %d\n",++cs,ans);
    }

    return 0;
}

/**
This is a test.
test
Hello!

The document provides late-breaking information
late breaking.
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


