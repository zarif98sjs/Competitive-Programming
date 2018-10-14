
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x1,x2,x3,y1,y2,y3;
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);

        int area =  abs( (x1*y2)+(x2*y3)+(x3*y1)-(x2*y1)-(x3*y2)-(x1*y3));

        printf("Case %d: %d %d %d\n",i,x1+x3-x2,y1+y3-y2,area);

    }

    return 0;
}
