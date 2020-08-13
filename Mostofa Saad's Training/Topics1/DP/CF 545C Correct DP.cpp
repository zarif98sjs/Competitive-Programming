
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

const int nmax = 1e5+7;
const int INF = 2e9+7;

int n;
vector<int>X,H;
int dp[nmax][3];

int solve(int pos,int prev_type)
{
    if(pos==n) return 0;

    int &ret = dp[pos][prev_type];
    if(~ret) return ret;

    int prev_l;

    if(prev_type==0) prev_l = pos==0 ? -INF : X[pos-1]; /// left move in the last | stay
    if(prev_type==1) prev_l = X[pos-1] + H[pos-1]; /// right move in the last

    ret = 0;

    if(X[pos] + H[pos] < X[pos+1]) ret = max(ret,1 + solve(pos+1,1)); /** If right possible **/
    else ret = max(ret,solve(pos+1,0));

    if(X[pos] - H[pos] > prev_l) ret = max(ret,1 + solve(pos+1,0)); /** If left possible **/

    return ret;
}

int main()
{
    optimizeIO();

    cin>>n;

    X = vector<int>(n+1);
    H = vector<int>(n+1);

    for(int i=0;i<n;i++)
        cin>>X[i]>>H[i];

    X[n] = INF;

    memset(dp,-1,sizeof dp);
    int ans = solve(0,0);
    DBG(ans);
    cout<<ans<<endl;

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


