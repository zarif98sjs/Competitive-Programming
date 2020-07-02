
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

const int nmax = 1e2+7;
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

int n,w,k;

int ara[nmax];
int dp[nmax][nmax];

int solve(int i,int baki)
{
    if(i==0||baki==0) return 0;

    int &ret = dp[i][baki];

    if(ret!=-1) return ret;

    int id2 =  lower_bound(ara+1,ara+n+1,ara[i]-w)-ara;
    int if_inc_add = i-id2+1;

    int inc = solve(id2-1,baki-1) + if_inc_add; /** id2-1 for 1 based indexing **/
    int exc = solve(i-1,baki);

    return ret = max(inc,exc);
}

int main()
{
//    freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    for(int qq=1;qq<=tc;qq++)
    {
        cin>>n>>w>>k;

        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            ara[i] = y;
        }

        sort(ara+1,ara+n+1);
        memset(dp,-1,sizeof dp);
        int ans = solve(n,k);
        cout<<"Case "<<qq<<": "<<ans<<endl;
//        cout<<endl;
    }

    return 0;
}
