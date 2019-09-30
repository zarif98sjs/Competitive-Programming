
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

const int nmax = 110;

int dp[nmax][nmax];
string dp2[nmax][nmax];
string X,Y;
int l1,l2;

int solve_forward(int i,int j)
{
    if(i>=l1 || j>=l2)
        return 0;

    int &ret = dp[i][j];

    if(ret!=-1)
        return ret;

    if(X[i]==Y[j])
        return ret = 1 + solve_forward(i+1,j+1);

    else
        return ret = max(solve_forward(i,j+1),solve_forward(i+1,j));
}

string printLCSforward(int i,int j)
{
    //cout<<" -- "<<endl;

    if(i>=l1 || j>=l2)
        return "";

    string &ret = dp2[i][j];

    if(ret!="#")
        return dp2[i][j];

    if(X[i]==Y[j])
        return  ret = X[i] + printLCSforward(i+1,j+1);

    if(solve_forward(i,j+1)>solve_forward(i+1,j))
        return ret = printLCSforward(i,j+1);
    else if (solve_forward(i,j+1)<solve_forward(i+1,j))
        return ret = printLCSforward(i+1,j);
    else
    {
        string temp1 = printLCSforward(i,j+1);
        string temp2 = printLCSforward(i+1,j);

        //cout<<temp1<<" ** "<<temp2<<endl;

        if(temp1<=temp2)
            return ret = temp1;
        else
            return ret = temp2;
    }
}

int main()
{
    //optimizeIO();

    int tc;
    cin>>tc;

    for(int q=1;q<=tc;q++)
    {
        cin>>X>>Y;
        l1 = (int)X.size();
        l2 = (int)Y.size();

        memset(dp,-1,sizeof(dp));

        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++)
                dp2[i][j]='#';

        string lex_lcs;
        int len = solve_forward(0,0);
        lex_lcs = printLCSforward(0,0);
        //len = (int) lex_lcs.size();

        if(len==0)
            cout<<"Case "<<q<<": "<<":("<<endl;
        else
            cout<<"Case "<<q<<": "<<lex_lcs<<endl;

    }

    return 0;
}
