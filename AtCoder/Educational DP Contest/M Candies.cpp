
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

const int nmax = 1e5+7;
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

LL dp[nmax];
const LL mod = 1e9+7;

void add_self(LL &a,LL b)
{
    a+=b;
    if(a>=mod) a -= mod;
}

void sub_self(LL &a,LL b)
{
    a-=b;
    if(a<0) a += mod;
}

int main()
{
    optimizeIO();

    int n, k;
    cin>>n>>k;

    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    /**

    Time Complexity : O(n*k^2)
    Space Complexity : O(n*k)

    dp[i][j] = number of ways of distributing j Candies among first i people

    dp[0][0] = 1;

    for(int i=0;i<n;i++)
    {
        for(int c=0;c<=k;c++)
        {
            for(int now=0;now<=v[i];now++)
            {
                if(c+now<=k) add_self(dp[i+1][c+now],dp[i][c]);
            }
        }
    }

    cout<<dp[n][k]<<endl;

    **/

    /**

    We can reduce the Space Complexity as i+1 th one only depend on i

    Time Complexity : O(n*k^2)
    Space Complexity : O(k)

    dp[j] = number of ways of distributing j Candies

    dp[0] = 1;

    for(int i=0;i<n;i++)
    {
        for(int c=k;c>=0;c--)
        {
            for(int now=1;now<=min(v[i],k-c);now++) /// c+now<=k ==> now<=k-c
            {
                add_self(dp[c+now],dp[c]);
            }
        }
    }

    cout<<dp[k]<<endl;

    **/


    /**

    We can reduce the Time Complexity as in the last loop we are basically doing Range Update .
    We can do that either using a BIT / Segment Tree . Or we can use the idea of prefix sum.

    Time Complexity : O(n*k)
    Space Complexity : O(k)

    **/

    dp[0] = 1;

    for(int i=0;i<n;i++)
    {
        vector<LL>dummy(k+1,0);

        for(int c=k;c>=0;c--)
        {
            int L = c+1;
            int R = c+min(v[i],k-c);

            if(L<=R)
            {
                add_self(dummy[L],dp[c]);
                if(R+1<=k) sub_self(dummy[R+1],dp[c]);
            }
        }

        for(int j=1;j<=k;j++)
            add_self(dummy[j],dummy[j-1]);

        for(int j=0;j<=k;j++)
            add_self(dp[j],dummy[j]);
    }

    cout<<dp[k]<<endl;


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


