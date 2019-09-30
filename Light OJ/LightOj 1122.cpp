
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 20;

int dp[nmax][nmax];
int n,len;
int ara[nmax];

int solve(int pos,int digit)
{
    if(pos==len+1)
        return 1;

    int &ret = dp[pos][digit];

    if(ret!=-1)
        return ret;

    ret = 0;

    for(int i=1;i<=n;i++)
    {
        if(pos==1 || (abs(digit-ara[i])<=2))
            ret += solve(pos+1,ara[i]);
    }

    return ret;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        cin>>n>>len;

        for(int i=1; i<=n; i++)
            cin>>ara[i];

        memset(dp,-1,sizeof(dp));

        cout<<"Case "<<q<<": ";
        cout<<solve(1,0)<<endl;

    }

    return 0;
}
