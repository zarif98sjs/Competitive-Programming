
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

vector<LL>cnt(3);
vector<LL>now(3);
vector<LL>cost(3);

LL f(LL x)
{
    LL val = 0;

    for(int i=0;i<3;i++)
        val += max(0LL,x*cnt[i]-now[i]) * cost[i];

    return val;
}

LL binarySearch(LL lo,LL hi,LL key)
{
    LL ans = 0;

    while(lo<=hi)
    {
        LL mid = lo + (hi-lo)/2;

        if(f(mid)<=key) lo = mid + 1 , ans = mid;
        else hi = mid - 1;
    }

    return ans;

}

int main()
{
    optimizeIO();

    string s;
    cin>>s;

    for(char ch:s)
    {
        if(ch=='B') cnt[0]++;
        if(ch=='S') cnt[1]++;
        if(ch=='C') cnt[2]++;
    }

    for(int i=0;i<3;i++) cin>>now[i];
    for(int i=0;i<3;i++) cin>>cost[i];

    LL taka;
    cin>>taka;

    cout<<binarySearch(1,1e15,taka)<<endl;

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


