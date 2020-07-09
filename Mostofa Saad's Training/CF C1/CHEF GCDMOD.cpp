
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

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
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

long long prod(long long a, long long b, long long m)
{
    long long res = 0;

    while(b)
    {
        if(b & 1)
            res = (res + a) % m;
        a = (a + a) % m;

        b >>= 1;
    }

    return res;
}

//LL bigMod_iter(LL b, LL p, LL m ) /// Faster than recursive one
//{
//    LL res = 1 % m, x = b % m;
//    while ( p )
//    {
//        if ( p & 1 )
//            res = prod(res,x,m);
//        x = prod(x,x,m);
//        p >>= 1;
//    }
//    return res;
//}

template <class T>
T bigMod_iter(T b, T p, T m ) /// Faster than recursive one
{
    T res = 1 % m, x = b % m;
    while ( p )
    {
        if ( p & 1 )
            res = ( (__int128)res * x ) % m;
        x = ( (__int128)x * x ) % m;
        p >>= 1;
    }
    return res;
}
LL mod = 1e9+7;

LL solve(LL a,LL b,LL n)
{
    if(a==b)
    {
        return (bigMod_iter(a,n,mod) + bigMod_iter(b,n,mod))%mod;
    }

//    LL mx = max(a,b);
//    LL mn = min(a,b);
//    a = mx  , b = mn;

    LL val = (bigMod_iter(a,n,a-b) + bigMod_iter(b,n,a-b))%(a-b);

    return __gcd(val,a-b);
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        LL a,b,n;
        cin>>a>>b>>n;

        cout<<solve(a,b,n)<<endl;
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


