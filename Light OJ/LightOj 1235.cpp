
/**

TAG : BINARY SEARCH | MEET IN THE MIDDLE
=========================================

The idea is that you split the large set into two small sets, small enough for you to handle them using the standard algorithm you know,
and then use the result from these two small sets to arrive at the required solution.

Note that , if we made 2 same vectors of n elements , and calculated subset sum by taking 0/1 times of the elements,
then that would get TLE as the Time Complexity will be : O(2^(n / 2) log (2^(n / 2)) [here , n = 2*18 = 36]


Here we calculated subset sum of n/2 elements by taking 0/1/2 times of the elements.
Complexity : O(3^(n / 2) log (3^(n / 2)) [here , n = 18]

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

const int nmax = 30+7;
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

void subsetSum(int i,const vector<LL> &v,LL s,vector<LL> &sum) /** Subset Sum taking 0/1/2 elements **/
{
    sum.push_back(s);

    if(i<v.size())
    {
        subsetSum(i+1,v,s,sum);
        subsetSum(i+1,v,s + v[i],sum);
        subsetSum(i+1,v,s + 2*v[i],sum);
    }
}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        int n;
        LL k;
        scanf("%d",&n);
        scanf("%lld",&k);

        vector<LL>v1,v2;

        for(int i=0;i<n;i++)
        {
            LL x;
            scanf("%lld",&x);

            if(i&1) v2.push_back(x);
            else v1.push_back(x);
        }

        vector<LL> subsetSum1 ,subsetSum2;

        subsetSum(0,v1,0,subsetSum1);
        subsetSum(0,v2,0,subsetSum2);

        sort(ALL(subsetSum2));

        bool hobe = false;

        for(LL s1:subsetSum1)
        {
            LL s2 = k - s1;
            if(binary_search(ALL(subsetSum2),s2))
            {
                hobe = true;
                break;
            }
        }

        printf("Case %d: ",q);
        if(hobe)printf("Yes\n");
        else printf("No\n");

    }


    return 0;
}

/**

3

2 5

1 2

2 10

1 2

3 10

1 3 5

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






