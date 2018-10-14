
/*Which of the favors of your Lord will you deny ?*/

#include<stdio.h>
#include<math.h>
double distance (int x1 , int y1 , int x2 , int y2)
{

    double d = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));

    return(d);

}

int main()
{
    int ox,oy,ax,ay,bx,by,n,i;

    double oa,ab,ob,A,s;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {

    scanf("%d %d %d %d %d %d",&ox,&oy,&ax,&ay,&bx,&by);

    oa=distance(ox,oy,ax,ay);
    ab=distance(ax,ay,bx,by);
    ob=distance(ox,oy,bx,by);

    A =(acos((oa*oa+ob*ob-ab*ab)/(2*oa*ob)));

    s=oa*A;

    printf("Case %d: %.8lf\n",i,s);

    }
return 0;
}
