
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
#define endl "\n"
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

void solveTC()
{
    int sum;
    cin>>sum;

    vector<int>a(3),b(3);
    cin>>a[0]>>a[1]>>a[2];
    cin>>b[0]>>b[1]>>b[2];

    int t1 = min(a[0],b[1]);
    int t2 = min(a[1],b[2]);
    int t3 = min(a[2],b[0]);

    int mx = t1+t2+t3;

    /// maximizing a lose not b win
    t1 = min(a[0],b[0]+b[2]);
    t2 = min(a[1],b[1]+b[0]);
    t3 = min(a[2],b[2]+b[1]);

    int alose = t1 + t2 + t3;

    int mn = sum - alose;

    cout<<mn<<" "<<mx<<endl;

//    int bt1 = min(b[0],a[1]);
//    b[0] -= bt1 , a[1] -= bt1;
//    int bt2 = min(b[1],a[2]);
//    b[1] -= bt2 , a[2] -= bt2;
//    int bt3 = min(b[2],a[0]);
//    b[2] -= bt3 , a[0] -= bt3;
//
//    DBG(a);
//    DBG(b);
//
//    int d1 = min(a[0],b[0]);
//    a[0] -= d1 , b[0] -= d1;
//    int d2 = min(a[1],b[1]);
//    a[1] -= d2 , b[1] -= d2;
//    int d3 = min(a[2],b[2]);
//    a[2] -= d3 , b[2] -= d3;
//
//    DBG(a);
//    DBG(b);
//
//    t1 = min(a[0],b[1]);
//    t2 = min(a[1],b[2]);
//    t3 = min(a[2],b[0]);
//
//    int mn = t1+t2+t3;

//    int mn = sum - bmx - draw;

}

int32_t main()
{
    optimizeIO();

    int tc =1 ;
//    cin>>tc;

    while(tc--)
    {
        solveTC();
    }

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
    for(T i:v)
    {
        os<<i<<" " ;
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
