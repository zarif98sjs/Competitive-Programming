
/**

Problem : LightOJ 1095

Idea
====

Derangement

Derangement Idea : http://www.shafaetsplanet.com/planetcoding/?p=600

Implementation 1
-----------------

- Choose any k elements from first m elements.
- For i = 1 to n-m , Choose i elements from n-m elements and Derange the rest i.e n-i-k elements

Implementation 2
-----------------

- Use the 2nd idea of derangement given in the link
- Solution of pin3da using this idea : https://github.com/pin3da/Programming-contest/blob/master/solved/lightoj/1095%20-%20Arrange%20the%20Numbers/solution.cc

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

const int nmax = 1e3+7;
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

LL mod = 1000000007;
LL dpArrange[nmax][nmax];
LL dpDerange[nmax];

LL nCr(LL n,LL r)
{
    if(r==1) return n;
    if(r==0 || r==n) return 1;

    LL &ret = dpArrange[n][r];

    if(ret!=-1) return ret;

    ret = ((nCr(n-1,r-1)%mod) + (nCr(n-1,r)%mod))%mod;

    return ret;
}

LL Derange(LL n)
{
    if(n==1) return 0;
    if(n==2 || n==0) return 1;

    LL &ret = dpDerange[n];

    if(ret!=-1) return ret;

    ret = ((n-1)%mod * (Derange(n-1)%mod+Derange(n-2)%mod)%mod)%mod;

    return ret;
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    memset(dpArrange,-1,sizeof dpArrange);
    memset(dpDerange,-1,sizeof dpDerange);

    for(int qq=1; qq<=tc; qq++)
    {
        LL n,m,k;
        cin>>n>>m>>k;

        LL ans1 = nCr(m,k); /** Choose any k from first m elements **/
        LL ans2 = 0;

        for(LL i=0;i<=n-m;i++)
            ans2 = (ans2%mod + (nCr(n-m,i)%mod * Derange(n-i-k)%mod)%mod)%mod;    /** Choose i from n-m elements and Derange the rest i.e n-i-k elements **/

        LL ans = (ans1 * ans2)%mod;

        cout<<"Case "<<qq<<": "<<ans<<endl;

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


