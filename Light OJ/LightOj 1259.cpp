
/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define pi       acos(-1)

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

int LIM = 10000000;
bool isP[10000005];
vector<int>primes;

void sieve()
{
    fr(j,1,LIM)
        isP[j]=true;

    for(int j=2; j<=LIM; j++)
    {
        if(isP[j]==true)
        {
            primes.PUB(j);

            for(int k=2; (j*k)<=LIM; k++)
                isP[j*k]=false;

        }

    }

    return;
}

int main()
{
    sieve();

    int tc;
    SI(tc);

    fr(i,1,tc)
    {
        int num,cnt=0;
        SI(num);

        for(int q=0;primes[q]<=(num/2);q++)
        {
            int query = num-primes[q];

            if(isP[query]==true)
                cnt++;
        }

        printf("Case %d: %d\n",i,cnt);

    }

    return 0;
}
