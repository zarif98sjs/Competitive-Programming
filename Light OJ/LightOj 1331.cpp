
/*Which of the favors of your Lord will you deny ?*/

#include<stdio.h>
#include<math.h>
double angle ( double a ,double b , double c)
{
    double A =(acos((b*b+c*c-a*a)/(2*b*c)));

    return (A);
}

int main()
{
    int n,i;

    scanf("%d",&n);

    for(i=1;i<=n;i++)

    {

    double th1,th2,th3,a,b,c,s,area,x,r1,r2,r3;

    scanf("%lf %lf %lf",&r1,&r2,&r3);

    th1=angle(r2+r3,r1+r2,r1+r3);
    th2=angle(r1+r3,r1+r2,r2+r3);
    th3=angle(r1+r2,r2+r3,r1+r3);

    a = r1+r2 ,  b = r2+r3 , c =  r3+r1;
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    x=area-.5*r1*r1*th1-.5*r2*r2*th2-.5*r3*r3*th3;

    printf("Case %d: %lf\n",i,x);

    }
return 0;
}
