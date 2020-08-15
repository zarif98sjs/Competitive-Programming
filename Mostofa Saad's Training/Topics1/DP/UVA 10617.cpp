
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

#define int long long

string s;
int n;

int dp[100][100];

int solve(int i,int j)
{
    if(i==j) return 1; /// there is only one character
    if(j-i==1) return 2 + (s[i]==s[j]); /// there is 2 character , if they're equal we have 3 palindrome (e.g aa {aa,a,a} ) else we have 2 (e.g ab {a,b} )

    int &ret = dp[i][j];
    if(~ret) return ret;

    ret = 0;

    if(s[i]==s[j]) ret += 1 + solve(i+1,j-1);

    ret += solve(i+1,j);
    ret += solve(i,j-1);

    ret -= solve(i+1,j-1); /// from this 2 last cases we have the string twice so we subtract it
                         /// e.g abc left (b,c) ,right (a,b) now we took the b twice so we subtract one time

    return ret;
}


int32_t main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>s;
        n = s.size();

        memset(dp,-1,sizeof dp);
        int ans = solve(0,n-1);
        cout<<ans<<endl;
        DBG(ans);
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


