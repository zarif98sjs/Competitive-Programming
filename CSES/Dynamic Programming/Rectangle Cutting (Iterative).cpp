
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

const int nmax = 505;
const int INF = 1e9+7;

int dp[nmax][nmax];

int solve(int h,int w)
{
    if(h==w) return 0;

    int &ret = dp[h][w];
    if(ret != -1) return ret;

    ret = INF;

    for(int x=1;x<=w;x++) ret = min(ret,1+solve(h,w-x)+solve(h,x));
    for(int y=1;y<=h;y++) ret = min(ret,1+solve(h-y,w)+solve(y,w));

    return ret;
}

void solveTC()
{
     int a,b;
     cin>>a>>b;

     dp[0][0] = 0;

     for(int h=1;h<=a;h++)
     {
         for(int w=1;w<=b;w++)
         {
            int &ret = dp[h][w];
             ret = INF;

             if(h==w)
             {
                ret = 0;
                continue;
             }

             for(int x=1;x<=w;x++) ret = min(ret,1+dp[h][w-x]+dp[h][x]);
             for(int y=1;y<=h;y++) ret = min(ret,1+dp[h-y][w]+dp[y][w]);

         }
     }

     cout<<dp[a][b]<<endl;

}

int32_t main()
{
    optimizeIO();

    int tc = 1;
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


