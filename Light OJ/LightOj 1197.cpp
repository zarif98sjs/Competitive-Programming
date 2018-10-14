
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair

LL MAX=1e10;
LL LIM=100000;

vector<int>primes;
bool isP[100010];
bool isPFinal[100010];

void sieve()
{
    for(int i=2; i<=LIM; i++)
        isP[i]=true;

    for(LL i=2; i<=LIM; i++)
    {
        //cout<<i<<endl;
        if(isP[i])
        {
            primes.push_back(i);
            for(LL j=i*i; j<=LIM; j+=i)  //ekhane int dile mara
                isP[j]=false;
        }
    }
}

int segmented_sieve(LL A,LL B)
{
    for(int i=0; i<=LIM; i++)
        isPFinal[i]=true;

    for(int i=0; i<primes.size(); i++)
    {
        LL p=primes[i];
        LL j=p*p;

        if(j<A)
            j=((A+p-1)/p)*p;

        for(; j<=B; j+=p)
            isPFinal[j-A]=false;

    }

    int ans=0;

    for(LL i=A; i<=B; i++)
    {
        if(isPFinal[i-A])
            ans++;
    }

    if(A==1)
        ans--;

    return ans;

}

int main()
{
    sieve();

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        LL A,B;
        scanf("%lld %lld",&A,&B);

        LL uttor=segmented_sieve(A,B);

        printf("Case %d: %d\n",i,uttor);
    }

    return 0;
}

