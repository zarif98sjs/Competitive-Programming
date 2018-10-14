
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair

int bigMod(int x,int n,int mo)
{
    if(n==0)
        return 1;

    int u = bigMod(x,n/2,mo);

    u = ((u%mo)*(u%mo))%mo;
    if(n%2==1)
        u = ((u%mo)*(x%mo))%mo;

    return u;
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int i=1;i<=tc;i++)
    {
        int n,k;
        scanf("%d %d",&n,&k);

        int last=bigMod(n,k,1000);

        double a=k*log10(n);
        double y = a-(int)a;

        double yy=pow(10,y)*100.0;

        printf("Case %d: %d %03d\n",i,(int)yy,last);

    }

    return 0;
}
