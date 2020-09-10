
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool sgn(ll x)
{
    return x > 0;
}

struct point
{
    int x, y, i;
};

ll cross(point p, point q)
{
    return p.x * q.y - p.y * q.x;
}

ll dot(point p, point q)
{
    return p.x * q.x + p.y * q.y;
}

bool sgn(point p)
{
    if(p.y != 0) return p.y < 0;
    return p.x < 0;
}

bool operator<(const point p, const point q)
{
    if(sgn(p) != sgn(q)) return sgn(p) < sgn(q);
    return cross(p, q) > 0;
}

bool comp(ll a, ll b, ll c, ll d)
{
    cout<<a<<"/"<<b<<"   ,  "<<c<<"/"<<d<<endl;
    if(a / b != c / d) return a / b < c / d;
    a %= b, c %= d;
    cout<<"a : "<<a<<" , "<<"c : "<<c<<endl;
    if(c == 0) return 0;
    if(a == 0) return 1;
    return comp(d, c, b, a);
}

bool comp(point a, point b, point c, point d)
{
    ll u1 = dot(a, b) * dot(a, b);
    ll v1 = dot(a, a) * dot(b, b);
    ll u2 = dot(c, d) * dot(c, d);
    ll v2 = dot(c, c) * dot(d, d);
    if(sgn(dot(a, b)) != sgn(dot(c, d)))
    {
        return sgn(dot(a, b)) < sgn(dot(c, d));
    }
    return !sgn(dot(a, b)) ^ comp(u1, v1, u2, v2);
}

const int MAXN = 100005;
int N;
point P[MAXN], U, V;

int main()
{

    comp(50,40,60,41);


    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> P[i].x >> P[i].y;
        P[i].i = i + 1;
    }

    for(int i = 0; i < N; i++)
        cout<<sgn(P[i])<<endl;





//    sort(P, P + N);
//    P[N] = P[0];
//    U = P[0];
//    V = P[1];
//    for(int i = 0; i < N; i++)
//    {
//        if(comp(U, V, P[i], P[i + 1]))
//        {
//            U = P[i];
//            V = P[i + 1];
//        }
//    }
//    cout << U.i << " " << V.i << '\n';
}

/**

4

1 1
-1 1
-1 -1
1 -1

**/
