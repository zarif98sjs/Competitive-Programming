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

#define int long long

int abso(int x)
{
    if(x<0)
        return -1*x;

    return x;

}

#define double long double

int32_t main()
{

    int tc = 1;

    fr(i,1,tc)
    {
        LL x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;

        LL d2 = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        double d = sqrtl(d2);

        double s = (r1+r2+d)/2.0;
        double A_tot = sqrt(s*(s-r1)*(s-r2)*(s-d)) * 2.0;

        double theta1 = 2*acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
        double theta2 = 2*acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));

        double A1 = 0.5*r1*r1*theta1;
        double A2 = 0.5*r2*r2*theta2;

        double A_uttor = A1+A2-A_tot;

        if(d2>=(r1+r2)*(r1+r2))
        {
            A_uttor = 0.0;

        }
        else if(d2<=(r1-r2)*(r1-r2))
        {
            if(r1<=r2)
                A_uttor = pi*r1*r1;
            else
                A_uttor = pi*r2*r2;

        }

        cout<<setprecision(15);
        cout<<A_uttor<<endl;

    }

    return 0;
}
