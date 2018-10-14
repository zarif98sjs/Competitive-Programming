
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        int n;
        scanf("%d",&n);

        int nimsum=0,p,cnt1=0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&p);

            if(p==1)
                cnt1++;

            nimsum=nimsum^p;
        }

        //cout<<nimsum<<endl;

        if(cnt1==n)
        {
            if(cnt1%2==1)
                printf("Case %d: Bob\n",i);
            else
                printf("Case %d: Alice\n",i);

        }

        else
        {
            if(nimsum!=0)
                printf("Case %d: Alice\n",i);
            else
                printf("Case %d: Bob\n",i);

        }
    }

    return 0;
}
