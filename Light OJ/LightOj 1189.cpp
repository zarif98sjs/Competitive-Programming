
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int>
#define MP mkae_pair
#define LL long long

//pair<LL,int> ara[50];

LL dp[50];

LL facto(LL n)
{
    if(n==0)
        return 1;

    if(dp[n])
        return dp[n];
    else
        dp[n]=n*facto(n-1);

    return dp[n];
}

/*
void precalc()
{
    for(int i=1;i<=19;i++)
    {
        ara[i]=MP(dp[i],i);
    }

}*/

int main()
{
    //freopen("outLOJ1189.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    LL x=19;

    facto(x);
    dp[0]=1;

    vector<int>ans;

    for(int q=1; q<=tc; q++)
    {
        LL n;
        scanf("%lld",&n);

        ans.clear();

        LL val=n;

        for(int i=19; i>=0; i--)
        {
            if(dp[i]<=val)
            {


                //int k=0;

                //if(val%dp[i]==0)
                //  k=val/dp[i];

                //if(k==0)
                //{
                ans.push_back(i);
                val-=dp[i];

                //cout<<val<<" "<<dp[i]<<endl;
                //}


                /*while(k--)
                {
                    ans.push_back(i);
                    val-=dp[i];
                }*/

            }

            if(val<=0)
                break;

        }

        if(val!=0)
        {

            printf("Case %d: impossible",q);
            /*
                        int sz=ans.size();
                        for(int i=sz-1; i>=0; i--)
                        {
                            if(i==0)
                                printf("%d!",ans[i]);
                            else
                                printf("%d!+",ans[i]);
                        }*/
        }


        else
        {
            int sz=ans.size();

            printf("Case %d: ",q);

            for(int i=sz-1; i>=0; i--)
            {
                if(i==0)
                    printf("%d!",ans[i]);
                else
                    printf("%d!+",ans[i]);
            }

        }

        printf("\n");



    }



    return 0;
}
