
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

#define GCD     __gcd
#define DEBUG   cout<<"aw"<<endl;

int abso(int x)
{
    if(x<0)
        return -1*x;

    return x;
}

int ara[50010];

int main()
{
    //freopen("outLOJ1016.txt","w",stdout);

    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        int n,width;
        SI(n),SI(width);

        fr(j,1,n)
        {
            int x,y;
            SI(x),SI(y);

            ara[j]=y;

        }

        sort(ara+1,ara+n+1);

        int q = ara[1] ,cnt=1;

        for(int k=2;k<=n;k++)
        {
            if(ara[k]-q>width)
            {
                cnt++;
                q = ara[k];
            }

        }

        printf("Case %d: %d\n",i,cnt);

    }

    return 0;
}
