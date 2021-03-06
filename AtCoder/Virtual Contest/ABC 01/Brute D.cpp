
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

#define int long long

//int solve(int n)
//{
//    int cnt = 0;
//
//    map<PII,bool>m;
//
//    for(int i=0;i<=n;i++)
//        for(int j=0;j<=n;j++)
//            if(i+j<=n && (i^j)<=n)
//                m[{i+j,i^j}] = true;
//
//    for(auto p:m) cnt += m[p.F];
//
//    return cnt;
//}

int solve(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;

    if(n%2==0) return 2*solve(n/2) + solve(n/2 - 1);
    else return 2*solve(n/2) + solve(n/2 + 1);
}

int32_t main()
{
    optimizeIO();


    while(1)
    {
        int n;
        cin>>n;

        while(true)
        {
            int i;
            cin>>i;
            int bit = ((n >> i) & 1);
            DBG(bit);
        }



        int ans = solve(n);
        DBG(ans);
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
