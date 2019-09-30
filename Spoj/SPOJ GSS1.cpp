
/*Which of the favors of your Lord will you deny ?*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 50007;
const int nmax2 = nmax<<2;

struct node
{
    LL pfx,sfx,sum,maxx;

    void merge_nodes(node &A,node &B)
    {
        sum = A.sum + B.sum;
        pfx = max(A.pfx, A.sum+B.pfx);
        sfx = max(B.sfx, A.sfx+B.sum);
        maxx = max(max(A.maxx,B.maxx),A.sfx + B.pfx);
    }

    void create_leaf(LL val)
    {
        sum=pfx=sfx=maxx=val;
    }

};

LL ara[nmax];

node Tree[nmax2];

void build(int node,int start,int end)
{
    if(start==end)
    {
        Tree[node].create_leaf(ara[start]);
        return;
    }

    int lc = 2*node, rc = 2*node+1;
    int mid = (start+end)/2;

    build(lc,start,mid);
    build(rc,mid+1,end);

    Tree[node].merge_nodes(Tree[lc],Tree[rc]);

}

void query(node &res,int idx,int start,int end,int l,int r)
{
    if(start>=l && end<=r)
    {
        res = Tree[idx];
        return;
    }

    int lc = 2*idx, rc = 2*idx+1;
    int mid = (start+end)/2;

    if(r<=mid)
        query(res,lc,start,mid,l,r);
    else if(l>mid)
        query(res,rc,mid+1,end,l,r);
    else
    {
        node left,right;
        query(left,lc,start,mid,l,r);
        query(right,rc,mid+1,end,l,r);
        res.merge_nodes(left,right);
    }
}


int main()
{
    //freopen("GSS1.txt","w",stdout);

    int n,m,t,x,y;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>ara[i];

    build(1,1,n);

    cin>>t;
    node Ans;

    while(t--)
    {
        cin>>x>>y;
        query(Ans,1,1,n,x,y);
        cout<<Ans.maxx<<"\n";
    }

    return 0;
}
