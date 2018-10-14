
/*Which of the favors of your Lord will you deny ?*/

#include<stdio.h>

int main()
{
    int i,n,a;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);

        int b=a/2;

        printf("%d %d\n",b,a-b);


    }

    return 0;

}
