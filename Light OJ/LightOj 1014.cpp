
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

unsigned LL powa(int x, int y)
{
    unsigned LL ans = x;

    for(int i=2; i<=y; i++)
    {
        ans = ans * x;
    }

    return ans;
}

int ara[1000000];

int main()
{
    //freopen("outLOJ1014","w",stdout);

    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        int p,l;
        SI(p),SI(l);

        int num = p-l, cnt=0,k=1;

        printf("Case %d:",i);

        for(int j=1; j<=sqrt(num); j++)
        {
            if(num%j==0)
            {
                if(j>l)
                {
                    //printf(" %d",j) , cnt++;
                    ara[k]=j;
                    k++;

                }

                if((num/j>l) && (j!=(num/j)))
                {
                    //printf(" %d",num/j) ,cnt++;
                    ara[k]=num/j;
                    k++;

                }
            }
        }

        k--;

        if(k==0) // k is count here
            printf(" impossible");

        else
        {
            sort(ara+1,ara+k+1);
            for(int q=1; q<=k; q++)
                printf(" %d",ara[q]);
        }

        printf("\n");

    }

    return 0;
}

