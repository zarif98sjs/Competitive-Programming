
/**

TAG : BINARY SEARCH
===================

Say, each day you walk D distance. It is very easy to understand that, if you have enough large D,
it is always possible to cover start to end with K stops.

If you know D, you can check if it is possible to pass with K stops, if it is possible, may be it will also be possible
for a lower D. On the other hand, if it is not yet possible, you must walk more time in a day.

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

//    cout<<d<<" : "<<cnt<<endl;
    cnt++;

    return cnt<=k;
}

void printAns(int d)
{
    int sum = 0;
    int cnt = 0;

    for(int i=1; i<=n; i++)
    {
        if(sum+ara[i]<=d)
            sum += ara[i];
        else
        {
//            cout<<sum<<endl;
            printf("%d\n",sum);
            cnt++;
            sum = ara[i];
        }

        if(n-i+1==k-cnt) /** remaining num. of elements including this == the extra i need **/
        {
            printf("%d\n",sum);

            for(int j=i+1;j<=n;j++)
                printf("%d\n",ara[j]);

            break;
        }
    }
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
        n++, k++;

        int lo = 0, hi = 0, mid = 0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ara[i]);

            lo = max(lo,ara[i]);
            hi += ara[i];
        }

        int ans = lo;

        while(lo<hi)
        {
            mid = (lo+hi)/2;

            //DBG(lo) , DBG(hi) , DBG(mid);

            if(isPossible(mid))
                hi = mid, ans = mid;
            else
                lo = mid+1;
        }

//        cout<<"Case "<<q<<": "<<ans<<endl;
        printf("Case %d: %d\n",q,ans);

        printAns(ans);

    }


    return 0;
}

/**

1
6 4
10
5
5
5
5
5
5

**/
