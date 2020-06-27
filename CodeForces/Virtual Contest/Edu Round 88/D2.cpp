
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

const int nmax = 2e5+7;
const LL LINF = 1e17;
const int INF = 1e9;

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

int ara[nmax];
int dp[nmax][70];

/**

dp[i][j] = maximum value ending at ith index with max_sum = j

**/

int offset = 31;


int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>ara[i];

    for(int i=1; i<=n; i++)
        for(int j=0; j<=64; j++)
            dp[i][j] = -INF;

    for(int i=1; i<=n; i++)
    {
        int v = ara[i] + offset;
        dp[i][v] = 0;

        if(i>1)
        {
            for(int j=0; j<=v; j++)
                dp[i][v] = max(dp[i][v],dp[i-1][j] + j - offset);
        }

        for(int j=v+1; j<64; j++)
            dp[i][j] = max(dp[i][j],ara[i] + (i == 1 ? -INF : dp[i-1][j]));

    }

    int ans = 0;

    for(int i=1; i<=n; i++)
        for(int j=0; j<64; j++)
            ans = max(ans,dp[i][j]);

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


