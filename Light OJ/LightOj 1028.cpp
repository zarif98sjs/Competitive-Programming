
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

#define mset(x,v) memset(x,v,sizeof(x))
#define GCD     __gcd
#define DEBUG   cout<<"aw"<<endl;

//int LIM1=1005;
int LIM2=1000005;

bool isP[1000010];
vector<int> primes;

void sieve()
{
    //primes.reserve(LIM2);

    fr(j,1,LIM2)
    isP[j]=true;

    for(int j=2; j<=LIM2; j++)
    {
        if(isP[j]==true)
        {
            primes.PUB(j);

            for(int k=2; (j*k)<=LIM2; k++)
                isP[j*k]=false;

        }

    }

    return;

}

int main()
{

    //freopen("LOJ1028.txt","w",stdout);

    sieve();

    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        LL num;
        SLL(num);

        int factorNum = 1;

        for(int j=0; primes[j]<=sqrt(num) ; j++)
        {
            if(num<=1000000)
            {
                if(isP[num]==true)
                    break;
            }

            int k = 0;
            int x = primes[j];

            while(num%x==0)
            {
                num=num/x;
                k++;
            }

            factorNum = factorNum * (k+1);

            //cout<<"**"<<j<<endl;
        }

        if(num>1)
            factorNum *= 2;

        printf("Case %d: %d\n",i,factorNum-1);

    }

    return 0;
}
