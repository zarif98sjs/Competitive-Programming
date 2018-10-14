
/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define SI(n)    scanf("%d",&n)
#define SLL(n)   scanf("%lld",&n)
#define SC(n)    scanf("%c",&n)
#define SD(n)    scanf("%lld",&n)

#define fr(i,a,b) for(int i=a ,_b=(b) ;i<= _b;i++)

#define LL      long long
#define PUB     push_back
#define POB     pop_back
#define MP      make_pair;
#define PII     pair<int,int>
#define PLL     pair<ll,ll>

#define GCD     __gcd

int main()
{
    int t;
    SI(t);
    fr(i,1,t)
    {
        int m,n,ans;
        SI(m),SI(n);

        int d = m*n;

        if(m==1 || n==1)
            ans=d;

        else if(m==2 || n==2)
        {
            int x = max(m,n);

            if(x%4==0)
                ans = d/2;
            else if(x%4==1)
                ans = d/2+1;
            else if(x%4==2)
                ans = d/2+2;
            else
                ans = d/2+1;
        }

        else if(d%2==0)
        {
            ans=d/2;
        }

        else
        {
            ans=(d+(2-1))/2; //ceil
        }

        printf("Case %d: %d\n",i,ans);

    }

    return 0;
}
