#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define double long double

bool sgn(ll x)
{
    return x > 0;
}

struct point
{
    ll x, y, i;
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
    if(a / b != c / d) return a / b < c / d;
    a %= b, c %= d;
    if(c == 0) return 0;
    if(a == 0) return 1;
    return comp(d, c, b, a);
}

double len(point p)
{
    return sqrtl(p.x*p.x + p.y*p.y);
}

double calc(point a, point b)
{
    double u = 1.0 * cross(a,b);
    double d = len(a) * len(b);

    return asin(u/d);
}

bool comp(point a, point b, point c, point d)
{
    double angle1 = calc(a,b);
    double angle2 = calc(c,d);

    return angle2<angle1;
}

const int MAXN = 100005;
int N;
point P[MAXN], U, V;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> P[i].x >> P[i].y;
        P[i].i = i + 1;
    }
    sort(P, P + N);
    P[N] = P[0];
    U = P[0];
    V = P[1];
    for(int i = 0; i < N; i++)
    {
        if(comp(U, V, P[i], P[i + 1]))
        {
            U = P[i];
            V = P[i + 1];
        }
    }
    cout << U.i << " " << V.i << '\n';
}
