
/**

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

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

const int nmax = 5761460;
//const LL LINF = 1e17;

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

LL mod;

// Faster than recursive one
LL bigmod_iter (LL b, LL p, LL m )
{
    LL res = 1 % m, x = b % m;
    while ( p )
    {
        if ( p & 1 )
            res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

LL po (LL b, LL p)
{
    LL res = 1, x = b;
    while ( p )
    {
        if ( p & 1 )
            res = ( res * x );
        x = ( x * x );
        p >>= 1;
    }
    return res;
}

//LL lcm(LL a,LL b)
//{
//    LL g = __gcd(a,b);
//    LL inv = modInv_general(g,mod);
//
//    LL ans = (a%mod * b%mod)%mod;
//    ans = (ans%mod * inv%mod)%mod;
//
//    return ans;
//}


const int pnmax = 1e8+2;
LL LIM;
bitset<pnmax> bs;   // 10^7 should be enough for most cases
int primes[nmax];
int pCount = 0;

void bit_sieve(LL upperbound)
{
    LIM = upperbound + 1;
    bs.set();                                                 // set all bits to 1
    bs[0] = bs[1] = 0;
    for (LL i = 2; i <= LIM; i++)
        if (bs[i])
        {
            for (LL j = i * i; j <= LIM; j += i)
                bs[j] = 0;
            primes[pCount] = i;
            pCount++;
        }
}

LL logLL(LL base, LL x)
{

    LL cnt = 0;
    LL v = 1;
    while(1)
    {
        v = v*base;

        if(v>x)
            break;
        cnt++;
    }

    return cnt;
}

LL calc_upto_sqrt(LL n)
{
    LL ans = 1;
    for(LL i=0; (LL)primes[i]*(LL)primes[i]<=n; i++)
    {
        LL p = primes[i];
        LL v = logLL(p,n)-1;
//        DBG(p);
//            DBG(v);
        LL v2 = bigmod_iter(p,v,mod);
        ans = (ans%mod * v2%mod)%mod;
    }
    return ans;
}

unsigned int dp[nmax];

LL precalc()
{
    int sz = pCount;
//    DBG(sz);

    dp[0] = primes[0];

    for(int i=1; i<sz; i++)
    {
//        DBG(i);
        dp[i] = ((dp[i-1]%mod) * (primes[i]%mod))%mod;
    }

//
//    cout<<"done"<<endl;

}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    mod = po(2,32);

    bit_sieve(1e8);
    precalc();

//    int cc = 0;
//    for(auto x:final_primes)
//    {
//        cout<<++cc<<" : "<<x<<endl;
//    }

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        int n;
        cin>>n;

        LL v1 = calc_upto_sqrt((LL)n)%mod;
//        DBG(v1);
        int id = upper_bound(primes,primes+pCount,n) - primes - 1;
        LL v2 = dp[id]%mod;
//        DBG(v2);
        LL x1 = v1*v2;
        LL x2 = v1*v2;
//        DBG(x1);
//        DBG(x2);
        LL ans = ((v1%mod) * (v2%mod))%mod;

        cout<<"Case "<<q<<": ";
        cout<<ans%mod<<endl;

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

