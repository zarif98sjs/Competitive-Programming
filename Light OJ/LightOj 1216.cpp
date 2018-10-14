
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)
    {
        double r1,r2,h,p;

        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);

        double y = h/(r1/r2-1);
        double x = r2*((p+y)/y);

        //printf("%lf %lf ",y,x);

        double Vbig =(1.0/3)*pi*x*x*(p+y);
        double Vsmall =(1.0/3)*pi*r2*r2*y;

        //printf("%lf %lf ",Vbig,Vsmall);

        double V = Vbig-Vsmall;

        printf("Case %d: %lf\n",i,V);

    }

    return 0;
}
