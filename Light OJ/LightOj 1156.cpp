
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

pair<int,char> ara[150];
bool mark[150];

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        fill(mark,mark+120,0);

        int n,D;
        char ch;
        scanf("%d %d",&n,&D);

        ara[1].first=0;
        ara[1].second='X';
        ara[n+2].first=D;
        ara[n+2].second='X';

        for(int i=1; i<=n; i++)
        {
            scanf(" %c",&ara[i+1].second);
            getchar();
            scanf("%d",&ara[i+1].first);

            //printf("**%c %d\n",ara[i+1].second,ara[i+1].first);
        }

        int maxx=-1,val=-1;

        for(int i=1; i<n+2; i++)
        {
            if(ara[i].second=='S'&&ara[i+1].second=='S')
            {
                val=ara[i+2].first-ara[i].first;
                if(ara[i].second=='S')
                    mark[i]=1;
                if(ara[i+2].second=='S')
                    mark[i+2]=1;

                i++;
            }
            else
            {
                val = ara[i+1].first-ara[i].first;
                if(ara[i].second=='S')
                    mark[i]=1;
                if(ara[i+1].second=='S')
                    mark[i+1]=1;
            }


            //cout<<" * "<<val<<endl;

            if(val>maxx)
                maxx = val;
        }

        for(int i=2,j=1; i<=n+2; i++)
        {
            //cout<<" !! "<<ara[i].first<<endl;

            /*if(ara[i].second=='B' && ara[i+1].second=='S')
            {
                val=ara[i+2].first-ara[i].first;
                i++;
            }
            else if(ara[i].second=='S' && ara[i+1].second=='S')
            {
                val=ara[i+2].first-ara[i].first;
                i++;
            }
            else if(ara[i].second=='S')
                continue;*/

            //cout<<" i ara[i] mark[i] "<<i<<" "<<ara[i].first<<" "<<mark[i]<<endl;
            if(!mark[i])
            {
                val = ara[i].first-ara[j].first;
                //cout<<" here "<<ara[i].first<<" "<<ara[j].first<<endl;
                j=i;
            }

            //cout<<" ** "<<val<<endl;

            if(val>maxx)
                maxx = val;
        }

        printf("Case %d: %d\n",q,maxx);

    }

    return 0;
}
