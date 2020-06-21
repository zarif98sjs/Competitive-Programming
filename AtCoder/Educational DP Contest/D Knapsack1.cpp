
/**

F(i,W) = max( include ith item , exclude ith item )

Here ,
include ith item = F(i-1,W-w[i]) + v[i]
exclude ith item = F(i-1,W)

Base case:

F(i,W<0)     = INT_MIN
F(i<=0,W==0) = 0

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

const int nmax = 1e2+7;
const int nmax2 = 1e5+7;
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

LL w[nmax];
LL v[nmax];

LL dp[nmax][nmax2];

LL solve(int pos,int W) /** maximum value to get using maximum weight W **/
{
    if(W<0) return INT_MIN; /** if anytime W<0 , not possible **/
    if(W==0) return 0; /** if anytime W=0 , OK . return 0 **/

    if(pos==0 && W>0) return 0; /** Done with n items , still W left , OK . return 0 **/

    LL &ret = dp[pos][W];
    if(ret!=-1) return ret;

    LL inc = solve(pos-1,W-w[pos]) + v[pos];
    LL exc = solve(pos-1,W);

    return ret = max(inc,exc);
}

int main()
{
    optimizeIO();

    int n,W;
    cin>>n>>W;

    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];

    memset(dp,-1,sizeof dp);

    cout<<solve(n,W)<<endl;

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


