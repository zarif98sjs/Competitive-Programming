
/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define pi       acos(-1)

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

double sumara[1000010];

void precalculate()
{

    for(int i=1; i<=1000000; i++)
    {
        double x = log10(i);

        sumara[i]=sumara[i-1]+x;

    }

    return;
}


int main()
{
    precalculate();

    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        int num,base;
        SI(num),SI(base);

        double beforeAns = (sumara[num])/(log10(base));

        int ans = (int)beforeAns+1;

        printf("Case %d: %d\n",i,ans);

    }

    return 0;
}

