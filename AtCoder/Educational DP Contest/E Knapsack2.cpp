
/**

------------------------------------------

Doing it like Knapsack 1 will get you TLE

as minimum W states = (2^100,1e9)

------------------------------------------

Now , as v <= 10^3 and n <= 100
maximum answer V = 10^5

So , we can come up with a different dp like this,
dp(i,V) = minimum weight needed to make EXACTLY V value is used if i items are available .

See , commented code for dp transition

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
const int INF = 1e9;
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

LL solve(int pos,int V) /** minimum W required if exactly V is used **/
{
    if(V<0) return LINF; /** if anytime V<0 , not possible **/

    if(pos==0) /** Done with n items **/
    {
        if(V==0) return 0; /** V=0 means , used exactly V , OK . return 0 **/
        return LINF; /** V>0 after done with n items , not possible **/
    }

    LL &ret = dp[pos][V];
    if(ret!=-1)
        return ret;

    LL inc = solve(pos-1,V-v[pos]) + w[pos];
    LL exc = solve(pos-1,V);

    return ret = min(inc,exc);
}

int main()
{
    optimizeIO();

    int n,W;
    cin>>n>>W;

    for(int i=1; i<=n; i++)
        cin>>w[i]>>v[i];

    int V = 0;
    for(int i=1; i<=n; i++)
        V += v[i];

    memset(dp,-1,sizeof dp);

    int ans = 0;

    for(int j=1;j<=V;j++)
        if(solve(n,j)<=W) /** minimum weight W required if exactly V is used if n items are available  **/
            ans = max(ans,j);

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


