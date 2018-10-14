
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

#define gamma 0.57721566490

double sumAra[1000010];

int main()
{
    double LIM = 1000000;

    sumAra[1]=1;
    double sum = 1.0;

    for(int i=2;i<=LIM;i++)
    {
        sum += (1.0/(double)i);

        sumAra[i] = sum;

    }

    int tc;
    SI(tc);

    double ans;

    fr(i,1,tc)
    {
        int n;
        SI(n);

        if(n<=(int)LIM)
        {
            ans = sumAra[n];
        }

        else
        {
            ans = log(n+0.5)+gamma;

        }

        printf("Case %d: %.10lf\n",i,ans);

    }

    return 0;
}
