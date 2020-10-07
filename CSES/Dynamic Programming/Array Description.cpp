
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

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

const int mod = 1e9+7;

int add(int a,int b)
{
    return (1LL*a+b)%mod;
}

int n,m;
vector<int>v;

int dp[nmax][105];

bool ok(int prv,int cur,int nxt)
{
    if(cur<1 || cur>m) return false;

    if(prv==0 && nxt==0) return true;

    if(abs(cur-prv)>1) return false;
    if(abs(cur-nxt)>1) return false;

    return true;
}

int solve(int pos,int prv)
{
    if(pos>n) return 1;

    int &ret = dp[pos][prv];
    if(ret != -1) return ret;

    ret = 0;

    if(pos==1 && v[pos]==0)
    {
        int nxt = v[pos+1];

        for(int cur=1;cur<=m;cur++)
        {
            if(ok(prv,cur,nxt)) ret = add(ret,solve(pos+1,cur));
        }
    }
    else if(v[pos]==0)
    {
        for(int i=-1;i<=1;i++)
        {
            int nxt = v[pos+1];

            if(prv!=0 && nxt == 0) nxt = prv;

            if(ok(prv,prv+i,nxt)) ret = add(ret,solve(pos+1,prv+i));
        }
    }
    else ret = add(ret,solve(pos+1,v[pos]));

    return ret;

}

void solveTC()
{
    cin>>n>>m;

    v = vector<int>(n+2,0);
    for(int i=1;i<=n;i++) cin>>v[i];

    bool gamela = false;

    for(int i=2;i<=n;i++)
    {
        if(v[i]!=0 && v[i-1]!=0 && abs(v[i]-v[i-1])>1)
            gamela = true;
    }

    if(gamela)
    {
        cout<<0<<endl;
        return;
    }

    memset(dp,-1,sizeof dp);
    cout<<solve(1,0)<<endl;

}

int32_t main()
{
    optimizeIO();

    int tc = 1 ;
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

