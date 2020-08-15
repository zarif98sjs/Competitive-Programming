
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
ostream &operator <<(ostream &os, multiset<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;

int nr,ng,nb;
vector<LL>r,g,b;

LL dp[205][205][205];

LL solve(int i,int j,int k)
{
    int cnt = 0;

    if(i>=nr) cnt++;
    if(j>=ng) cnt++;
    if(k>=nb) cnt++;

    if(cnt>=2) return 0;

    LL &ret = dp[i][j][k];
    if(ret != -1) return ret;

    ret = 0;

    if(j<ng && k<nb) ret = max(ret,g[j]*b[k] + solve(i,j+1,k+1));
    if(i<nr && k<nb) ret = max(ret,r[i]*b[k] + solve(i+1,j,k+1));
    if(i<nr && j<ng) ret = max(ret,r[i]*g[j] + solve(i+1,j+1,k));

    return ret;
}

int main()
{
    optimizeIO();

    cin>>nr>>ng>>nb;

    LL x;
    for(int i=0;i<nr;i++) cin>>x  , r.push_back(x);
    for(int i=0;i<ng;i++) cin>>x  , g.push_back(x);
    for(int i=0;i<nb;i++) cin>>x  , b.push_back(x);

    sort(ALL(r));
    sort(ALL(g));
    sort(ALL(b));

    reverse(ALL(r));
    reverse(ALL(g));
    reverse(ALL(b));

    memset(dp,-1,sizeof dp);
    LL ans = solve(0,0,0);
    cout<<ans<<endl;
    DBG(ans);
    return 0;
}

/**
10 1 1
11 7 10 10 10 14 2 4 13 14
8
11
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
ostream &operator <<(ostream &os, multiset<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


