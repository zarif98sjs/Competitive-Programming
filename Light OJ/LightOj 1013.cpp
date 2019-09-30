

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

int n1,n2;
string s1,s2;

LL dp[nmax][nmax];
LL dp_ans[nmax][nmax];

LL solve(int i,int j)
{
    if(i>=n1) return n2-j;
    if(j>=n2) return n1-i;

    LL &ret = dp[i][j];

    if(ret!=-1) return ret;

    if(s1[i]==s2[j]) ret = 1 + solve(i+1,j+1);
    else ret = 1 + min(solve(i,j+1),solve(i+1,j));

    return ret;
}

LL ways(int i,int j)
{
    if(i>=n1) return 1;
    if(j>=n2) return 1;

    LL &ret = dp_ans[i][j];

    if(ret!=-1) return ret;

    if(s1[i]==s2[j]) ret = ways(i+1,j+1);
    else if(solve(i+1,j)<solve(i,j+1)) ret = ways(i+1,j);
    else if(solve(i+1,j)>solve(i,j+1)) ret = ways(i,j+1);
    else ret = ways(i+1,j) + ways(i,j+1); // if both gives same result , go both ways

    return ret;
}

int main()
{
    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {

        cin>>s1>>s2;

        n1 = s1.size();
        n2 = s2.size();

        memset(dp,-1,sizeof dp);
        memset(dp_ans,-1,sizeof dp_ans);

        LL len = solve(0,0);
        LL ans = ways(0,0);

        cout<<"Case "<<q<<": "<<len<<" "<<ans<<endl;

    }

    return 0;
}
