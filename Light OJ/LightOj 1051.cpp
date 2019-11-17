
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

const int nmax = 55;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

bool is_vow(char c)
{
    return (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U');
}

string s;
int n;
int dp[nmax][10][10];

int solve(int pos,int c,int v)
{
    if(pos>=n)
        return 2;

    int &ret = dp[pos][c][v];

    if(ret!=-1) return ret;

    if(s[pos]=='?')
    {
        int op1 = (c>=4) ? 1 : solve(pos+1,min(c+1,5),0);
        int op2 = (v>=2) ? 1 : solve(pos+1,0,min(v+1,3));
        return ret = op1 | op2;
    }
    else if(is_vow(s[pos]))
    {
        if(v>=2) return ret = 1;
        else return ret = solve(pos+1,0,min(v+1,3));
    }
    else
    {
        if(c>=4) return ret = 1;
        else return ret = solve(pos+1,min(c+1,5),0);
    }

}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        cin>>s;
        n = s.size();

        memset(dp,-1,sizeof dp);
        int ans = solve(0,0,0);

        if(ans==1) cout<<"Case "<<q<<": BAD"<<endl;
        else if(ans==2) cout<<"Case "<<q<<": GOOD"<<endl;
        else cout<<"Case "<<q<<": MIXED"<<endl;
    }

    return 0;

}


