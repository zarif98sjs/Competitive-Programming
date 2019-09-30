#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL ara[10010];
LL dp[10010];
int n;

LL profit(int idx)
{
    if(idx>n)
        return 0;

    if(dp[idx]!=-1)
        return dp[idx];

    return dp[idx]=max(profit(idx+1),profit(idx+2)+ara[idx]);

}

int main()
{

    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&ara[i]);
            dp[i]=-1;
        }


        LL ans=profit(1);

        printf("Case %d: %lld\n",q,ans);

    }

    return 0;
}
