
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int>
#define LL long long

int powa(int x,int n)
{
    if(n==0)
        return 1;
    int u=powa(x,n/2);
    u=u*u;
    if(n%2==1)
        u=u*x;
    return u;
}

vector<int>ara;

int main()
{
    //freopen("outLOJ1133.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int t=1; t<=tc; t++)
    {
        int n,q;
        scanf("%d %d",&n,&q);

        ara.clear();

        for(int i=0; i<n; i++)
        {
            int v;
            scanf("%d",&v);
            ara.push_back(v);
        }
        //scanf("%d",&ara[i]);

        for(int i=1; i<=q; i++)
        {
            //cout<<"npoooooo"<<endl;


            char ch;
            //getchar();
            //fflush(stdin);
            scanf(" %c",&ch);

            if(ch=='S')
            {
                int a;
                scanf("%d",&a);

                for(int j=0; j<n; j++)
                {
                    ara[j]+=a;
                }

            }

            if(ch=='M')
            {
                int a;
                scanf("%d",&a);

                for(int j=0; j<n; j++)
                {
                    ara[j]*=a;
                }

            }

            if(ch=='D')
            {
                int a;
                scanf("%d",&a);

                for(int j=0; j<n; j++)
                {
                    ara[j]/=a;
                }

            }

            if(ch=='R')
                reverse(ara.begin(),ara.end());
            if(ch=='P')
            {
                int a,b;
                scanf("%d %d",&a,&b);
                swap(ara[a],ara[b]);
            }

        }

        printf("Case %d:\n",t);

        for(int ee=0; ee<n; ee++)
        {
            if(ee==n-1)
                printf("%d",ara[ee]);
            else
                printf("%d ",ara[ee]);
        }


        printf("\n");

    }

    return 0;
}



