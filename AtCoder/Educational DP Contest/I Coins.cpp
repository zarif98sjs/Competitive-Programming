
/**

Idea
----

Let dp(i,j) = Probability of getting i heads in first j coins

Now for the jth coin,

Option 1 : It is Head .
So , there must be i-1 heads in first j-1 coins i.e dp(i-1,j-1)

Option 2 : It is Tail .
So , there must be i heads in first j-1 coins i.e dp(i,j-1)

So , dp(i,j) = dp(i-1,j-1) * p(j) +dp(i,j-1) * (1-p(j))

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

const int nmax = 3e3+7;
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

double p[nmax];
double dp[nmax][nmax];

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>p[i];

    dp[0][0] = 1;

    for(int c=1;c<=n;c++)
    {
        for(int h=0;h<=n;h++)
        {
            double p1 = 0 , p2 = 0;

            if(h>0) p1 = dp[h-1][c-1] * p[c];
            p2 = dp[h][c-1] * (1-p[c]);

            dp[h][c] = p1 + p2;
        }
    }

    double ans = 0;

    for(int h=0;h<=n;h++)
    {
        int t = n-h;

        if(h>t)
            ans += dp[h][n];
    }

    cout << setprecision(9) << ans<<endl;;

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


