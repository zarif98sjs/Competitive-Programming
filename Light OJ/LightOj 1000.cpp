
/*Which of the favors of your Lord will you deny ?*/

#include <stdio.h>

int main()
{
    int n,i,a,b;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",i,a+b);
    }

    return 0;

}
