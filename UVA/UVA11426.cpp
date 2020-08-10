
/**

Problem : UVA 11426 GCD - Extreme (II)
Tag : Number Theory , GCD
--------------------------------------

Idea
====

Let N = 4

S = g(1,2) + g(1,3) + g(1,4) +
    g(2,3) + g(2,4) +
    g(3,4)

  = g(1,4) + g(2,4) + g(3,4) +
    g(1,3) + g(2,3) +
    g(1,2)

  = For(ALL i = 2 to N) SUM g(j,i) [j = 1 to N-1]

Now , What are the possible values of gcd(i,n) where i = 1 to n-1
The possible values are the divisors of n which are less than n i.e [d|n && d<n]
Now how many cases are there such that gcd(i,n) = d ?

    gcd(i,n) = d
==> gcd(i,n/d) = 1 [as d divides n]

So , the answer is phi(n/d)

So , S = For(ALL i = 2 to N) SUM d * phi(n/d)     [d|i && d<i]
==>  S = For(ALL i = 2 to N) SUM n/d * phi(d)     [as d|n , n/d is also a divisor , and for the change the condition is d>1]

Now , we can precalculate to get our ans

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

const int nmax = 4e6+7;
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

LL phi[nmax];
LL temp[nmax];

void eulerPhi_for_upto_n_modified(LL n)
{
    for (LL i=1; i<=n; i++)
        phi[i] = i;

    for (LL p=2; p<=n; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p-1;

            for (LL i = 2*p; i<=n; i += p)
               phi[i] = (phi[i]/p) * (p-1);
        }
    }

    for(LL i=2;i<=n;i++)
        for(LL j=i;j<=n;j+=i)
            temp[j] += (j*phi[i])/i;

//    // Print precomputed phi values
//    for (int i=1; i<=n; i++)
//      cout << "Totient of " << i << " is "
//           << phi[i] << endl;
}

LL sum[nmax];

void precalc(LL n)
{
    sum[1] = 0;
    for(LL i=2;i<=n;i++)
        sum[i] = sum[i-1] + temp[i];
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    eulerPhi_for_upto_n_modified(4e6);
    precalc(4e6);

    while(1)
    {
        LL n;
        cin>>n;

        if(n==0) break;

        cout<<sum[i]<<endl;
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


