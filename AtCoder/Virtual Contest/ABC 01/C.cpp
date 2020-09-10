
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

#define int long long

const int nmax = 2e5+7;
const int mod = 1e9+7;

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

int32_t main()
{
    optimizeIO();

    int tc = 1;

    while(tc--)
    {
        int n;
        cin>>n;

        vector<int>v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];

        vector<int>cnt(n+1,0);

        bool ok = true;

        for(int i=1;i<=n;i++)
        {
//            if((n%2) == (v[i]%2))
//            {
//                ok = false;
//                continue;
//            }

            int x = (n-v[i]-1)/2;
            int y = (n+v[i]-1)/2;

            cnt[x+1]++;
            cnt[y+1]++;

        }

        for(int i=1;i<=n;i++) if(cnt[i]!=2) ok = false;

        if(ok) cout<<bm(2LL,n/2,mod)<<endl;
        else cout<<0<<endl;
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
