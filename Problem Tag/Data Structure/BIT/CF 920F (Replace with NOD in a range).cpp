
/**

Data Structure : BIT

NOD = Number of Divisor

Notice that indices which have value 1 or 2 won’t change in the future.
Let’s keep a set of indices where value is greater than 2.
When REPLACE l r update is given, we will iterate over the indices in the set which are in the given range and update their values.
When a value becomes <= 2, remove this index from the set.
Also, we will maintain a BIT to efficiently answer the queries.
The editorial on CF says “At first let's notice that this function converges very quickly, for values up to 106 it's at most 6 steps.”
So, we won’t traverse each element in the set more than 6 times.

**/

/**Which of the favors of your Lord will you deny ?**/

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e6+7;
const int nmax2 = 2e5+7;
const LL LINF = 1e17;

string to_str(LL x)
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

/** Calculating Number of Divisors of a range O(MAXN * logMAXN) **/

int NOD[nmax];
void calc_number_of_divisors()
{
    for(int i=1;i<nmax;i++)
        for(int j=i;j<nmax;j+=i)
            NOD[j]++;
}

/** BIT / FENWICK TREE **/

LL BIT[nmax];
void update(int index,int val,int len)
{
    while(index<=len)
    {
        BIT[index] = BIT[index]+val;
        index += index&(-index);
    }
}

LL query(int index)
{
    LL sum=0;
    while(index>0)
    {
        sum = sum+BIT[index];
        index -= index&(-index);
    }
    return sum;
}

int main()
{
    optimizeIO();

    calc_number_of_divisors();

    int n,m;
    cin>>n>>m;

    set<int>st;

    for(int i=1;i<=n;i++)
    {
        cin>>ara[i];
        update(i,ara[i],n);
        if(ara[i]>2)st.insert(i);
    }

    for(int i=1;i<=m;i++)
    {
        int t, l , r;
        cin>>t>>l>>r;

        if(t==1)
        {
            auto it = st.lower_bound(l);

            while(it != st.end() && *it<=r)
            {
                update(*it,NOD[ara[*it]] - ara[*it],n);
                ara[*it] = NOD[ara[*it]];

                if(ara[*it]>2) it++;
                else it = st.erase(it); /** returns an iterator to the next element that follows **/
            }
        }
        else
        {
            cout<<query(r) - query(l-1)<<endl;
        }
    }

    return 0;
}
