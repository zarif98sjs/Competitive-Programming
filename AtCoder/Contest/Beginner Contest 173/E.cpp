
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
LL mod = 1e9+7;

/// ax + by = GCD(a,b)
/// r2 is GCD(a,b) and X & Y will be the co-eff of a and b respectively
template <class T>
T ext_gcd ( T A, T B, T &X, T &Y )
{
    T x2, y2, x1, y1, x, y, r2, r1, q, r;
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

template <class T>
T invMod_general(T a,T m) /// when inverse of a (w.r.to mo) && mo is not prime
{
    T x, y;
    ext_gcd( a, m, x, y );

    /// Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 )
        x += m;
    return x;
}

LL mul(LL a,LL b)
{
    a = (a+mod)%mod;
    b = (b+mod)%mod;

    return ((a%mod) * (b%mod))%mod;
}

//LL findSubarray(const vector<LL>&v, int n, int k)
//{
//	LL window_sum = 1;
//
//	LL mx = -1e18;
//
//	for (int i = 0; i < 2*n; i++)
//	{
//		window_sum = mul(window_sum,v[i]);
//
//		if (i + 1 >= k)
//		{
//			mx = max(mx,window_sum);
//
//			LL d = v[i + 1 - k];
//			LL invd = invMod_general(d,mod);
//			window_sum = mul(window_sum,invd);
//		}
//	}
//
//	return mx;
//}

LL findSubarray(vector<LL>&v, int n, int k)
{
    sort(ALL(v));

    LL product = 1;

    if (v[n - 1] == 0 && (k & 1))
        return 0;

    if (v[n - 1] <= 0 && (k & 1))
    {
        for (int i = n - 1; i >= n - k; i--)
            product = mul(product,v[i]);
        return product;
    }


    int i = 0;

    int j = n - 1;


    if (k & 1)
    {
        product = mul(product,v[j]);
        j--;
        k--;
    }

    k >>= 1;

    for (int itr = 0; itr < k; itr++)
    {

        LL left_product = v[i] * v[i + 1];
        LL right_product = v[j] * v[j - 1];

        if (left_product > right_product)
        {
            product = mul(product,left_product);
            i += 2;
        }
        else
        {
            product = mul(product,right_product);
            j -= 2;
        }
    }

    return product;
}

int main()
{
    optimizeIO();

    int n,k;
    cin>>n>>k;

    vector<LL>v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

//    sort(ALL(v));
//
//    for(int i=0;i<n;i++)
//        v.push_back(v[i]);

    LL ans = findSubarray(v,n,k);
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


