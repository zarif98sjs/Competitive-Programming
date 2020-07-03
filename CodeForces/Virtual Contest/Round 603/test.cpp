
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

const int nmax = 1e6+5;
const int nmax2 = nmax<<2;

string s;
int n;

struct node
{
    int left,right;

    void merge_nodes(node &a,node &b)
    {
        int matched = min(a.left,b.right);
        left = a.left + b.left - matched;
        right = a.right + b.right - matched;
    }

    void create_leaf(char ch)
    {
        if(ch=='(') left = 1 , right = 0;
        else if(ch==')') left = 0 , right = 1;
        return;
    }

};

node Tree[nmax2];

void build(int cur,int start,int end)
{
    if(start==end)
    {
        Tree[cur].create_leaf(s[start]);
        return;
    }

    int lc = 2*cur, rc = 2*cur+1;
    int mid = (start+end)/2;

    build(lc,start,mid);
    build(rc,mid+1,end);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);

}

void query(node &res,int cur,int start,int end,int l,int r)
{
    if(start>=l && end<=r)
    {
        res = Tree[cur];
        return;
    }

    int lc = 2*cur, rc = 2*cur+1;
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
    optimizeIO();

    cin>>s;
    s = "#" + s;

    n = s.size();

    build(1,1,n);

    int q;
    cin>>q;

    while(q--)
    {
        int l , r;
        cin>>l>>r;

        node temp;
        query(temp,1,1,n,l,r);

        DBG(temp.left);
        DBG(temp.right);

        int res = (r-l+1) - (temp.left+temp.right);
        cout<<res<<endl;
    }

    return 0;
}
