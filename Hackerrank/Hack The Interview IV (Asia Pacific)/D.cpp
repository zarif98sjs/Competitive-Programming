
/**
**/

/**Which of the favors of your Lord will you deny ?**/

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

string A,B;
int k;
LL mod = 1e9+7;

LL dp[105][2][2][105];

LL go(int pos,int choto,int boro,int val)
{
    if(pos==B.size())
    {
        return (val==k);
    }

    LL &ret = dp[pos][choto][boro][val];

    if(ret!=-1)
        return ret;

    ret = 0;

    int lo = 0, hi = 9;

    if(!choto)
        hi = B[pos] - '0';
    if(!boro)
        lo = A[pos] - '0';

    for(int j=lo; j<=hi; j++)
    {
        ret = ret%mod + go(pos+1, choto | (j<hi), boro | (j>lo),  (j!=0)+val)%mod;
        ret = ret%mod;
    }

    return ret;
}

int main()
{
    optimizeIO();

    cin>>A>>B;
    cin>>k;

    bool ok = false;
    int cnt = 0;
    for(int i=0;i<A.size();i++)
        cnt += (A[i]!='0');

    if(cnt==k)
        ok = true;

    while(A.size()<B.size())
    {
        A.insert(A.begin(),'0');
    }

    //cout<<inp<<endl;
    memset(dp,-1,sizeof dp);
    LL ans = go(0,0,0,0);

    if(ok)
        ans = (ans-1+mod)%mod;

    cout<<ans<<endl;

    return 0;
}
