#include<bits/stdc++.h>
using namespace std;
int n,m,a[550],b[550],dp[550][550],Next[550][550];
int solve(int pos,int last)
{
    if(pos>n) return 0;
    if(dp[pos][last]!=-1) return dp[pos][last];
    int op = 0;
    if(Next[pos][last]<=m && a[pos]>b[last]) op = 1 + solve(pos+1,Next[pos][last]);
    op = max(op,solve(pos+1,last));
    return dp[pos][last] = op;
}
void print(int pos,int last)
{
    if(pos>n) return;
    int op1 = -1,op2 = solve(pos+1,last);
    if(Next[pos][last]<=m && a[pos]>b[last]) op1 = 1 + solve(pos+1,Next[pos][last]);
    //cout<<pos<<" "<<last<<" "<<op1<<" "<<op2<<endl;
    if(op1>=op2)
    {
        cout<<a[pos]<<" ";
        print(pos+1,Next[pos][last]);
    }
    else print(pos+1,last);
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1; i<=m; i++) scanf("%d",&b[i]);
    b[0] = INT_MIN;
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        int last = m+1;
        for(int j=m; j>=0; j--)
        {
            Next[i][j] = last;
            if(b[j]==a[i]) last = j;
        }
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<Next[i][j]<<" ";
        cout<<endl;
    }



    int ans = solve(1,0);
    cout<<ans<<endl;
    print(1,0);
    cout<<endl;
}
