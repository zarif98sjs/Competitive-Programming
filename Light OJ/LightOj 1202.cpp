
/*Which of the favors of your Lord will you deny ?*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int n,a,b;
    scanf("%d",&n);

    for(int i = 1; i<=n ; i++)
    {
        long long r1,c1,r2,c2;
        scanf("%lld %lld %lld %lld",&r1,&c1,&r2,&c2);
        a= abs(r2-r1);
        b= abs(c2-c1);
        if(a==b)
            printf("Case %d: 1\n",i);
        else if(((r1+r2+c1+c2)%2) != 0 )
            printf("Case %d: impossible\n",i);
        else
            printf("Case %d: 2\n",i);

    }

    return 0;
}
