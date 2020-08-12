
/**

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

const int nmax = 1e6+7;
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

    //optimizeIO();

    eulerPhi_for_upto_n_modified(1e6);
    precalc(1e6);

    while(1)
    {
        LL n;
        scanf("%lld",&n);

        if(n==0) break;

        printf("%lld\n",sum[n]);
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


