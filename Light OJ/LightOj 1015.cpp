
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

int main()
{
    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        int n;
        SI(n);
        LL sum = 0;

        fr(j,1,n)
        {
            int a;
            SI(a);

            if(a>0)
                sum += a;
        }

        printf("Case %d: %lld\n",i,sum);

    }

    return 0;
}
