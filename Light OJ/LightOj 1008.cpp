
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
        int row,col;
        LL num;
        SLL(num);
        double a = ceil(sqrt(num));
        int x = (int) a;

        int d = num - (x-1)*(x-1);

        if(x%2==1)
        {
            if(d<=x)
                row = d , col = x;

            else // d>x
                row = x , col = 2*x-d;
        }

        else //if(x%2==0)
        {
            if(d<=x)
                col = d , row = x;

            else // d>x
                col = x , row = 2*x-d;
        }

        printf("Case %d: %d %d\n",i,col,row);

    }

    return 0;
}
