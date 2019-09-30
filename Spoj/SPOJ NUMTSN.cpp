
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

string A,B;


LL dp[60][2][2][17][17][17];

LL mod = 1e9+7;

int lim;

LL go(int pos,int choto,int boro,int three,int six,int nine)
{
    if(three>16 || six>16 || nine>16)
        return 0;

    if(pos==lim)
        return ((three>=1) && (three==six) && (six==nine));

    LL &ret = dp[pos][choto][boro][three][six][nine];

    if(ret!=-1 && boro==1 && choto==1)
        return ret;

    ret = 0;

    int lo = 0, hi = 9;

    if(!choto) hi = B[pos] - '0';
    if(!boro) lo = A[pos] - '0';

    for(int j=lo; j<=hi; j++)
    {
        ret = ret%mod + (go(pos+1, choto | (j<hi), boro | (j>lo),(j==3)+three,(j==6)+six,(j==9)+nine))%mod;
        ret = ret%mod;
    }

    return ret;
}

int main()
{
    //optimizeIO();

    int tc;
    //cin>>tc;
    scanf("%d",&tc);
    memset(dp,-1,sizeof dp);
    for(int q=1; q<=tc; q++)
    {

        //cout<<"----------------------"<<endl;
        //cout<<"Case "<<q<<": ";
//
//        string a,b;
//        cin>>a>>b;
//
//        A = a;
//        B = b;
        char s1[60],s2[60];

        scanf("%s",s1);
        scanf("%s",s2);

        A = s1;
        B = s2;

        while(A.size()<B.size())
        {
            A.insert(A.begin(),'0');
        }
        while(A.size()!=51)
        {
            A.insert(A.begin(),'0');
            B.insert(B.begin(),'0');
        }
        lim=51;
        //cout<<inp<<endl;

        LL ans = go(0,0,0,0,0,0);
        ans = ans % mod;
        printf("%d\n",ans);
        //cout<<ans<<endl;

    }


    return 0;
}

