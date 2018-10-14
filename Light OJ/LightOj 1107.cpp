
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)
    {
        int x1,y1,x2,y2,n;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&n);
        printf("Case %d:\n",i);

        for(int j=1;j<=n;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);

            if((a>x1)&&(a<x2)&&(b>y1)&&(b<y2)) printf("Yes\n");
            else printf("No\n");

        }

    }

    return 0;
}
