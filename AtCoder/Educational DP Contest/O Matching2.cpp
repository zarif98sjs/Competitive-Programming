
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

int match[25][25];

const LL mod = 1e9+7;

void add_self(LL &a,LL b)
{
    a += b;
    if(a>=mod) a -= mod;
}

LL dp[22][1<<22];
LL dp2[1<<22];
int n;

LL solve(int m,int mask)
{
    LL &ret = dp[m][mask];

    if(ret!=-1) return ret;

    if(m==n) return ret = (mask==(1<<n)-1); /// n pair is matched

    ret = 0;

    for(int w=0;w<n;w++)
    {
        if(match[m][w] && !(mask&(1<<w)))
            add_self(ret , solve(m+1,mask |(1<<w)));
    }

    return ret;
}

LL solve2(int mask) /// optimized
{
    LL &ret = dp2[mask];

    if(ret!=-1) return ret;

    int m = __builtin_popcount(mask);

    if(m==n) return ret = (mask==(1<<n)-1); /// n pair is matched

    ret = 0;

    for(int w=0;w<n;w++)
    {
        if(match[m][w] && !(mask&(1<<w)))
            add_self(ret ,solve2( mask |(1<<w)));
    }

    return ret;
}

int main()
{
    optimizeIO();

    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>match[i][j];

//    memset(dp,-1,sizeof dp);
    memset(dp2,-1,sizeof dp2);

    cout<<solve2(0)<<endl;

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


