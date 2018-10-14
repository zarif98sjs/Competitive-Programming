
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

int main()
{
    //freopen("LOJ1214.txt","w",stdout);

    int tc;
    SI(tc);

    fr(j,1,tc)
    {
        char num[1000];
        int div;

        scanf("%s",num);
        SI(div);

        LL now = num[0]-'0',i=0;

        if(num[0]=='-')
            i=1,now = num[1]-'0';

        if(div<0)
            div = div*(-1);

        for( ; i<strlen(num); i++)
        {

            if(now/div!=0)
            {
                now = now%div;
                if(num[i+1]!='\0')
                {
                    now = now*10+(num[i+1]-'0');

                    //cout<<"**"<<now<<endl;
                }

                //cout<<"##"<<now<<endl;
            }
            else // now/div=0
            {
                //cout<<":)"<<num[i+1]<<endl;

                if(num[i+1]!='\0')
                {
                    now = now*10 + (num[i+1]-'0');
                    //cout<<"@@@"<<now<<endl;

                }

            }

        }

        if(now==0)
            printf("Case %d: divisible\n",j);
        else
            printf("Case %d: not divisible\n",j);

    }

    return 0;
}
