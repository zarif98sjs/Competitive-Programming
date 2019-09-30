
/**

Bitmask DP
Idea : https://codeforces.com/blog/entry/19423

Note : Using excess memory gives RTE in this problem , the LOJ compiler can't compile in that case.
So , allocate memory carefully

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

const int nmax = 18;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

LL dp[1<<17][20];
int ara[200];

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        LL base,M;
        cin>>base>>M;
        string s;
        cin>>s;

        int len = s.size();

        for(LL i=0; i<len; i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ara[i]=s[i]-'0';
            }
            else
            {
                ara[i]=s[i]-'A'+10;
            }
        }

        memset(dp,0,sizeof dp);

        dp[0][0] = 1;

        for(int i=0; i< (1<<len); i++)
            for(int k=0; k<len; k++)
                if(!(i & (1<<k)))
                    for(int j=0; j<M; j++)
                        dp[i | (1<<k)][(j*base+ara[k])%M] += dp[i][j];


        LL ans = dp[(1<<len)-1][0];

        cout<<"Case "<<q<<": "<<ans<<endl;

    }

    return 0;
}
