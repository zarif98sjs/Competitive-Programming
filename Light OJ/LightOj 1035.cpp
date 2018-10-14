
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

bool isPrime[110];
vector<int>primes;

void sieve()
{
    for(int i=1; i<=100; i++)
        isPrime[i]=true;

    for(int j=2; j<=100; j++)
    {
        if(isPrime[j]==true)
        {
            primes.PUB(j);

            for(int k=2; (j*k)<=100; k++)
            {
                isPrime[j*k]=false;
            }

        }
    }

    return;
}

int countPrimefacto[1000];

void porishkar()
{
    fr(i,1,100)
        countPrimefacto[i]=0;

    return;
}

int main()
{
    sieve();

    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        int n;
        SI(n);

        porishkar();

        int track = 1;

        for(int q=n;q>1;)
        {
            for(int j=0;j<primes.size();j++)
            {
                int x = primes[j];

                if(x>q)
                    break;

                while(q%x==0)
                {
                    q = q/x;
                    countPrimefacto[x]++;

                    //cout<<"x is "<<x<<endl;
                }



            }

            q = n-track;
            track++;

            //cout<<"again q is "<<q<<endl;
        }


        printf("Case %d: %d =",i,n);

        int flag;

        for(int j=2;j<=100;j++)
        {
            if(countPrimefacto[j]>0)
            {
                printf(" %d (%d)",j,countPrimefacto[j]);
                flag = j;
                break;
            }

        }

        for(int j=flag+1;j<=100;j++)
        {
            if(countPrimefacto[j]>0)
            {
                printf(" * %d (%d)",j,countPrimefacto[j]);

            }
        }

        printf("\n");

    }

    return 0;
}
