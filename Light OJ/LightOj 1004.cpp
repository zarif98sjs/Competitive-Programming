
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define LPII pair<LL, pair<int,int> >
#define MP make_pair
#define F first
#define S second
#define LINF LLONG_MAX

LL ara[300][150];
LL dp[300][150];

void init()
{
    memset(ara,0,sizeof ara);
    memset(dp,0,sizeof dp);
}

int main()
{
    //freopen("LightOj1099.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        init();

        int n;
        scanf("%d",&n);

        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                scanf("%lld",&ara[i][j]);


        for(int i=n+1,k=n-1;i<=2*n-1;i++,k--)
            for(int j=1;j<=k;j++)
                scanf("%lld",&ara[i][j]);

//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=i;j++)
//                printf("%lld ",ara[i][j]);
//
//            printf("\n");
//
//        }
//
//        for(int i=n+1,k=n-1;i<=2*n-1;i++,k--)
//        {
//            for(int j=1;j<=k;j++)
//                printf("%lld ",ara[i][j]);
//
//            printf("\n");
//        }

        dp[1][1]=ara[1][1];

        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
            {
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+ara[i+1][j]);
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+ara[i+1][j+1]);
            }

        for(int i=n+1,k=n-1;i<=2*n-1;i++,k--)
            for(int j=1;j<=k;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+ara[i][j];
            }


            printf("Case %d: %lld\n",i,dp[2*n-1][1]);

    }

    return 0;
}


