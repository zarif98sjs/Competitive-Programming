
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#endif

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;

struct Point
{
    int x,y;

    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int x,int y)
    {
        this->x = x;
        this->y = y;
    }

    Point operator - (const Point &p) const
    {
        return Point(x-p.x, y-p.y);
    }
};

ostream &operator <<(ostream &os, Point &node)
{
    os<<"X : "<<node.x<<" , Y : "<<node.y;
    return os;
}

bool isSame(Point a,Point b)
{
    if(a.x==b.x && a.y==b.y)
        return true;
    return false;
}

LL cross(Point p, Point q)
{
    return p.x*1LL*q.y-p.y*1LL*q.x;
}

bool isPos(Point l1a,Point l1b,vector<Point>&v)
{
    int n = v.size();

    vector<bool>ok(n,false);

    for(int i=0; i<v.size(); i++)
    {
        Point p = v[i];

        if(cross(l1b-l1a,p-l1a)==0)
            ok[i] = true;

    }

    DBG(ok);

    vector<int>l2;

    for(int i=0; i<n; i++)
        if(!ok[i] && l2.size()<2)
            l2.push_back(i);

    if((int)l2.size()==1) ok[l2[0]] = true;
    else if((int)l2.size()==2)
    {
        Point l2a = v[l2[0]];
        Point l2b = v[l2[1]];
        for(int i=0; i<v.size(); i++)
        {
            Point p = v[i];

            if(cross(l2b-l2a,p-l2a)==0)
                ok[i] = true;
        }
    }

    for(int i=0; i<n; i++)
        if(!ok[i])
            return false;

    return true;
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<Point>v(n);

    for(int i=0; i<n; i++)
        cin>>v[i].x>>v[i].y;

    if(n<=3)
    {
        cout<<"YES"<<endl;
        return 0;
    }

    bool ok = false;

    if (isPos(v[0],v[1],v))
        ok = true;
    else if (isPos(v[0],v[2],v))
        ok = true;
    else if (isPos(v[1],v[2],v))
        ok = true;

    if(ok)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


    return 0;
}

/**

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


