
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

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
const LL mod = 998244353;

template <class T>
T bigMod_iter(T b, T p, T m ) /// Faster than recursive one
{
    T res = 1 % m, x = b % m;
    while ( p )
    {
        if ( p & 1 )
            res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

int main()
{
    optimizeIO();

    int na,nb;
    cin>>na>>nb;

    string a,b;
    cin>>a>>b;

    reverse(ALL(a));
    reverse(ALL(b));

    vector<int>cnt;
    cnt.push_back(0);

    for(int i=0;i<nb;i++)
    {
        if(b[i]=='1') cnt.push_back(1);
        else cnt.push_back(0);
    }

    for(int i=1;i<(int)cnt.size();i++)
        cnt[i] += cnt[i-1];

    LL ans = 0;

    for(int i=0;i<na;i++)
    {
        if(a[i]=='0')
            continue;

        int l = i+1; /// 1 indexing
        int r = nb;  /// 1 indexing

        if(l>r)
            continue;

        LL val = (cnt[r] - cnt[l-1])%mod;

        LL add = (val * bigMod_iter(2LL,(LL)i,mod))%mod;

        ans = (ans%mod +  add%mod)%mod;
    }

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


