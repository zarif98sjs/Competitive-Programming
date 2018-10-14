
/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)

#define SI(n)    scanf("%d",&n)
#define SLL(n)   scanf("%lld",&n)
#define SULL(n)   scanf("%llu",&n)
#define SC(n)    scanf("%c",&n)
#define SD(n)    scanf("%lf",&n)

#define fr(i,a,b) for(int i=a ,_b=(b) ;i<= _b;i++)

#define LL      long long
#define PUB     push_back
#define POB     pop_back
#define MP      make_pair;
#define PII     pair<int,int>
#define PLL     pair<ll,ll>


#define GCD     __gcd
#define DEBUG   cout<<"aw"<<endl;

int abso(int x)
{
    if(x<0)
        return -1*x;

    return x;

}

int main()
{

    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        int x1,y1,r1,x2,y2,r2;
        SI(x1),SI(y1),SI(r1),SI(x2),SI(y2),SI(r2);

        double d = sqrt(abso(x1-x2)*abso(x1-x2)+abso(y1-y2)*abso(y1-y2));

        double s = (r1+r2+d)/2.0;
        double A_tot = sqrt(s*(s-r1)*(s-r2)*(s-d)) * 2.0;

        double theta1 = 2*acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
        double theta2 = 2*acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));

        //cout<<<<" "<<theta2<<endl;

        //cout<<theta1<<" "<<theta2<<endl;

        double A1 = 0.5*r1*r1*theta1;
        double A2 = 0.5*r2*r2*theta2;

        double A_uttor = A1+A2-A_tot;

        if(d>=(r1*1.0+r2*1.0))
        {
            A_uttor = 0.0;

        }
        else if(d<=abs(r1-r2))
        {
            if(r1<=r2)
                A_uttor = pi*r1*r1;
            else
                A_uttor = pi*r2*r2;

        }

        printf("Case %d: %0.10lf\n",i,A_uttor);

    }

    return 0;
}
