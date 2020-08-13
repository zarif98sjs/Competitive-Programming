
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
const LL INF = 1e18+7;

int n;
vector<int>c;
vector<string>v;

LL dp[nmax][3];

LL solve(int pos,int prev_flip)
{
    if(pos==n) return 0;

    LL &ret = dp[pos][prev_flip];
    if(ret != -1) return ret;

    string prev_s = pos == 0 ? "-1" : v[pos-1];
    if(prev_flip) reverse(ALL(prev_s));

    string now1 = v[pos];
    string now2 = now1;
    reverse(ALL(now2));

    LL way1  = INF , way2 = INF;

    if(now1>=prev_s) way1 = solve(pos+1,0);
    if(now2>=prev_s) way2 = c[pos] + solve(pos+1,1);

    return ret = min(way1,way2);
}

int main()
{
    optimizeIO();

    cin>>n;

    c = vector<int>(n);
    v = vector<string>(n);

    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++) cin>>v[i];

    memset(dp,-1,sizeof dp);
    LL ans = solve(0,0);

    if(ans>=INF) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}

/**

3
1 5 3
aa
ba
ac

2
3 4
ba
ac

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


