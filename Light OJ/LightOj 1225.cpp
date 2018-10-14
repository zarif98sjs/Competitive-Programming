
/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int j=1; j<=tc; j++)
    {
        char num[100];

        scanf("%s",num);
        int cnt = 0;
        int len = strlen(num);

        for(int i=0; i<(len+1)/2; i++)
        {
            if(num[i]==num[len-i-1])
                cnt++;
            else
                break;
        }

        //cout<<cnt<<" "<<(len+1)/2<<endl;

        if(cnt==(len+1)/2)
            printf("Case %d: Yes\n",j);
        else
            printf("Case %d: No\n",j);

    }



    return 0;
}
