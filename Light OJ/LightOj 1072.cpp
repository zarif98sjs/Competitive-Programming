
/**

Topic : Geometry
================

Angle in one circle is (2*PI)/n

**/

/** Which of the favors of your Lord will you deny? **/

#include<bits/stdc++.h>
#include<string>
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
#define MP      make_pair
#define PII     pair<int,int>
#define PLL     pair<ll,ll>

#define GCD     __gcd
#define DEBUG   cout<<"aw"<<endl;

int main()
{
    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        double R;
        int n;

        cin>>R>>n;

        double sin_a = sin(pi/n);

        double r = (R*sin_a)/(1+sin_a);

        printf("Case %d: %.9lf\n",i,r);

    }

    return 0;
}
