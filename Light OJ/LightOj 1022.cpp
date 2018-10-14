
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
#define pi 2*acos(0.0)

using namespace std;


int main()
{
    int n;

    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {

        double r;
        scanf("%lf",&r);

        double area = r*r*(4-pi);

        printf("Case %d: %.2lf\n",i,area);
    }

return 0;
}
