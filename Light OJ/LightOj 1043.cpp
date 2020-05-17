
/**

Topic : Geometry
================

AB/AD = AC/AE = BC/DE

We know that , If two triangles are similar, then the ratio of the area of both triangles is proportional
to the square of the ratio of their corresponding sides.

So , Area(ABC)/Area(ADE) = (AB/AD)^2 = (AC/AE)^2 = (BC/DE)^2

**/

/** Which of the favors of your Lord will you deny ?* */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        double ab,bc,ac,x;
        scanf("%lf %lf %lf %lf",&ab,&ac,&bc,&x);

        double k = sqrt((1+x)/x);

        printf("Case %d: %.10lf\n",i,ab/k);

    }

    return 0;
}
