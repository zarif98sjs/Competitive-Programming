
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

#define int long long

void solve() {
    int x, k, d;
    cin>>x>>k>>d; /// k is the total no. of moves
    x = abs(x); /// considering that we are on +ve x-axis
    int steps = x/d; /// no. of steps we are away from origin
    if(k <= steps) x -= k*d; ///if k<=steps, we will try to move as close to origin as
                             ///possible
    else { ///if we are forced to move more steps than required
        k -= steps; ///now k is the extra steps which we are condemned to move
        if(k%2==0) x -= d*steps; ///if extra steps is even, we can simply waste them by
                              ///moving 1 step forward and 1 step backward again and again
        else { ///if odd, we will cross origin (atleast) once as we have no other choice
            x -= d*(steps+1);
        }
    }
    x = abs(x); //finally getting the distance from origin
    cout<<x<<"\n";
    return;
}

int32_t main()
{
    optimizeIO();

    solve();

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


