
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

int ara[150];

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        int n,time=0,cnt_pos=0;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ara[i]);
            time+=abs(ara[i]);
            if(ara[i]>0)
                cnt_pos++;
        }

        int lob = time;
        int hor = cnt_pos;

        //cout<<lob<<" "<<hor<<endl;

        int bhag = __gcd(lob,hor);

        while(bhag>1)
        {
            lob=lob/bhag;
            hor=hor/bhag;

            bhag = __gcd(lob,hor);
        }

        if(cnt_pos==0)
            printf("Case %d: inf\n",q);
        else
            printf("Case %d: %d/%d\n",q,lob,hor);

    }

    return 0;
}

