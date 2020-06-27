
/**

If we need to find the answer between L and R index, then we can do the following

Let i be the index of any maximum element in range L to R. There are three possiblities

    The optimal subarray lies from L to i - 1
    The optimal subarray lies from i + 1 to R
    It include element at index i and therfore maximum of this subarray will be element at index i.

Now first two cases are recursion and for the third you need to find the maximum prefix sum for range i + 1 to R and maximum suffix sum for range L to i - 1. So these queries (maximum index, maximum suffix sum, maximum prefix sum) can be done by segment tree. The merging step will take O(logN) time and therefore even though our problem doesn't always reduce into two equal halves, we will achieve a time complexity of O(NlogN).

**/

/** Which of the favors of your Lord will you deny ? **/

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
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

const int nmax = 1e5+7;
const int nmax2 = nmax<<2;

struct node
{
    int pfx,sfx,sum,mx,mx_id;

    node()
    {
        sum=pfx=sfx=mx=mx_id=0;
    }

    void merge_nodes(node &A,node &B)
    {
        sum = A.sum + B.sum;
        pfx = max(A.pfx, A.sum+B.pfx);
        sfx = max(B.sfx, A.sfx+B.sum);
        if(A.mx>B.mx)
        {
            mx = A.mx;
            mx_id = A.mx_id;
        }
        else
        {
            mx = B.mx;
            mx_id = B.mx_id;
        }
    }

    void create_leaf(int val)
    {
        sum=pfx=sfx=mx=val;
    }
    void create_leaf2(int val)
    {
       mx_id = val;
    }

};

LL ara[nmax];

node Tree[nmax2];

void build(int node,int start,int end)
{
    if(start==end)
    {
        Tree[node].create_leaf(ara[start]);
        Tree[node].create_leaf2(start);
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
    if(l>r)
        return;

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

int calc(int l,int r,int n)
{
    if(l>r) return 0;

    node temp,v1,v2;
    query(temp,1,1,n,l,r);

//    DBG(temp.mx_id);

    query(v1,1,1,n,l,temp.mx_id-1);
    query(v2,1,1,n,temp.mx_id+1,r);

    int cl = calc(l,temp.mx_id-1,n);
    int cr = calc(temp.mx_id+1,r,n);

    vector<int>v;

    v.push_back(cl);
    v.push_back(cr);
    v.push_back(max(0,v1.sfx)+max(0,v2.pfx));
//    v.push_back(v1.sfx+v2.pfx));

    int ans = 0;

    for(int x:v)
        ans = max(ans,x);

    return ans;

}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>ara[i];

    build(1,1,n);

    cout<<calc(1,n,n)<<endl;

    return 0;
}

/**

**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(int i=0; i<v.size(); i++)
    {
        os<<v[i]<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


