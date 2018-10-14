
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
        int m,l;
        scanf("%d %d",&m,&l);

        int ans=abs(m-l)*4+m*4+ 2*3 + 2*5 + 3;
        printf("Case %d: %d\n",i,ans);
    }

    return 0;
}
