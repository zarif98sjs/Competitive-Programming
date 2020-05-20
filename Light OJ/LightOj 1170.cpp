
/**

TAG : BINARY SEARCH | CATALAN NUMBER
=====================================

If there are n prefect power numbers in [a,b] , Answer is basically Catalan(n)
Catalan(n) = (2n)! / (n! *(n+1)!)


Proof
=====

Consider all possible binary search trees with each element at the root.
If there are n nodes, then for each choice of root node, there are n – 1 non-root nodes and these non-root nodes must be partitioned into those that are less than a chosen root and those that are greater than the chosen root.
Let’s say node i is chosen to be the root. Then there are i – 1 nodes smaller than i and n – i nodes bigger than i. For each of these two sets of nodes, there is a certain number of possible subtrees.

Let T(n) be the total number of BSTs with n nodes. The total number of BSTs with i at the root is T(i – 1) * T(n – i). The two terms are multiplied together because the arrangements in the left and right subtrees are independent. That is, for each arrangement in the left tree and for each arrangement in the right tree, you get one BST with i at the root.
Summing over i gives the total number of binary search trees with n nodes.

T(n) = Summation(i = 1 to n) [T(i – 1) * T(n – i)]

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

const int nmax = 1e6+7;
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


set<LL>SET;
vector<LL>v;
LL facto[nmax];
LL mod = 100000007;

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
LL modInv_general ( LL a, LL m ) {
    LL x, y;
    ext_gcd( a, m, x, y );

    // Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

void precalc1()
{
    LL lim = 1e10;

    for(LL i=2; i*i<=lim; i++)
    {
        LL val = i;

        for(LL j=1; val<=lim; j++)
        {
            val *= i;

            if(!SET.count(val))
            {
                SET.insert(val);
                v.push_back(val);
            }
        }
    }
}

void precalc2()
{
    /** SET size is around 2e5 **/

    LL lim = 1e6;

    facto[0] = 1;

    for(LL i=1; i<=lim; i++)
    {
        facto[i]=((facto[i-1]%mod)*(i%mod))%mod; //(facto[i-1]*i)%m
    }
}

LL catalan(LL n)
{
    if(n==0)
        return 0;

    LL ans1 = facto[2*n];
    LL v1 = facto[n];
    LL v2 = facto[n+1];

    LL ans2 = modInv_general(v1,mod);
    LL ans3 = modInv_general(v2,mod);

    LL ans = (ans1*ans2)%mod;
    ans = (ans*ans3)%mod;

    return ans;
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    precalc1();
    precalc2();

    sort(ALL(v));

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        LL a,b;
        cin>>a>>b;

        LL ca = upper_bound(ALL(v),a-1)-v.begin();
        LL cb = upper_bound(ALL(v),b)-v.begin();

        LL n = cb-ca;

        LL ans = catalan(n);

        cout<<"Case "<<q<<": ";
        cout<<ans<<endl;
    }

    return 0;
}

/**

4

1 4

5 10

1 10

1 3

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


