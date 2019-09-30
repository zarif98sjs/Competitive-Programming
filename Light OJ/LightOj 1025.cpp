
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

const int nmax = 70;

LL dp[nmax][nmax];
string str;

LL solve(int i, int j)
{
    if(i>j) return 0;
    if(i==j) return 1;

    LL &ret = dp[i][j];

    if(ret!=-1) return ret;

    if(str[i]==str[j])
        return ret = 1 + solve(i+1,j) + solve(i,j-1); // ret = (1 + solve(i+1,j-1)) + solve(i+1,j) + solve(i,j-1)-solve(i+1,j-1);
    else
        return ret =  solve(i+1,j) + solve(i,j-1) - solve(i+1,j-1);

}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1; q<=tc; q++)
    {
        cin>>str;

        int len = str.size();

        memset(dp,-1,sizeof(dp));

        cout<<"Case "<<q<<": ";
        cout<<solve(0,len-1)<<endl;

    }

    return 0;
}
