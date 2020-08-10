
/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int BIT[MAX];

void update(int index,int val,int len)
{
    index++;

    while(index<=len)
    {
        BIT[index] += val;
        index += index&(-index);
    }
}

int query(int index)
{
    index++;
    int sum=0;
    while(index>0)
    {
        sum += BIT[index];
        index -= index&(-index);
    }
    return sum;
}


int main()
{
    int tc;
    scanf("%d",&tc);

    for(int i=1; i<=tc; i++)
    {
        printf("Case %d:\n",i);

        char ara[MAX];
        fill(BIT,BIT+MAX,0);

        scanf("%s",ara);
        int len = strlen(ara);

        int ask;
        scanf("%d",&ask);

        for(int j=1;j<=ask;j++)
        {
            char ch;
            scanf(" %c",&ch);

            if(ch=='I')
            {
                int lo,hi;
                scanf("%d %d",&lo,&hi);
                lo--;
                hi--;
                update(lo,1,len);
                update(hi+1,-1,len);
            }
            else if(ch=='Q')
            {
                int qu;
                scanf("%d",&qu);
                qu--;

                if(query(qu)%2==1)
                {
                    if(ara[qu]=='0')
                        printf("1");
                    else
                        printf("0");
                }
                else
                    printf("%c",ara[qu]);

                printf("\n");

            }
        }

    }

   return 0;
}
