// GEOMETRY

/* Lesson : Try with 3 squares first
            You will see that the area is (min of the upper x-max of the lower x)*(min of the upper x-max of the lower x);


/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define pi       acos(-1)

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

int main()
{
    //freopen("LOJ1211.txt","w",stdout);

    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        int n;
        SI(n);

        int max_x_lo = 0,max_y_lo = 0,max_z_lo = 0;
        int min_x_hi = 2000,min_y_hi = 2000,min_z_hi = 2000;


        fr(j,1,n)
        {
            int x_lo,y_lo,z_lo,x_hi,y_hi,z_hi;
            scanf("%d %d %d %d %d %d",&x_lo,&y_lo,&z_lo,&x_hi,&y_hi,&z_hi);

            max_x_lo = max(max_x_lo,x_lo);
            max_y_lo = max(max_y_lo,y_lo);
            max_z_lo = max(max_z_lo,z_lo);

            min_x_hi = min(min_x_hi,x_hi);
            min_y_hi = min(min_y_hi,y_hi);
            min_z_hi = min(min_z_hi,z_hi);

        }

        if(min_x_hi>max_x_lo && min_y_hi>max_y_lo && min_z_hi>max_z_lo)
            printf("Case %d: %d\n",i,(min_x_hi-max_x_lo)*(min_y_hi-max_y_lo)*(min_z_hi-max_z_lo));
        else
            printf("Case %d: 0\n",i);
    }


    return 0;
}
