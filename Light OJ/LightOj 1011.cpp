
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

int n;

LL ara[16][16];
LL dp[16][1<<16];
//bool visited[30];

void init()
{
    memset(ara,0,sizeof ara);
    memset(dp,(LL)-1,sizeof dp);
    //memset(visited,0,sizeof visited);
}

LL solve(int r,int mask)
{
    if(r>=n)
        return 0;
    if(dp[r][mask]==-1)
    {
        for(int i=0; i<n; i++) // i means col
        {
            if(!(mask&(1<<i)))
                dp[r][mask]=max(dp[r][mask],ara[r][i]+solve(r+1,mask | (1<<i)));
        }
    }
    //else
    return dp[r][mask];

}

int main()
{
    //freopen("LightOj1011.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        init();


        scanf("%d",&n);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%lld",&ara[i][j]);



        LL ans=solve(0,0);

//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<(1<<n); j++)
//                printf("%lld ",dp[i][j]);
//
//            printf("\n");
//
//        }
//

        printf("Case %d: %lld\n",q,ans);


    }

    return 0;
}
