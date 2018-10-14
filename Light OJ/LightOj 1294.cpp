//  Sum of arithmetic progression
/*  Sn = (n/2)*(2*a+(n-1)*d)
    nth term = a+(n-1)*d;

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

int main()
{
    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        LL n,m;
        SLL(n),SLL(m);

        LL ans  = (n*m)/2;

        printf("Case %d: %lld\n",i,ans);
    }

    return 0;
}
