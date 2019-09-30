

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

const int nmax = 1e6+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

vector<int>R,G,B;

int dp[30][4];

int n;

int solve(int pos,int prev)
{
    if(pos>=n)
        return 0;

    int &ret = dp[pos][prev];

    if(ret!=-1)
        return ret;

    if(prev==0)
    {
        int v1 = G[pos] + solve(pos+1,1);
        int v2 = B[pos] + solve(pos+1,2);
        ret = min(v1,v2);
    }
    else if(prev==1)
    {
        int v1 = R[pos] + solve(pos+1,0);
        int v2 = B[pos] + solve(pos+1,2);
        ret = min(v1,v2);
    }
    else if(prev==2)
    {
        int v1 = R[pos] + solve(pos+1,0);
        int v2 = G[pos] + solve(pos+1,1);
        ret = min(v1,v2);
    }
    else
    {
        int v1 = R[pos] + solve(pos+1,0);
        int v2 = G[pos] + solve(pos+1,1);
        int v3 = B[pos] + solve(pos+1,2);
        ret = min(v1,min(v2,v3));
    }

    return ret;

}

int main()
{
    int tc;
    cin>>tc;

    for(int q=1;q<=tc;q++)
    {
        R.clear();
        G.clear();
        B.clear();

        cin>>n;

        for(int i=0;i<n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            R.push_back(a);
            G.push_back(b);
            B.push_back(c);
        }

        memset(dp,-1,sizeof dp);
        int ans = solve(0,3);
        cout<<"Case "<<q<<": "<<ans<<endl;
    }

    return 0;
}
