/*
                " اللهم صلي و سلم علي سيدنا محمد و علي اله وصحبه اجمعين "
*/

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define f for
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define intial(s1,s2,x,dp) f(int i = 0; i < s1; i++)f(int j = 0; j < s2; j++)dp[i][j] = x;
using namespace std;
#define BI  acos(-1)
#define all(a) a.begin(), a.end()
#define loop1(n) f(int i=0;i<n;i++)
#define loop2(n) f(int j=0;j<n;j++)
void Open()
{
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void madesetprobblem()
{
    //$ $
    //less than or equal => $ 1 \leq 100 $
    //  $(1 \le A,B \le 10^5 )$
    // a[i] => $a_i$
    // a[i][j] => $a_{i,j}$
    // double qoutes ''yext''
    /*
        image
        \begine{center}
        \includegraphics{image.jpg}
        \end{center}
    */
    /*
        list
        \begin{itemize}
            \item first one
            \item second one
        \end{itemize}
    */
}
int n,s,k;
int *a;
int *b;
int dp[51][2001][51][4];
int ans(int c,int k,int z,int x)
{
    cout<<c<<" "<<k<<endl;

    if(c==-1||c==n||k<=0)
    {
        if(k<=0)
            return 0;
        return 1e8;
    }
    int &ret=dp[c][k][z][x];
    if(~ret)return ret;
    ret=1e8;
//    if(x==3)
//    {
//        ret=min(ans(c+1,k-a[c],a[c],b[c])+1,ans(c-1,k-a[c],a[c],b[c])+1);
//    }
    if(a[c]>z&&x!=b[c])
    {
        cout<<"here"<<endl;
        ret = min(ret,ans(c+1,k-a[c],a[c],b[c])+1);
        ret = min(ret,ans(c-1,k-a[c],a[c],b[c])+1);
    }
    return ret=min({ret,ans(c+1,k,z,x)+1,ans(c-1,k,z,x)+1});
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>n>>s>>k;
    a=new int[n];
    b=new int[n];
    loop1(n)
    {
        cin>>a[i];
    }
    char e;
    loop1(n)
    {
        cin>>e;
        if(e=='R')
            b[i]=0;
        else if(e=='G')
            b[i]=1;
        else b[i]=2;
    }
    int ss=ans(s-1,k,0,3);
    if(ss>=1e8)cout<<-1;
    else cout<<ss-1;
}
/**
2 10
here
3 7
here
4 3
5 3
3 3
4 3
2 3
3 3
1 3
2 3
0 3
1 3
-1 3
2 3
4 7
**/
