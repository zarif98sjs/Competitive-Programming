
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair

LL sum(LL n)
{
    return (n*(n+1))/2;
}

LL CSOD(LL num)
{
    LL ans=0;
    LL nod=0;
    LL u=sqrt(num);

    for(LL i=2;i<=u;i++)
    {
        nod = (num/i)-i;
        ans += nod*i;
        ans += (sum(num/i)-sum(i));
        ans += i;

        //cout<<"ans "<<ans<<endl;
    }

    //nod *= 2;
    //nod +=u;
    //ans +=

    return ans;
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int q=1;q<=tc;q++)
    {
        LL num;
        scanf("%lld",&num);

        printf("Case %d: %lld\n",q,CSOD(num));

    }

    return 0;
}
