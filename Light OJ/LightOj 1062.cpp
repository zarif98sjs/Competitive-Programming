
/**

Topic : Geometry / Binary Search
=================================

Intersection of 2 line using cross product --> http://bit.ly/line_intersection

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLI pair<LL,int>
#define LPII pair<LL, pair<int,int> >
#define MP make_pair
#define F first
#define S second
#define LINF LLONG_MAX

//#define EPS 1e-11
double INF=1e100;
double EPS=1e-12;

struct PT
{
    double x,y;
    PT() {}
    PT(double x,double y) : x(x), y(y) {}
    PT(const PT &p) :   x(p.x), y(p.y) {}

    PT operator + (const PT &p) const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p) const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)    const
    {
        return PT(x*c, y*c  );
    }
    PT operator / (double c)    const
    {
        return PT(x/c, y/c  );
    }
};

double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}
double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d)
{
    b=b-a;
    d=c-d;
    c=c-a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}

const double eps = 1e-11;
int cmp(double x, double y)
{
    return (x <= y + eps) ? (x + eps < y) ? -1 : 0 : 1; /** 0 -> x equal y , 1 -> x>y , -1 -> x<y **/
}

int main()
{
    int tc;
    scanf("%d",&tc);

    //freopen("LightOj1056.txt","w",stdout);

    for(int i=1; i<=tc; i++)
    {
        double x,y,c,d;
        cin>>x>>y>>c;

        double lo=0,hi=min(x,y),mid;

        while(cmp(lo,hi)==-1)
        {
            mid=(lo+hi)*0.5;
            d=mid;

            double a1=sqrt(x*x-d*d);
            double a2=sqrt(y*y-d*d);

            PT h = ComputeLineIntersection(PT(0,0),PT(d,a2),PT(d,0),PT(0,a1));

            if (cmp(h.y, c) == 0)
                break;
            if (cmp(h.y, c) == 1)
                lo = mid;
            else
                hi = mid;

            d=mid;

        }

        cout<<"Case "<<i<<": "<<fixed<<setprecision(8)<<d<<endl;

    }

    return 0;

}
