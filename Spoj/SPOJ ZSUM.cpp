
/**Which of the favors of your Lord will you deny ?**/

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

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;



/*

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

LL gcd( LL a, LL b )
{
    while ( b )
    {
        a = a % b;
        swap ( a, b );
    }
    return a;
}

LL po(LL x,LL n) /// x^n
{
    LL res = 1;

    while(n>0)
    {
        if(n&1)
            res = res*x;

        x = x*x;
        n >>= 1;
    }

    return res;
}

LL bigMod(LL x,LL n,LL mo) /// x^n % mo
{
    x %= mo;

    LL res = 1;

    while(n>0)
    {
        if(n&1)
            res = ((res%mo)*(x%mo)) % mo;

        x = ((x%mo)*(x%mo)) %mo;
        n >>= 1;
    }

    return res;

}

/**
ax + by = GCD(a,b)
r2 is GCD(a,b) and X & Y will be the co-eff of a and b respectively
**/
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

/**
when inverse of a (w.r.to mo) && mo is not prime
**/
LL modInv_general ( LL a, LL m ) {
    LL x, y;
    ext_gcd( a, m, x, y );

    // Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

/*--------------------------Template Ends---------------------------------*/

const int nmax = 2e5+7;
const LL LINF = 1e17;
const int MOD = 1e7+7;

int main()
{
    optimizeIO();

    int n,k;

    while(cin>>n>>k)
    {
        if(n==0 && k==0)break;

        LL ans = bigMod(n,k,MOD) + 2*bigMod(n-1,k,MOD);
        ans %= MOD;
        ans += bigMod(n,n,MOD) + 2*bigMod(n-1,n-1,MOD);
        ans %= MOD;

        cout<<ans<<endl;
    }

    return 0;
}
