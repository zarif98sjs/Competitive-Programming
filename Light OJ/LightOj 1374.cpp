
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 10010

int cnt[MAX];
int ara[MAX];

int main()
{
    //freopen("Long2Q.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        //printf("Case %d: ",i);

        fill(cnt,cnt+MAX,0);
        int n;
        scanf("%d",&n);

        for(int j=1; j<=n; j++)
        {
            scanf("%d",&ara[j]);
            if(ara[j]<n)
                cnt[ara[j]]++;
            //maxx=max(maxx,ara[j]);
        }

        int flag=0;

        for(int j=0; j<n; j++)
        {
            if(cnt[j]>2)
            {
                flag=1;
                //cout<<"flaggg"<<endl;
                //cout<<cnt[j]<<" "<<ara[j]<<endl;
                break;
            }

            if(cnt[j]+cnt[n-j-1]!=2)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
            printf("Case %d: no\n",i);
        else
            printf("Case %d: yes\n",i);

    }

    return 0;
}
