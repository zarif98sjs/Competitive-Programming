
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

vector<vector<int>> v;
int r,c,k;

int dp[3005][3005][5];

int solve(int i,int j,int cnt)
{
    if(i==r || j==c)
    {
        if((i==r-1 && j==c) || (i==r && j==c-1))
        {
            if(cnt<=3) return 0;
            return LLONG_MIN;
        }

        return LLONG_MIN;
    }

    int &ret = dp[i][j][cnt];
    if(~ret) return ret;

    ret = 0;

    if(cnt<=2) ret = max(ret, v[i][j] + solve(i,j+1,cnt+1));
    ret = max(ret, solve(i,j+1,cnt));
    if(cnt<=2) ret = max(ret, v[i][j] + solve(i+1,j,0));
    ret = max(ret, solve(i+1,j,0));

    return ret;
}


int32_t main()
{
    optimizeIO();


    cin>>r>>c>>k;

    v = vector<vector<int>>(r,vector<int>(c));

    while(k--)
    {
        int x,y,val;
        cin>>x>>y>>val;

        x-- , y--;
        v[x][y] = val;
    }

    memset(dp,-1,sizeof dp);
    int ans = solve(0,0,0);
    cout<<ans<<endl;
    DBG(ans);

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


