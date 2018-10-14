
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int>
#define LL long long

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int i=1;i<=tc;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        if((a*a+b*b==c*c)||(a*a+c*c==b*b)||(c*c+b*b==a*a))
            printf("Case %d: yes\n",i);
        else
            printf("Case %d: no\n",i);
    }


    return 0;
}
