
/**

Idea : http://lbv-pc.blogspot.com/2012/07/baker-vai.html

**/

/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 1e2+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

int n,m;
LL ara[nmax][nmax];

LL dp[nmax][nmax][nmax][3];

LL solve(int row,int lc,int rc,int move)
{
    if(row==n-1 && lc==m-2 && rc==m-1 && move==0)
        return 0;

    LL &ret = dp[row][lc][rc][move];

    if(ret!=-1)
        return ret;

    ret = 0;

    if(move==0)
    {
        if(lc+1<rc)
            ret = max(ret, solve(row,lc+1,rc,0) + ara[row][lc+1]);
        ret = max(ret, solve(row,lc,rc,1));
    }
    else if(move==1)
    {
        if(rc+1<m)
            ret = max(ret, solve(row,lc,rc+1,1) + ara[row][rc+1]);
        if(rc>lc)
            ret = max(ret, solve(row,lc,rc,2));
    }
    else
    {
        if(lc<rc && row+1<n)
            ret = max(ret, solve(row+1,lc,rc,0) + ara[row+1][lc] + ara[row+1][rc]);
    }

    return ret;

}

int main()
{
    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        cin>>n>>m;

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>ara[i][j];

        memset(dp,-1,sizeof dp);

        LL ans = solve(0,0,0,1) + ara[0][0];

        cout<<"Case "<<q<<": "<<ans<<endl;


    }

    return 0;
}
