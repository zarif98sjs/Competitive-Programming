
/**

TAG : BINARY SEARCH
===================

The target is to minimize the maximum capacity.
Binary search over capacity 'd'
If possible with capacity 'd' , minimize and if not maximize using binary search .

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

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e3+7;
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
int n,k;

bool isPossible(int d)
{
    int sum = 0;
    int cnt = 0;

    for(int i=1; i<=n; i++)
    {
        if(d<ara[i])
            return false;

        if(sum+ara[i]<=d)
            sum += ara[i];
        else
            cnt++, sum = ara[i];
    }

    cnt++;
    return cnt<=k;
}

int main()
{
    //freopen("out.txt","w",stdout);

    //optimizeIO();

    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        scanf("%d %d",&n,&k);

        int cnt = 0;

        for(int i=1; i<=n; i++)
            scanf("%d",&ara[i]);

        int lo = 0, hi = INT_MAX , mid = 0;

        int ans = lo;

        while(lo<hi)
        {
            mid = lo + (hi-lo)/2;

            //DBG(lo) , DBG(hi) , DBG(mid);

            if(isPossible(mid))
                hi = mid, ans = mid;
            else
                lo = mid+1;
        }

        printf("Case %d: %d\n",q,ans);

    }


    return 0;
}

/**

2

5 3

1 2 3 4 5

3 2

4 78 9

**/
