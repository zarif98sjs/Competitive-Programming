
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

int cnt[1000010];

int main()
{
    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        fill(cnt,cnt+1000000,0);

        int n, hi=-1;
        SI(n);

        fr(j,1,n)
        {
            int num;
            SI(num);
            cnt[num]++;

            if(num>hi)
                hi=num;
        }

        LL ans=0;

        fr(j,0,hi)
        {
            if(cnt[j]>0)
            {
                //cout<<j<<" ** "<<cnt[j]<<" "<<((cnt[j]+j)/(j+1))*(j+1)<<endl;
                ans = ans + ((cnt[j]+j)/(j+1))*(j+1); // ceil[(cnt[j]/(j+1))]
            }
        }

        printf("Case %d: %lld\n",i,ans);

    }

    return 0;
}

