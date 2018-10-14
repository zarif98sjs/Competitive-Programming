    /* Which of the favors of your Lord will you deny? */

    #include<bits/stdc++.h>
    using namespace std;

    #define SI(n)    scanf("%d",&n)
    #define SLL(n)   scanf("%lld",&n)
    #define SULL(n)   scanf("%llu",&n)
    #define SC(n)    scanf("%c",&n)
    #define SD(n)    scanf("%lf",&n)

    #define fr(i,a,b) for(int i=a ,_b=(b) ;i<= _b;i++)

    #define LL      long long
    #define PUB     push_back
    #define POB     pop_back
    #define MP      make_pair;
    #define PII     pair<int,int>
    #define PLL     pair<ll,ll>

    #define GCD     __gcd
    #define DEBUG   cout<<"aw"<<endl;

    unsigned LL powa(int x , int y)
    {
        unsigned LL ans = x;

        for(int i=2;i<=y;i++)
        {
            ans = ans * x;
        }

        return ans;
    }

    int main()
    {
        int tc;
        SI(tc);

        fr(i,1,tc)
        {
            unsigned LL w;
            int q;
            SULL(w);

            if(w%2==1)
                printf("Case %d: Impossible\n",i);

            else
            {
                unsigned LL q = powa(2,1);

                for(int j=1;q<=w;j++ , q = powa(2,j))
                {
                    //DEBUG

                    if((w/q)%2==1)
                    {
                        printf("Case %d: %llu %llu\n",i,(w/q),q);
                        break;

                    }
                }
            }

        }

        return 0;
    }
