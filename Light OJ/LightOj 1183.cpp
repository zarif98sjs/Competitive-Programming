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

    struct Node
    {
        LL prop=-1,sum=0;
        //int left,right;
        //bool update_hoise;

    }tree[400040];


    void build(int node,int b,int e)
    {
        if(b==e)
        {
            tree[node].sum=ara[b];
            return;
        }

        int lc = node<<1, rc = (node<<1)+1;
        int mid = b+(e-b)/2;

        build(lc,b,mid);
        build(rc,mid+1,e);

        tree[node].sum=tree[lc].sum+tree[rc].sum;

    }

    void pushdown(int node,int b,int e)
    {
        if(tree[node].prop==-1)
            return;

        int mid=b+(e-b)/2;

        tree[node<<1].sum=(mid-b+1)*tree[node].prop;
        tree[node<<1|1].sum=(e-mid)*tree[node].prop;
        tree[node<<1].prop=tree[node<<1|1].prop=tree[node].prop;

        tree[node].prop=-1;

    }

    void update(int node,int b,int e,int qb,int qe,LL val)
    {
        if(qb>e || qe<b)
            return ;
        if(b>=qb && e<=qe)
        {
            tree[node].sum = (e-b+1)*val;
            tree[node].prop = val;
            return;
        }

        int lc = node<<1 , rc=(node<<1)+1;
        int mid = b+(e-b)/2;

        pushdown(node,b,e);

        update(lc,b,mid,qb,qe,val);
        update(rc,mid+1,e,qb,qe,val);

        tree[node].sum=tree[lc].sum + tree[rc].sum;
    //    if(tree[lc].update_hoise==true && tree[rc].update_hoise==true)
    //        tree[node].sum=tree[lc].sum + tree[rc].sum;
    //    else if(tree[lc].update_hoise==true && tree[rc].update_hoise==false)
    //        tree[node].sum=tree[lc].sum + tree[rc].sum + (tree[rc].right-tree[rc].left+1)*tree[node].prop;
    //    else if(tree[lc].update_hoise==false && tree[rc].update_hoise==true)
    //        tree[node].sum=tree[lc].sum + tree[rc].sum + (tree[lc].right-tree[lc].left+1)*tree[node].prop;

        //tree[node].sum = tree[node].prop*(e-b+1);
    }

    LL query(int node,int b,int e,int qb,int qe) //query begin , query end
    {
        if(e<qb || b>qe)
            return 0;
        if(b>=qb && e<=qe)
            return tree[node].sum;//+ tree[node].prop*(e-b+1);

        int lc = node<<1 , rc=(node<<1)+1;
        int mid = b+(e-b)/2;

        pushdown(node,b,e);

        LL p1=query(lc,b,mid,qb,qe);
        LL p2=query(rc,mid+1,e,qb,qe);

        return p1+p2;
    }

    LL gcd(LL a , LL b)
    {
       if(b==(LL)0) return a;
       a%=b;
       return gcd(b,a);
    }

    int main()
    {
        //freopen("LightOj1093.txt","w",stdout);

        int tc;
        scanf("%d",&tc);

        for(int qq=1; qq<=tc; qq++)
        {
            memset(ara,0,sizeof ara);

            int n,q;
            scanf("%d %d",&n,&q);

            for(int i=0;i<400040;i++)
            {
                tree[i].sum = 0;
                tree[i].prop = -1;
            }

            printf("Case %d:\n",qq);

            for(int i=0;i<q;i++)
            {
                int type;
                scanf("%d",&type);

                if(type==1)
                {
                    int x,y,val;
                    scanf("%d %d %d",&x,&y,&val);
                    update(1,1,n,x+1,y+1,val);
                }

                else
                {
                    int x,y;
                    scanf("%d %d",&x,&y);
                    LL ans=query(1,1,n,x+1,y+1);

                    //cout<<"ans------------->"<<ans<<endl;
                    LL deno=y-x+1;

                    LL g=gcd(ans,deno);
                    ans/=g;
                    deno/=g;

                    if(deno==1)
                        printf("%lld\n",ans);
                    else
                        printf("%lld/%lld\n",ans,deno);
                }
            }


        }

        return 0;
    }

