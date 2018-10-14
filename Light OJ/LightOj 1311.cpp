
/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

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

#define mset(x,v) memset(x,v,sizeof(x))
#define GCD     __gcd
#define DEBUG   cout<<"aw"<<endl;

int main()
{
    //freopen("loj1311.txt","w",stdout);

    int tc;
    SI(tc);

    /* // time for the stopping is not same :/
        fr(i,1,tc)
        {
            double v1,v2,v3,a1,a2;
            SD(v1),SD(v2),SD(v3),SD(a1),SD(a2);

            double d = ((v1+v2)*(v1+v2))/(2.0*(a1+a2));

            double t = ((v1+v2)+sqrt((v1+v2)*(v1+v2)-2*(a1+a2)*d))/(a1+a2);

            double d_bird = v3*t;

            printf("Case %d: %.7lf %.7lf\n",i,d,d_bird);

        }
    */

    fr(i,1,tc)
    {
        double v1,v2,v3,a1,a2,t;
        SD(v1),SD(v2),SD(v3),SD(a1),SD(a2);

        double d1 = (v1*v1)/(2*a1);
        double d2 = (v2*v2)/(2*a2);

        double d = (v1*v1)/(2*a1) + (v2*v2)/(2*a2);

        double t1 = (2*d1)/v1;
        double t2 = (2*d2)/v2;

        t=t1;
        if(t2>t1)
            t=t2;

        double d_bird = v3*t;

        printf("Case %d: %.8lf %.8lf\n",i,d,d_bird);

    }

    return 0;
}

