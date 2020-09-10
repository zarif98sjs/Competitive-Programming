
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

#include <random>
#include <chrono>

// Seeding non-deterministically
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

random_device rd;
mt19937 mt(rd());

uniform_int_distribution<int> r(1,10); /// generate between [1,10]

int32_t main()
{
    optimizeIO();

    freopen("inC.txt","w",stdout);

    int tc;
    cin>>tc;
    cout<<tc<<endl;

    while(tc--)
    {
        int n = r(mt);
        cout<<n<<endl;

        for(int i=0;i<n;i++)
            cout<<r(mt)<<" ";
        cout<<endl;
    }

    return 0;
}

/**
9
4 6 5 7 2 3 5 4 5

7
5 2 3 2 3 2 3

10
7 2 3 5 2 3 5 2 3 5
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


