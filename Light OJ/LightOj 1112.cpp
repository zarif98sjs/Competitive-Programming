
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

void update(int bit[],int index,int val,int n)
{
    index++;

    while(index<=n)
    {
        bit[index] += val;

        index += index & (-index);
    }
}

int getsum(int bit[],int index,int n)
{
    int sum=0;
    index++;

    while(index>0)
    {
        sum += bit[index];
        index -= index & (-index);
    }

    return sum;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        printf("Case %d:\n",i);

        int n,q;
        scanf("%d %d",&n,&q);

        int ara[n+5];
        int BIT[n+5];

        for(int j=0; j<n; j++)
            scanf("%d",&ara[j]);

        //initialize
        for(int j=1; j<=n; j++)
            BIT[j]=0;

        //update
        for(int j=0; j<n; j++)
            update(BIT,j,ara[j],n);


        for(int w=1; w<=q; w++)
        {
            int a;
            scanf("%d",&a);

            if(a==1)
            {
                int x1;
                scanf("%d",&x1);
                printf("%d\n",getsum(BIT,x1,n)-getsum(BIT,x1-1,n));

                int ww = getsum(BIT,x1,n)-getsum(BIT,x1-1,n);
                update(BIT,x1,-1*ww,n);
            }
            else if(a==2)
            {
                int x2,y2;//y2=val
                scanf("%d %d",&x2,&y2);

                update(BIT,x2,y2,n);
            }
            else if(a==3)
            {
                int x3,y3;//y2=val
                scanf("%d %d",&x3,&y3);

                printf("%d\n",getsum(BIT,y3,n)-getsum(BIT,x3-1,n));
            }
        }
    }

    return 0;
}

