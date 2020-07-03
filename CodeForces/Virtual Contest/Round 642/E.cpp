
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


/**

dp[i] = minimum cost such that last lit is ith lamp

**/

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,k;
        cin>>n>>k;

        vector<int>dp(n+1,0);
        vector<int>pre(n+1,0);

        string s;
        cin>>s;
        s = "0"+s;

        for(int i=1;i<=n;i++)
            pre[i] = pre[i-1] + s[i] - '0';

        for(int i=1;i<=n;i++)
        {
            int way1 = INT_MAX , way2 = INT_MAX;

            way1 = pre[i-1] ; /** i-k th one is not lit , so turn off all before ith lamp **/
            if(i-k>=1) way2 = dp[i-k] + (pre[i-1]-pre[i-k]) ; /** i-k th one is lit , so value of dp[i-k] + cost of turning all in range [i-k+1,i-1]**/

            dp[i] = min(way1,way2) + (s[i]!='1');
        }

        int ans = pre[n];

        for(int i=1;i<=n;i++)
            ans = min(ans, dp[i] + (pre[n]-pre[i])); /** [i+1,n] is off **/

        cout<<ans<<endl;

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


