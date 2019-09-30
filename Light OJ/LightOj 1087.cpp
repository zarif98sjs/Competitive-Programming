    /* Which of the favors of your lord will you deny  ? */

    #include<bits/stdc++.h>
    using namespace std;

    int ara[200010];
    int value_ara[200010];
    int tree[800040];

    void build(int node,int b,int e)
    {
        if(b==e)
        {
            tree[node]=ara[b];
            return;
        }

        int lc = 2*node , rc = 2*node+1;
        int mid = b+(e-b)/2;

        build(lc,b,mid);
        build(rc,mid+1,e);

        tree[node]=tree[lc]+tree[rc];

    }

    int query(int node,int b,int e,int qb,int qe) //query begin , query end
    {
        if(e<qb || b>qe)
            return 0;
        if(b>=qb && e<=qe)
            return tree[node];

        int lc = 2*node , rc=2*node+1;
        int mid = b+(e-b)/2;

        int p1=query(lc,b,mid,qb,qe);
        int p2=query(rc,mid+1,e,qb,qe);

        return p1+p2;
    }

    void update(int node,int b,int e,int idx,int val)
    {
        if(idx>e || idx<b)
            return ;
        if(b>=idx && e<=idx)
        {
            tree[node]=val;
            return;
        }

        int lc = 2*node , rc=2*node+1;
        int mid = b+(e-b)/2;

        update(lc,b,mid,idx,val);
        update(rc,mid+1,e,idx,val);

        tree[node]=tree[lc]+tree[rc];
    }


    int main()
    {
        //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int tc;
        scanf("%d",&tc);

        for(int i=1;i<=tc;i++)
        {
            //getchar();

            int n,q;
            scanf("%d %d",&n,&q);

            memset(ara,0,sizeof ara);

            for(int j=1;j<=n;j++)
            {
                scanf("%d",&value_ara[j]);
                ara[j]=1;
            }
            getchar();

            printf("Case %d:\n",i);

            int last=2*n;
            build(1,1,last);

            //cout<<"asdasdj"<<endl;

            for(int w=1;w<=q;w++)
            {
                char ch;int v;
                //cin>>ch>>v;
                ch=getchar();
                scanf("%d",&v);
                getchar();

                if(ch=='a')
                {
                    n++;
                    value_ara[n]=v;
                    update(1,1,last,n,1);
                }
                else if(ch=='c')
                {
                    int lo=1,hi=n,mid,ans=0;

                    for(int step=1;step<=20;step++)
                    //while(lo<hi)
                    {
                        //cout<<lo<<" "<<hi<<endl;

                        mid=lo+(hi-lo)/2;
                        int j=query(1,1,last,1,mid);

                        if(j>=v) //v=pos
                            hi=mid-1,ans=mid;
                        else
                            lo=mid+1;

                    }

                    //ans=lo;
                    //cout<<"ans is "<<ans<<endl;

                    if(ans)
                    {
                        printf("%d\n",value_ara[ans]);
                        update(1,1,last,ans,0);
                    }
                    else
                        printf("none\n");

                }
            }

        }

        return 0;
    }


