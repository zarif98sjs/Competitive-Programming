/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define MAX 100050

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

#define N 2

int base[2][2] = {{1, 1}, {1, 0}}, unit[2][2] = {{1, 0}, {0, 1}};
int mod=0;

void multiply(int a[N][N], int b[N][N])
{
    int mul[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < N; k++)
                mul[i][j] += (a[i][k]*b[k][j])%mod;
        }
    }

//    for (int i=0; i<N; i++)
//        for (int j=0; j<N; j++)
//            a[i][j] = mul[i][j];

    memcpy(a,mul,sizeof mul);
}

void fast_mat_expo(int r[N][N],int n)
{
    int b[2][2];
    memcpy(r, unit, sizeof unit);
    memcpy(b, base, sizeof base);

    while(n>0)
    {
        if(n&1)//odd
            multiply(r,b);
        n>>=1;
        multiply(b,b);
    }
}

int powa(int x,int y)
{
    if(y==0)
        return 1;

    int temp = powa(x,y/2);

    if((y&1)==0) // (y%2==0) // LL korle 1LL
        return temp*temp;
    else
        return x*temp*temp;

}



int main()
{
    //freopen("LightOj1093.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        int a,b,n,m;
        scanf("%d %d %d %d",&a,&b,&n,&m);
        mod=powa(10,m);

        if(n==1)
            printf("Case %d: %d\n",q,a&mod);
        else if(n==2)
            printf("Case %d: %d\n",q,b&mod);
        else
        {
            int r[N][N];
            fast_mat_expo(r,n-1);

            int ans=(r[0][0]*b+r[0][1]*a)%mod;
            printf("Case %d: %d\n",q,ans);

        }

    }

    return 0;
}
