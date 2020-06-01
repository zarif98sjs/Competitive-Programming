
/**

Problem : LightOJ 1105

Idea
====

Zeckendorf representation | Fibonacci Number

- The Zeckendorf representation of an integer is the unique way of representing that integer as a sum of non-consecutive Fibonacci numbers.
- Every positive integer n has a Zeckendorf representation as a sum of non-consecutive Fibonacci numbers Fi
- For any given positive integer, a representation that satisfies the conditions of Zeckendorf's theorem can be found by using a greedy algorithm, choosing the largest possible Fibonacci number at each stage.

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

LL fib[nmax];
LL cnt = 0;

void precalc()
{
    fib[0] = 1;
    fib[1] = 1;

    for(LL i=2; ; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        cnt = i;

        if(fib[i]>1e9)
            break;
    }
}

string solve(LL n)
{
    vector<LL>ans;

    while(n)
    {
        LL id = upper_bound(fib+1,fib+cnt+1,n) - fib - 1; /** greedy , take the  current highest fibonacci number **/

        ans.push_back(id);
        n -= fib[id];
    }

    string temp = string(ans[0],'0');

    for(auto x:ans)
        temp[x-1] = '1';

    reverse(ALL(temp));

    return temp;
}


int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    precalc();

    int tc;
    cin>>tc;

    for(int qq=1; qq<=tc; qq++)
    {
        LL n;
        cin>>n;

        string ans = solve(n);

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


