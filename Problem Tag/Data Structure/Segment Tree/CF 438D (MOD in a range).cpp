
/**

DATA STRUCTURE : SEGMENT TREE

If you apply modulo operation to some number x, x' = x mod p, there are two cases either x' = x (when x < p) or x' < p <= x (when x >= p).

Now, think about the second case, which changes the current value of x.
When the second case applies, the value of x gets at least halved.
So, if you keep applying modulo operation to some number x, how many times it’s value will be changed? At most logx times.
After that, x will become zero and no further change will be applied to it.

We will use this idea to solve the problem. Write a segment which maintains sum and max.
When we are doing an update modulo p, if we see that current node’s max < p we will proceed no further.
In this way, we will visit only the relevant indices where the values are actually being changed.
The complexity will be NlogNlog1e9.

**/

/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;
const LL LINF = 1e17;

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

LL ara[nmax];

/** Segment Tree **/

struct node
{
    LL sum , maxx;

    void create_leaf(LL val)
    {
        sum=val , maxx= val;
    }

    void merge_nodes(node &A,node &B)
    {
        sum = A.sum + B.sum;
        maxx = max(A.maxx,B.maxx);
    }
};

const int nmax2 = nmax<<2;
node Tree[nmax2];

void build(int cur,int start,int end) /** build the segment tree **/
{
    if(start==end)
    {
        Tree[cur].create_leaf(ara[start]);
        return;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    build(lc,start,mid);
    build(rc,mid+1,end);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);

}

void update(int cur, int start, int end, int updex, LL value) /** POINT update , replaces the current value **/
{
    if (start == end)
    {
        Tree[cur].create_leaf(value);
        return;
    }

    int mid = (start + end)>>1;
    int lc = cur<<1, rc = lc|1;

    if (updex <= mid)
        update(lc, start, mid, updex, value);
    else
        update(rc, mid+1, end, updex, value);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
}

void MODupdate(int cur, int start, int end, int l,int r,LL mo) /** POINT update , replaces the current value **/
{
    if(end<l || start>r)
        return;

    if(Tree[cur].maxx<mo) /** imp **/
        return;

    if (start == end)
    {
        ara[start] %= mo; /** imp **/
        Tree[cur].create_leaf(ara[start]);
        return;
    }

    int mid = (start + end)>>1;
    int lc = cur<<1, rc = lc|1;

    MODupdate(lc, start, mid, l, r, mo);
    MODupdate(rc, mid+1, end, l, r, mo);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
}

void query(node &res,int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(start>=l && end<=r)
    {
        res = Tree[cur];
        return;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

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
    optimizeIO();

    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>ara[i];
    }

    build(1,1,n);

    while(q--)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            int l,r;
            cin>>l>>r;

            node ans;
            query(ans,1,1,n,l,r);
            cout<<ans.sum<<endl;
        }
        else if(type==2)
        {
            int l,r;
            LL mo;
            cin>>l>>r>>mo;

            MODupdate(1,1,n,l,r,mo);

        }
        else
        {
            int idx;
            LL val;
            cin>>idx>>val;

            ara[idx] = val; /** imp **/
            update(1,1,n,idx,val);
        }
    }

    return 0;
}
