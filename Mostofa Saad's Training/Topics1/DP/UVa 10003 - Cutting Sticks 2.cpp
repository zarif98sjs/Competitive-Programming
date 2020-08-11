
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

const int nmax = 1e3+7;

int n;
int ara[nmax];
int dp[nmax][nmax];

int solve(int l,int r)
{
//    if(l>=r) return 0;

    int &ret = dp[l][r];
    if(ret != -1) return ret;

    int mn = INT_MAX;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(ara[i]>l && ara[i]<r)
        {
            mn = min(mn,solve(l,ara[i]) + solve(ara[i],r));
            cnt++;
        }
    }

    if(cnt==0)
        return ret = 0;

    ret = r-l + mn;

    return ret;
}

int main()
{
    optimizeIO();

    while(true)
    {
        int L;
        scanf("%d",&L);

        if(L==0)
            break;

        scanf("%d",&n);

        for(int i=1;i<=n;i++)
            scanf("%d",&ara[i]);

        memset(dp,-1,sizeof dp);
        int ans = solve(0,L);

//        printf("%d\n",ans);
        printf("The minimum cutting is %d.\n", ans);

    }

    return 0;
}

/**
100
3
25 50 75
10
4
4 5 7 8
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


