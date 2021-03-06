
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
    int n;
    cin>>n;

    vector<int>v(n+1);
    for(int i=0;i<n;i++) cin>>v[i];
    v[n] = 1;

    int turn = 0; /// friend;
    vector<int>cost(n,0);

    for(int i=0;i<n;i++)
    {
        if(turn==0)
        {
            DBG(i);
            if(v[i]==0 && v[i+1]==0) i++;
//            if(v[i]==0 && v[i+1]==1) ;
            if(v[i]==1 && v[i+1]==0) cost[i] = 1 , i++;
            if(v[i]==1 && v[i+1]==1) cost[i] = 1;
        }
        if(turn==1)
        {
            int ni = i;
            DBG(ni);
//            if(v[i]==0 && v[i+1]==0) ;
            if(v[i]==0 && v[i+1]==1) i++;
//            if(v[i]==1 && v[i+1]==0) ;
            if(v[i]==1 && v[i+1]==1) i++;
        }

        turn ^= 1;

//        DBG(cost);
    }

    int ans = 0;

    for(int x:cost) ans += x;

    DBG(ans);
    cout<<ans<<endl;
}

int32_t main()
{
    optimizeIO();

    int tc;
    cin>>tc;

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
