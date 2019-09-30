
    /*

    MATRIX EXPO
    -----------

    Related Article : http://zobayer.blogspot.com/2010/11/matrix-exponentiation.html

    One thing to notice is that here the power will be n-2

    */

    /* Which of the favors of your Lord will you deny? */

    #include<bits/stdc++.h>
    using namespace std;

    #define MAX 100050

    #define LL long long
    #define PII pair<int,int>
    #define MP make_pair
    #define F first
    #define S second

    #define N 4

    int base[4][4] = {{-1,0,-1,1},{1,0,0,0},{0,1,0,0},{0,0,0,1}}, unit[4][4];
    int mod=10007;

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
        int b[4][4];
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

        for(int i=0;i<N;i++)
            unit[i][i]=1;

        for(int q=1; q<=tc; q++)
        {
            int n,a,b,c;
            scanf("%d %d %d %d",&n,&a,&b,&c);


            base[0][0]=a;
            base[0][2]=b;

    //        for (int i=0; i<N; i++)
    //        {
    //            for (int j=0; j<N; j++)
    //                cout<<base[i][j]<<" ";
    //            cout<<endl;
    //        }



            if(n<=2)
                printf("Case %d: %d\n",q,0);
            else
            {
                //n=1;
                int r[N][N];
                fast_mat_expo(r,n-2);

                int ans=(r[0][3]*c)%mod;
                printf("Case %d: %d\n",q,ans);

            }

        }

        return 0;
    }


