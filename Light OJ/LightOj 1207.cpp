/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000050

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

//int ara[MAX];
set<int>S;

struct Node
{
    int prop,sum;

}tree[4*MAX];

void pushdown(int node)
{
    if(tree[node<<1].sum<tree[node].sum) tree[node<<1].sum=tree[node].sum;
    if(tree[node<<1|1].sum<tree[node].sum) tree[node<<1|1].sum=tree[node].sum;

    tree[node].sum=0;
}

void update(int node,int b,int e,int qb,int qe,int val)
{
    if(qb>e || qe<b)
        return ;
    if(b>=qb && e<=qe)
    {
          tree[node].sum = val;
//        tree[node].prop += val;
        return;
    }

    int lc = node<<1 , rc=node<<1|1;
    int mid = b+(e-b)/2;

//    if(tree[node].sum)
//        return;
    pushdown(node);

    if(qb<=mid) update(lc,b,mid,qb,qe,val);
    if(qe>mid) update(rc,mid+1,e,qb,qe,val);

    //tree[node].sum=tree[lc].sum + tree[rc].sum + tree[node].prop*(e-b+1);
}



void query(int node,int b,int e)
{
    if(b==e)
    {
        //printf("%d ",tree[node].sum);
        if(tree[node].sum!=0) S.insert(tree[node].sum);
        return;
    }

    pushdown(node);

    int lc = node<<1 , rc=node<<1|1;
    int mid = b+(e-b)/2;

    query(lc,b,mid);
    query(rc,mid+1,e);
}

int vl[MAX];
int vr[MAX];

int main()
{
    //freopen("LightOj1207.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int qq=1; qq<=tc; qq++)
    {
        memset(vl,0,sizeof vl);
        memset(vr,0,sizeof vr);
        S.clear();

        int q;
        scanf("%d",&q);

        for(int i=0;i<4*MAX;i++)
            tree[i].sum = 0;

        int maxx=0;

        for(int i=1;i<=q;i++)
        {
            int l,r;
            scanf("%d %d",&vl[i],&vr[i]);

            maxx=max(maxx,vr[i]);

            //update(1,1,n,l,r,i);
        }

        int n=maxx;

        for(int i=1;i<=q;i++)
        {
            int l=vl[i],r=vr[i];
            update(1,1,n,l,r,i);
        }

        query(1,1,n);
        int ans=S.size();

        printf("Case %d: %d\n",qq,ans);
    }

    return 0;
}
