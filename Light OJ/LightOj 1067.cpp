
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

LL facto[1000010];


LL factoMod(int n,int p) // n factorial mod p
{
    LL ans = 1;

    for(int i=n;i>1;i--)
    {
        ans = ans * (i%p);
        //cout<<"*"<<ans<<endl;
    }

    LL d =  (ans%p);
    //cout<<"##"<<d<<endl;

    return d;

}


int m = 1000003;

LL bigMod(int x,int n,int mo)
{
    if(n==0)
        return 1;

    LL u = bigMod(x,n/2,mo);
    u = (u*u)%mo;

    if(n%2==1)
        u = (u*x)%mo;

    //cout<<"@@"<<u<<endl;

    return u;
}

int modInverse(int a ,int mo)
{
    int uttor = bigMod(a,mo-2,mo);

    return uttor;
}

int main()
{
    facto[0]=1;

    for(LL j=1;j<=1000000;j++)
    {
        facto[j]=((facto[j-1]%m)*(j%m))%m; //(facto[j-1]*j)%m
    }

    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        int n,r;
        SI(n),SI(r);

        LL ans1 = facto[n];
        LL y1 = facto[n-r];
        LL y2 = facto[r];

        LL ans2 = modInverse(y1,m);
        LL ans3 = modInverse(y2,m);

        LL ans = (ans1 * ans2 * ans3)%m;

        //cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;

        printf("Case %d: %lld\n",i,ans);

    }

    return 0;
}
