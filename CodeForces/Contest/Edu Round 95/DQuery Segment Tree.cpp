
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

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

struct LazySegmentTree
{
    struct node
    {
        LL sum ;
        LL lazy;

        node()
        {
            sum = 0;
            lazy = 0;
        }

        void create_leaf(LL val)
        {
            sum = val;
            lazy = 0;
        }

        void merge_nodes(node &A,node &B)
        {
            sum = A.sum + B.sum;
        }

    };

    vector<node>Tree;
    vector<int>ara;
    int n;

    LazySegmentTree(int n)
    {
        this->n = n;
        int len = n+1;
        ara = vector<int>(len);
        Tree = vector<node>(len<<2);
    }

    void update(int L,int R,LL add)
    {
        __update(1,1,n,L,R,add);
    }

    LL query(int L,int R)
    {
        return __query(1,1,n,L,R);
    }

    void node_update(int v,int st,int en,LL add)
    {
        Tree[v].sum += (en-st+1)*add; /** Multiplying the size of the current node **/
        Tree[v].lazy += add;
    }

    void push(int v,int st,int en)
    {
        int mid = (st+en)>>1;
        int lc = v<<1, rc = lc|1;

        if(Tree[v].lazy)
        {
            node_update(lc,st,mid,Tree[v].lazy);   /** Multiplying the size of the left node with the parent's lazy value **/
            node_update(rc,mid+1,en,Tree[v].lazy); /** Multiplying the size of the right node with the parent's lazy value **/

            Tree[v].lazy = 0;
        }
    }

    void __update(int cur, int start, int end, int l,int r, LL add)
    {
        if(l>r)
            return;

        if (l==start && r==end)
        {
            node_update(cur,start,end,add);
        }
        else
        {
            int mid = (start + end)>>1;
            int lc = cur<<1, rc = lc|1;

            push(cur,start,end); /** Pushdown to children node **/

            __update(lc, start, mid,l,min(r,mid), add);
            __update(rc, mid+1, end,max(l,mid+1),r, add);

            Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
        }
    }

    LL __query(int cur,int start,int end,int l,int r) /** RANGE query **/
    {
        if(l>r)
            return 0;

        if(start>=l && end<=r)
        {
            return Tree[cur].sum;
        }

        int mid = (start+end)>>1;
        int lc = cur<<1, rc = lc|1;

        push(cur,start,end); /** Pushdown to children node **/

        LL p1 = __query(lc,start,mid,l,min(r,mid));
        LL p2 = __query(rc,mid+1,end,max(l,mid+1),r);

        return p1+p2; /// sum

    }

};



int32_t main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int>v(n+1);
    for(int i=1; i<=n; i++)
        cin>>v[i];

    int max_num = 1e6+5;
    vector<int>last(max_num,0);

    int q;
    cin>>q;

    vector<vector<PII>>queries(n+1);

    for(int i=0; i<q; i++)
    {
        int l,r;
        cin>>l>>r;

        queries[r].push_back({l,i});
    }


    LazySegmentTree LST(n);

    vector<int>ans(q);

    for(int i=1; i<=n; i++)
    {
        int L = last[v[i]]+1;
        int R = i;

        last[v[i]] = i;

        LST.update(L,R,1);

        for(auto x:queries[i])
        {
            ans[x.S] = LST.query(x.F,x.F);
        }
    }

    for(int x:ans)
        cout<<x<<endl;

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
    for(T i:v)
    {
        os<<i<<" " ;
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

