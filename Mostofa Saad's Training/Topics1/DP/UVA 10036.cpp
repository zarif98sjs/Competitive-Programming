
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

int n,k;
vector<int>v;
int dp[10005][105];

int FIX(int x)
{
    return (x%k + k)%k;
}

/**

If we had stored the actual sum , we would need [1e4][1e8] dp states.
But divisibility can be determined by the modulo of the sum . That reduces the number of states to [1e4][1e2]

**/

int solve(int pos,int sum)
{
    if(pos==n)
    {
        return sum==0;
    }

    int &ret = dp[pos][sum];
    if(ret != -1) return ret;

    int s1 = v[pos] + sum;
    int s2 = -v[pos] + sum;

    int way1 = solve(pos+1 , FIX(s1) );
    int way2 = solve(pos+1 , FIX(s2) );

    ret = way1 | way2;
    return ret;
}

int main()
{
    optimizeIO();

//    WRITE;

    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>n>>k;

        v = vector<int>(n);

        for(int i=0;i<n;i++)
            cin>>v[i];

        memset(dp,-1,sizeof dp);
        int ans = solve(1,FIX(v[0]));

        if(ans) cout<<"Divisible"<<endl;
        else cout<<"Not divisible"<<endl;
    }

    return 0;
}

/**
10
4 7
17 5 -21 15
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


