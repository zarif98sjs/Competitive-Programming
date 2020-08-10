
/**

Idea
----
From value x , we can go to x-a1 , x-a2 , ... x-an states.

If any one of them is a losing state for the first mover , than that is a win for him as he can give the move to Second mover and
he has no other option than losing .

Base case
---------
if(k<min) : Lose
if(k = ai) : Win // not necessary as from this state we can still go on to do the normal of removing ai

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

vector<int>v;
int n,mn;
unordered_map<int,bool>dp;

bool solve(int k)
{
//    assert(k>=0);

    if(k<mn) return false;

//    if(binary_search(ALL(v),k)) return true;

    if(dp.count(k))
        return dp[k];

    bool ok = false;

    for(int i=0; i<n; i++)
    {
        if(v[i]>k)
            break;

        if(solve(k-v[i])==false)
        {
            ok = true;
            break;
        }
    }

    return dp[k] = ok;
}

int main()
{
    optimizeIO();

//    WRITE;

    int k;
    cin>>n>>k;

    mn = INT_MAX;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
        mn = min(mn,v[i]);
    }

    sort(ALL(v));

    if(solve(k))
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;

    return 0;
}

/**
1 4
3

2 4
2 3

2 5
2 3

2 7
2 3

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



