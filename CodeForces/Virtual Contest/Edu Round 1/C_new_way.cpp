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
    if(p.y != 0) return p.y < 0; /// if lower half return 1 i.e higher value
    return p.x < 0;
}

bool operator<(const point p, const point q)
{
    if(sgn(p) != sgn(q)) return sgn(p) < sgn(q);
    return cross(p, q) > 0; /// if in the same half , identify position by cross product
}

/**

We look at the integer parts of each fraction first.
If they are unequal, then we know which is larger.

Otherwise, we can discard their integer parts and consider only their fractional parts.
To compare these, we take the reciprocals of the two fractional parts and apply this process recursively.

(Note the similarities between this algorithm and the Euclidean algorithm---both run in O(NlogN) )

**/

bool comp(ll a, ll b, ll c, ll d)
{
    if(a / b != c / d) return a / b < c / d;
    a %= b, c %= d;
    if(c == 0) return 0;
    if(a == 0) return 1;
    return comp(d, c, b, a);
}

/**

Compare the angle created between (c,d) vectors with the angle created between (a,b) vectors

a^b = angle between a and b
    = dot(a,b) / |a| * |b|

To avoid calculating square root we square it .
So , (a^b)^2 = dot(a,b) * dot(a,b) / |a|^2 * |b|^2
=> (a^b)^2 = dot(a,b) * dot(a,b) / dot(a, a) * dot(b, b)

To compare a^b with c^d , if we know that the signs are different
we know that the one with +ve sign is smaller as will take acos() of that value

As for the case when they are same , we have to compare 2 fractions . See the comp function.

**/
bool comp(point a, point b, point c, point d)
{
    ll u1 = dot(a, b) * dot(a, b);
    ll v1 = dot(a, a) * dot(b, b);
    ll u2 = dot(c, d) * dot(c, d);
    ll v2 = dot(c, c) * dot(d, d);
    if(sgn(dot(a, b)) != sgn(dot(c, d)))
    {
        return sgn(dot(c, d)) > sgn(dot(a, b));
    }
    return !sgn(dot(c, d)) ^ comp(u1, v1, u2, v2);
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

    /**
    Sort according to semi planes (i.e lower and upper half)
    and for same semi plane identify order by doing cross product .
    If p x q > 0 then p and q is in anticlockwise order
    else in clockwise order
    **/

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
