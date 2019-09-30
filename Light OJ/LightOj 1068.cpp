
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

const int nmax = 1e3+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

int k;
string inp;

LL dp[10][2][100][100];

LL go(int pos,int is_start,int sum,int div)
{
    if(pos==inp.size())
        return (sum==0) && (div==0);

    LL &ret = dp[pos][is_start][sum][div];

    if(ret!=-1)
        return ret;

    ret = 0;

    int maxx = is_start ? (inp[pos]-'0') : 9;

    for(int j=0;j<=maxx;j++)
        ret += go(pos+1, is_start && (j==maxx) ,(sum+j)%k,(((div*10)%k)+j)%k);

    return ret;
}

int main()
{
    optimizeIO();

    //freopen("LOJ1068.txt","w",stdout);

    int tc;
    cin>>tc;

    for(int q=1;q<=tc;q++)
    {

        cout<<"Case "<<q<<": ";

        LL a,b;
        cin>>a>>b>>k;

        if(k>81)
        {
            cout<<0<<endl;
            continue;
        }

        inp = to_str(b);
        memset(dp,-1,sizeof dp);
        LL ans = go(0,1,0,0);

        inp = to_str(a-1);
        memset(dp,-1,sizeof dp);
        ans -= go(0,1,0,0);

        cout<<ans<<endl;

    }


    return 0;
}
