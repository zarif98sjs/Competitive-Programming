
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

const int nmax = 1e6+7;

template <class T>
T bm(T b, T p, T m ) /// Faster than recursive one
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

LL d[nmax];
LL ans[nmax];

LL mod = 1e9+7;

void pre()
{
    for(int i=0;i<nmax;i++)
        d[i] = (LL)i * bm(2LL,(LL)i,mod);

    ans[1] = 0;
    ans[2] = 0;

    for(int i=3;i<nmax;i++)
    {
        ans[i] = ((ans[i-1]%mod) * ((LL)i%mod))%mod;
        ans[i] = ((ans[i]%mod) + (d[i-2]%mod))%mod;

//        if(i<10)
//        {
//            DBG(ans[i]);
//            DBG(d[i-2]);
//        }

    }

}

int main()
{
    optimizeIO();

    pre();

    int tc = 1;
    while(tc--)
    {
        LL n;
        cin>>n;

        LL res = ans[n];

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


