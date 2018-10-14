
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

double durotto(double a1,double b1,double c1,double a2,double b2,double c2)
{
    double ans_square = (a2-a1)*(a2-a1)+(b2-b1)*(b2-b1)+(c2-c1)*(c2-c1);

    return sqrt(ans_square);
}

int main()
{
    //freopen("outI.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    double ax,ay,az,bx,by,bz,px,py,pz;

    for(int i=1;i<=tc;i++)
    {
        double ans=0,baad_jabe;

        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",&ax,&ay,&az,&bx,&by,&bz,&px,&py,&pz);

        double lox = ax,loy=ay,loz=az;
        double hix = bx,hiy=by,hiz=bz;

        for(int it=1;it<=1000;it++)
        {
            double mid1x = (2*lox+hix)/3.0,mid1y = (2*loy+hiy)/3.0,mid1z = (2*loz+hiz)/3.0;
            double mid2x = (lox+2*hix)/3.0,mid2y = (loy+2*hiy)/3.0,mid2z = (loz+2*hiz)/3.0;

            if(durotto(mid1x,mid1y,mid1z,px,py,pz)>durotto(mid2x,mid2y,mid2z,px,py,pz))
                lox=mid1x,loy=mid1y,loz=mid1z;
            else
                hix=mid2x,hiy=mid2y,hiz=mid2z;

        }

        ans = durotto(lox,loy,loz,px,py,pz);

        printf("Case %d: %.10lf\n",i,ans);
    }



    return 0;
}
