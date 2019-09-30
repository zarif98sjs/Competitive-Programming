/* Which of the favors of your Lord will you deny? */

#include<bits/stdc++.h>
using namespace std;

#define MAX 100050

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

int ara[100010];
PII treeMin[400040];
int n;

void buildMin(int node,int start,int end)
{
    if(start==end)
    {
        treeMin[node]=MP(ara[start],start);
        return;
    }

    int lc = 2*node , rc = 2*node+1;
    int mid = (start+end)/2;

    buildMin(lc,start,mid);
    buildMin(rc,mid+1,end);

    if(treeMin[lc].F<=treeMin[rc].F)
        treeMin[node]=treeMin[lc];
    else
        treeMin[node]=treeMin[rc];

}

PII RMinQ(int node,int start,int end,int l,int r)
{
    if(l>end || r<start)
        return MP(INT_MAX,-1);

    if(start>=l && end<=r)
        return treeMin[node];

    int lc = 2*node , rc = 2*node+1;
    int mid = (start+end)/2;

    auto left=RMinQ(lc,start,mid,l,r);
    auto right=RMinQ(rc,mid+1,end,l,r);

    int lq = left.F; //left query
    int rq = right.F;

    int l_idx = left.S;
    int r_idx = right.S;

    if(lq<=rq)
        return MP(lq,l_idx);
    else
        return MP(rq,r_idx);

}

int solve(int left,int right)
{
    //cout<<"left --> "<<left<<" right --> "<<right<<" min_idx --> "<<min_idx<<endl;

    if(left<1 || right >n || left>right)
        return 0;

    auto min_auto=RMinQ(1,1,n,left,right);
    int minn = min_auto.F;
    int min_idx = min_auto.S;

    //cout<<"left --> "<<left<<" right --> "<<right<<" min --> "<<minn<<" min_idx --> "<<min_idx<<endl;

    return max(minn*(right-left+1),max(solve(left,min_idx-1),solve(min_idx+1,right)));
}

int main()
{
    //freopen("LightOj1093.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ara[i]);
        }

        buildMin(1,1,n);

//        int left=1,right=n;
//
//        auto min_auto=RMinQ(1,1,n,left,right);
//        int minn = min_auto.F;
//        int min_idx = min_auto.S;
//
//    cout<<"left --> "<<left<<" right --> "<<right<<" min --> "<<minn<<" min_idx --> "<<min_idx<<endl;
//


        int ans=solve(1,n);

        printf("Case %d: %d\n",q,ans);

    }

    return 0;
}
