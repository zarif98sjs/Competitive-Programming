
/**

Problem : LightOJ 1064

Idea
====

DP

- Solve the number of solution to : a1 + a2 + ..... + an >= target
- Ans is that divided by total num of outcome i.e 6^n

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
using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

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

const int nmax = 2e5+7;
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


LL n,target;
LL mx = 6;

LL dp[30][160];
LL po[30];

void precalc()
{
    po[0] = 1;

    for(LL i=1;i<=25;i++)
        po[i] = po[i-1] * 6LL;

}

LL solve(LL pos,LL sum) /** a1+a2+...an >=sum **/
{
    if(pos>n)
    {
        if(sum>=target) return 1;
        return 0;
    }

    LL &ret = dp[pos][sum];
    if(ret!=-1) return ret;

    ret = 0;
    for(int i=1;i<=mx;i++)
        ret += solve(pos+1,sum+i);

    return ret;
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
        cin>>n>>target;

        memset(dp,-1,sizeof dp);
        LL up = solve(1,0);
        LL down = po[n];

        LL gcd = __gcd(up,down);

        up /= gcd;
        down /= gcd;

        if(down!=1) cout<<"Case "<<qq<<": "<<up<<"/"<<down<<endl;
        else cout<<"Case "<<qq<<": "<<up<<endl;
    }

    return 0;
}

/**

7

3 9

1 7

24 24

15 76

24 143

23 81

7 38


**/


