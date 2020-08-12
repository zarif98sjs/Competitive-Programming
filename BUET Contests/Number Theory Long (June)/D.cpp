
/**

Problem : LightOj 1054
Tag : Number Theory , Divisors , Prime Factorization
----------------------------------------------------

Idea
====

Prime Factorization | Geometric Progression

- Sum of Divisors of n can be calculated using Prime Factorization .
- If n = p0^q0 + p1^q1 + ...  + pn^qn , Sum of Divisor = (p0^0 + p0^1 + ... + p0^q0) * ... (pn^0 + pn^1 + ... + pn^qn)
- For a geometric progression , if first term is a and ration is r ,
  Sum of n terms , Sn = (a * (r^n - 1) ) / (r-1)

- For n^m , prime factorization will be n = p0^(q0*m) + p1^(q1*m) + ...  + pn^(qn*m)
- Rest of the implementation is trivial

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

LL nt,mt;
LL mod = 1e9+7;

LL LIM;
const int nmax_bit = 1e5+7;
bitset<nmax_bit> bs;
vector<LL> primes;

LL bigMod(LL x,LL n,LL mo)
{
    if(n==0)
        return 1;

    LL u = bigMod(x,n/2,mo);
    u = ((u%mo)*(u%mo))%mo;

    if(n%2==1)
        u = ((u%mo)*(x%mo))%mo;

    return u;
}

// ax + by = GCD(a,b)
// r2 is GCD(a,b) and X & Y will be the co-eff of a and b respectively
LL ext_gcd (LL A, LL B, LL &X, LL &Y )
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
LL modInv_general ( LL a, LL m ) {
    LL x, y;
    ext_gcd( a, m, x, y );

    // Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

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
            primes.push_back(i);
        }
}


LL sum_of_Divisors_modified(LL N) //SOD
{
    LL res = 1;
    LL sqrtn = sqrtl (N);
    for ( LL i = 0; i < primes.size() && primes[i] <= sqrtn; i++ )
    {
        if ( N % primes[i] == 0 )
        {
            LL power = 0;
            while ( N % primes[i] == 0 )
            {
                N /= primes[i];
                power++;
            }
            sqrtn = sqrtl ( N );

            power *= mt;
            power++;

            LL up = (bigMod(primes[i],power,mod) - 1 + mod)%mod;
            LL down = modInv_general(primes[i]-1,mod);

            res = (res%mod * up%mod)%mod;
            res = (res%mod * down%mod)%mod;
        }
    }
    if ( N != 1 ) // Need to multiply (p^0+p^1)
    {
        LL po = mt+1;

        LL up = (bigMod(N,po,mod) - 1 + mod)%mod;
        LL down = modInv_general(N-1,mod);

        res = (res%mod * up%mod)%mod;
        res = (res%mod * down%mod)%mod;
    }
    return res;
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    LL upto = 50000; /** sqrt(2^31) ~ 50k **/
    bit_sieve(upto);

    int tc;
    cin>>tc;

    for(int q=1;q<=tc;q++)
    {
        cin>>nt>>mt;

        LL ans = sum_of_Divisors_modified(nt);

        cout<<"Case "<<q<<": "<<ans<<endl;

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


