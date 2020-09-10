 
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
const int INF= 1e9;
 
int n;
vector<int>v;
int dp[nmax][3][2];
 
int add(int x,int y)
{
    return (x+y)%3;
}
 
template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}
 
 
int solve(int pos,int sum,bool first)
{
    if(pos==n)
    {
        return sum == 0 ? 0 : INF;
    }
 
    int &ret = dp[pos][sum][first];
    if(~ret) return ret;
 
    ret = INF;
 
    if(first)
    {
        if(v[pos]==0) ret = min(ret,1 + solve(pos+1,sum,first));
        else
        {
             ret = min(ret,solve(pos+1,add(sum,v[pos]),false));
             ret = min(ret,1 + solve(pos+1,sum,first));
        }
    }
    else
    {
        ret = min(ret,solve(pos+1,add(sum,v[pos]),false));
        ret = min(ret,1 + solve(pos+1,sum,first));
    }
    
    return ret;
}
 
string solve_ans(int pos,int sum,bool first)
{
    if(pos==n)
    {
        return "";
    }
 
    if(first)
    {
        if(v[pos]==0) return solve_ans(pos+1,sum,first);
        else
        {
            int way1 = solve(pos+1,add(sum,v[pos]),false);
            int way2 =  1 + solve(pos+1,sum,first);
 
            if(way1<way2) return to_str(v[pos]) + solve_ans(pos+1,add(sum,v[pos]),false);
            else return solve_ans(pos+1,sum,first);
        }
    }
    else
    {
        int way1 = solve(pos+1,add(sum,v[pos]),false);
        int way2 =  1 + solve(pos+1,sum,first);
 
        if(way1<way2) return to_str(v[pos]) + solve_ans(pos+1,add(sum,v[pos]),false);
        else return solve_ans(pos+1,sum,first);
    }
}

bool zero_ase(string s)
{
    for(auto ch:s)
        if(ch=='0')
            return true;

    return false;
}
 
int main()
{
    optimizeIO();
 
    string s;
    cin>>s;
 
    n = s.size();
 
    v = vector<int>(n);
    // dp = vector<vector<int>>(n+1,vector<int>(5,-1));
 
    for(int i=0;i<n;i++)
        v[i] = s[i] - '0';
 
    memset(dp,-1,sizeof dp);
    int remove = solve(0,0,true);
 
    if(remove>=n)
    {
        if(zero_ase(s)) cout<<0<<endl;
        else cout<<-1<<endl;
    }
    else
    {
        string res = solve_ans(0,0,true);
        DBG(res);
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