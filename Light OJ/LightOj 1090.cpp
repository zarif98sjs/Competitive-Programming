
/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define SI(n)    scanf("%d",&n)
#define SLL(n)   scanf("%lld",&n)
#define SULL(n)   scanf("%llu",&n)
#define SC(n)    scanf("%c",&n)
#define SD(n)    scanf("%lf",&n)

#define fr(i,a,b) for(int i=a ,_b=(b) ;i<= _b;i++)

#define LL      long long
#define PUB     push_back
#define POB     pop_back
#define MP      make_pair;
#define PII     pair<int,int>
#define PLL     pair<ll,ll>

#define mset(x,v) memset(x,v,sizeof(x))
#define GCD     __gcd
#define DEBUG   cout<<"aw"<<endl;

int powa(int x, int y)
{
    int ans = x;

    for(int i=2; i<=y; i++)
    {
        ans = ans * x;
    }

    return ans;
}

int countFive(int num)
{
    int x = powa(5,1);

    int ans=0,i=2;
    while(num/x !=0)
    {
        ans=ans+(num/x);
        x = powa(5,i);
        i++;
    }

    return ans;

}

int countTwo(int num)
{
    int x = powa(2,1);

    int ans=0,i=2;

    while(num/x !=0)
    {
        ans=ans+(num/x);
        x = powa(2,i);
        i++;
    }

    return ans;

}

int main()
{
    //freopen("outLOJ1090","w",stdout);

    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        int n,r,p,q;
        SI(n),SI(r),SI(p),SI(q);

        int y = n-r;

        LL fiveAbove = countFive(n)-countFive(r)-countFive(y);
        LL fiveBeside = 0;
        LL twoBeside = 0;

        if(p%2==0)
        {
            int cnt = 0;

            while((p%2)==0)
            {
                p=p/2;
                cnt++;
            }

            twoBeside = cnt * q;
            //cout<<cnt<< "**"<<ans2<<endl;
        }

        if(p%5==0)
        {
            int cnt = 0;

            while((p%5)==0)
            {
                p=p/5;
                cnt++;
            }

            fiveBeside = cnt * q;
            //cout<<cnt<< "**"<<ans2<<endl;
        }

            //cout<<"##"<<twoBeside<<fiveBeside<<" "<<fiveAbove<<endl;

            LL uttor = fiveAbove + min(twoBeside,fiveBeside);

            //cout<<"*"<<uttor<<endl;

        int extraTwosAbove = (countTwo(n)-countFive(n))-(countTwo(r)-countFive(r))-(countTwo(y)-countFive(y));
        int extraFivesBeside = fiveBeside - twoBeside;
        int extraTwosBeside = twoBeside - fiveBeside;

        //cout<<"**"<<extraTwosAbove<<endl;

        if(extraFivesBeside>0)
        {
            if(extraTwosAbove>=0)
                uttor += min(extraTwosAbove,extraFivesBeside);
        }


        if(extraTwosBeside>0)
            extraTwosAbove += extraTwosBeside;

        if(extraTwosAbove<0)
            uttor += extraTwosAbove;

        printf("Case %d: %lld\n",i,uttor);

    }

    return 0;
}
