
/**

EDITORIAL
---------

https://codeforces.com/blog/entry/71995

One update:

e[i] = p[i]*(1+e[i+1]) + (1-p[i])*(1+e[1])
/// Prob the ith mirror will say beautiful * (1 day delay + expectation value of the same happening in i+1th mirror)
    + Prob the ith mirror will NOT say beautiful * (1 day delay + expectation value from the start again)
=> e[i] = 1 + p[i]*e[i+1] + (1-p[i])*e[1]

OUR answer is e[1]

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

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

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

// ax + by = GCD(a,b)
// r2 is GCD(a,b) and X & Y will be the co-eff of a and b respectively
LL ext_gcd ( LL A, LL B, LL &X, LL &Y )
{
    LL x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1;
    y2 = 0;
    x1 = 0;
    y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y )
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    X = x2;
    Y = y2;
    return r2;
}

//when inverse of a (w.r.to mo) && mo is not prime
LL modInv_general ( LL a, LL m )
{
    LL x, y;
    ext_gcd( a, m, x, y );

    // Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 )
        x += m;
    return x;
}

LL p[nmax];

LL mod = 998244353;

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>p[i], p[i] = (p[i] * modInv_general(100,mod))%mod;

    LL up = 1;
    LL down = 1;

    LL t = 1;

    for(int i=1; i<=n; i++)
    {
        t = (t*p[i])%mod;

        if(i!=n) up = (up+t)%mod;
    }

    down = t;

    LL ans = (up* modInv_general(down,mod))%mod;

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


