
/**

The expectation at i is E(i)

E(i) = (E(i+1) + E(i+2) + E(i+3) + E(i+4) + E(i+5) + E(i+6)) / cnt + gold[i];

where cnt is how many of E(i+x) is valid

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

long double ara[103];
long double dp[103];
int n;

long double solve(int pos)
{
    if(pos==n-1)
        return ara[pos];

    long double &ret = dp[pos];

    if(ret>=0.0)
        return ret;

    ret = 0;
    int cnt = 0;

    for(int i=1; i<=6; i++)
    {
        if(pos+i<n)
        {
            ret += ara[pos] + solve(pos+i);
            //cout<<i<<" -> "<<ret<<endl;
        }
        else
            cnt++;

    }

    ret /= (6.0-cnt);

    return ret;
}


int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        cin>>n;

        for(int i=0; i<n; i++)
            cin>>ara[i];

        memset(dp,-1,sizeof dp);

        long double ans = solve(0);

        cout << fixed << showpoint;
        cout << setprecision(10);

        cout<<"Case "<<q<<": "<<ans<<endl;

    }

    return 0;
}



