
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

int arax[800];
int aray[800];
double slope[800];

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        int n,maxx=0;
        double baka,baka2;
        scanf("%d",&n);

        for(int j=1; j<=n; j++)
        {
            scanf("%d %d",&arax[j],&aray[j]);
        }

        for(int j=1; j<=n; j++)
        {
            int x = arax[j];
            int y = aray[j];

            int w=1;

            for(int k=1; k<=n; k++)
            {
                if(k==j)
                    continue;

                int x2 = arax[k];
                int y2 = aray[k];

                if(x2-x==0)
                    baka=(double)INT_MAX;
                else
                    baka = ((y2-y)*1.0)/(x2-x);

                //printf("!! %lf\n",baka);

                slope[w]=baka;
                w++;

            }

            w--;

            sort(slope+1,slope+w+1);

            //for(int r=1;r<=w;r++)
            //  printf("%lf ",slope[r]);
            int cnt=2;
            for(int r=1; r<w; r++)
            {
                //if(abs(slope[r+1]-slope[r])<=1e-7)
                if(fabs(slope[r+1]-slope[r])<=1e-10)
                {
                    cnt++;
                    //printf("** %lf %lf\n",slope[r],slope[r+1]);
                }
                else
                {
                    if(cnt>maxx)
                        maxx=cnt;

                    cnt=2;
                }


            }

            if(cnt>maxx)
                maxx=cnt;


        }

        if(n<=2)
            printf("Case %d: %d\n",i,n);
        else
            printf("Case %d: %d\n",i,maxx);

    }


    return 0;
}
