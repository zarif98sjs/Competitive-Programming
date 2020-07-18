
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

LL LOG(LL b,LL p)
{
    LL cnt = 0;

    LL x = b;

    while(x<=p)
    {
        x = x*b;
        cnt++;
    }

    return cnt;
}

template <class T>
T po(T b, T p) /// Faster than recursive one
{
    T res = 1, x = b;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x );
        p >>= 1;
    }
    return res;
}

bool isPerfectSquare(LL x)
{
  // Find floating point value of
  // square root of x.
  long double sr = sqrtl(x);

  // If square root is an integer
  return ((sr - floor(sr)) == 0);
}

vector<LL> precalc(LL n)
{
    set<LL>s;

    for(LL i=2;i<=1e6;i++)
    {
        for(LL j=i*i*i; j<=n ;j*=i)
        {
            assert(j>=0);

            if(!isPerfectSquare(j)) s.insert(j);

            if(j>n/i) break;
        }
    }

    vector<LL>v;

    for(LL x:s)v.push_back(x);

    return v;
}

LL query(LL x,vector<LL> &v)
{
    LL up = upper_bound(ALL(v),x) - v.begin();

    LL perf_sq = sqrtl(x);

    return up+perf_sq;
}


int main()
{
    optimizeIO();

    vector<LL> v = precalc(1e18);

    int q;
    cin>>q;

    while(q--)
    {
        LL l,r;
        cin>>l>>r;

        LL ans = query(r,v) - query(l-1,v);
        cout<<ans<<endl;
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
