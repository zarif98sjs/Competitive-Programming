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
    int treeMax[400040];
    int treeMin[400040];

    void buildMax(int node,int start,int end)
    {
        if(start==end)
        {
            treeMax[node]=ara[start];
            return;
        }

        int lc = 2*node , rc = 2*node+1;
        int mid = (start+end)/2;

        buildMax(lc,start,mid);
        buildMax(rc,mid+1,end);

        if(treeMax[lc]>treeMax[rc])
            treeMax[node]=treeMax[lc];
        else
            treeMax[node]=treeMax[rc];

    }

    void buildMin(int node,int start,int end)
    {
        if(start==end)
        {
            treeMin[node]=ara[start];
            return;
        }

        int lc = 2*node , rc = 2*node+1;
        int mid = (start+end)/2;

        buildMin(lc,start,mid);
        buildMin(rc,mid+1,end);

        if(treeMin[lc]<treeMin[rc])
            treeMin[node]=treeMin[lc];
        else
            treeMin[node]=treeMin[rc];

    }

    int RMinQ(int node,int start,int end,int l,int r)
    {
        if(l>end || r<start)
            return INT_MAX;

        if(start>=l && end<=r)
            return treeMin[node];

        int lc = 2*node , rc = 2*node+1;
        int mid = (start+end)/2;

        int lq = RMinQ(lc,start,mid,l,r); //left query
        int rq = RMinQ(rc,mid+1,end,l,r);

        if(lq<rq)
            return lq;
        else
            return rq;

    }

    int RMaxQ(int node,int start,int end,int l,int r)
    {
        if(l>end || r<start)
            return 0;

        if(start>=l && end<=r)
            return treeMax[node];

        int lc = 2*node , rc = 2*node+1;
        int mid = (start+end)/2;

        int lq = RMaxQ(lc,start,mid,l,r); //left query
        int rq = RMaxQ(rc,mid+1,end,l,r);

        if(lq>rq)
            return lq;
        else
            return rq;

    }

    int main()
    {
        //freopen("LightOj1093.txt","w",stdout);

        int tc;
        scanf("%d",&tc);

        for(int q=1; q<=tc; q++)
        {
            int n,d,x;
            scanf("%d %d",&n,&d);

            for(int i=1; i<=n; i++)
            {
                scanf("%d",&ara[i]);
            }

            buildMax(1,1,n);
            buildMin(1,1,n);

            int maxx=0;

            for(int i=1;i<=n-d;i++)
            {
                int v1=RMaxQ(1,1,n,i,i+d-1);
                int v2=RMinQ(1,1,n,i,i+d-1);

                //cout<<"v1 -> "<<v1<<" v2-> "<<v2<<endl;

                maxx=max(maxx,v1-v2);

            }

            printf("Case %d: %d\n",q,maxx);

        }

        return 0;
    }

