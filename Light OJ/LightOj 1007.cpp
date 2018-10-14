
/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define SI(n)    scanf("%d",&n)
#define SLL(n)   scanf("%lld",&n)
#define SC(n)    scanf("%c",&n)
#define SD(n)    scanf("%lld",&n)

#define fr(i,a,b) for(int i=a ,_b=(b) ;i<= _b;i++)

#define LL      long long
#define PUB     push_back
#define POB     pop_back
#define MP      make_pair;
#define PII     pair<int,int>
#define PLL     pair<ll,ll>

#define GCD     __gcd

//vector<int> vec[5000005];
bool isP[5000005];
//unsigned LL ara[5000005];
unsigned LL tot[5000005];

//int d = sqrt(5000005);
int x = 5000000;

void initialize()
{
    for(int j=1; j<=x; j++)
    {
        isP[j]=true;
        tot[j]=j;
    }

}

void sieve()
{
    for(int i=2; i<=x; i++)
    {
        if(isP[i]==true)
        {

            tot[i] = (tot[i]/i)*(i-1); //for handling prime number cases

            for(int j=2; i*j<=x; j++)
            {
                isP[i*j] = false;

                tot[i*j] = (tot[i*j]/i)*(i-1);
            }
        }
    }
}

int main()
{
    int t,a,b;
    SI(t);
    //cin>>t;

    initialize();
    sieve();

    fr(i,2,x)
    {
       // LL y = calcTot(i);
        unsigned LL y = tot[i]*tot[i];

        tot[i] = tot[i-1] + y;

        //ara[i] = ara[i-1]+y;
    }

    fr(i,1,t)
    {

        //cin>>a>>b;
        SI(a),SI(b);
        unsigned LL alu = tot[b]-tot[a-1];

        printf("Case %d: %llu\n",i,alu);

        /*int qq;
        cin>>qq;
        cout<<tot[qq]<<endl;
        */

    }
    return 0;
}
