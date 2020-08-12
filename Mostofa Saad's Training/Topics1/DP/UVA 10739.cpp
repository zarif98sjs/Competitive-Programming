
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

const int nmax = 1e3+7;
const int INF= 1e9;

string s;

int dp[nmax][nmax];

int solve(int i,int j)
{
    if(i>j) return 0;

    int &ret = dp[i][j];
    if(~ret) return ret;

    ret = INF;

    if(s[i]==s[j]) ret = solve(i+1,j-1);
    else
    {
        ret = min(ret,1 + solve(i+1,j)); /// add to the right of j / remove i
        ret = min(ret,1 + solve(i,j-1)); /// add to the left of i / remove j
        ret = min(ret,1 + solve(i+1,j-1)); /// replace one
    }

    return ret;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    int cs = 0;

    while(tc--)
    {
        cin>>s;

        int n = s.size();

        memset(dp,-1,sizeof dp);
        int ans = solve(0,n-1);

        cout<<"Case "<<++cs<<": "<<ans<<endl;
    }

    return 0;
}

/**
6
tanbirahmed
shahriarmanzoor
monirulhasan
syedmonowarhossain
sadrulhabibchowdhury
mohammadsajjadhossain
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


