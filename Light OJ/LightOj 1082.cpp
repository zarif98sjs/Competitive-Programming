
/* Which of the favors of your lord will you deny  ? */

#include<bits/stdc++.h>
using namespace std;

int ara[100010];
int tree[400040];

void build(int node,int start,int end)
{
    if(start==end)
    {
        tree[node]=ara[start];
        return;
    }

    int lc = 2*node , rc = 2*node+1;
    int mid = (start+end)/2;

    build(lc,start,mid);
    build(rc,mid+1,end);

    if(tree[lc]<tree[rc])
        tree[node]=tree[lc];
    else
        tree[node]=tree[rc];

}

int RMinQ(int node,int start,int end,int l,int r)
{
    if(l>end || r<start)
        return INT_MAX;

    if(start>=l && end<=r)
        return tree[node];

    int lc = 2*node , rc = 2*node+1;
    int mid = (start+end)/2;

    int lq = RMinQ(lc,start,mid,l,r); //left query
    int rq = RMinQ(rc,mid+1,end,l,r);

    if(lq<rq)
        return lq;
    else
        return rq;

}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int i=1;i<=tc;i++)
    {
        int n,q;
        scanf("%d %d",&n,&q);

        for(int j=1;j<=n;j++)
            scanf("%d",&ara[j]);

        printf("Case %d:\n",i);

        build(1,1,n);

        //cout<<"asdasdj"<<endl;

        int l,r;

        for(int w=1;w<=q;w++)
        {
            scanf("%d %d",&l,&r);
            int minn = RMinQ(1,1,n,l,r);
            printf("%d\n",minn);
        }

    }

    return 0;
}
