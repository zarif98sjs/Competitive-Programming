
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

const int INF = 1e9;

struct node
    {
        PLL mx;
        LL lazy;

        node()
        {
            mx = {-INF,0};
            lazy = 0;
        }

        node(PLL mx)
        {
            this-> mx = mx;
            lazy = 0;
        }

        void create_leaf(LL val)
        {
            mx = {val,1};
            lazy = 0;
        }
    };

struct LazySegmentTree
{
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

    void build()
    {
        __build(1,1,n);
    }

    void update(int L,int R,LL add)
    {
        __update(1,1,n,L,R,add);
    }

    node query(int L,int R)
    {
        return __query(1,1,n,L,R);
    }

    /**-------------------------------------**/

    node merge_nodes(node &A,node &B)
    {
        if(A.mx.F>B.mx.F)
            return A;
        else if(A.mx.F<B.mx.F)
            return B;
        else
            return node({A.mx.F,A.mx.S+B.mx.S});
    }

    void node_update(int v,LL add)
    {
        Tree[v].mx.F += add;
        Tree[v].lazy += add;
    }

    void push(int v,int st,int en)
    {
        int lc = v<<1, rc = lc|1;

        if(st != en)
        {
            node_update(lc,Tree[v].lazy);
            node_update(rc,Tree[v].lazy);
        }

        Tree[v].lazy = 0;
    }

    void __build(int cur,int start,int end) /** build the segment tree **/
    {
        if(start==end)
        {
            Tree[cur].create_leaf(0);
            return;
        }

        int mid = (start+end)>>1;
        int lc = cur<<1, rc = lc|1;

        __build(lc,start,mid);
        __build(rc,mid+1,end);

        Tree[cur] = merge_nodes(Tree[lc],Tree[rc]);
    }

    void __update(int cur, int start, int end, int l,int r, LL add)
    {
        if(l>r)
            return;

        if (l==start && r==end)
        {
            node_update(cur,add);
        }
        else
        {
            int mid = (start + end)>>1;
            int lc = cur<<1, rc = lc|1;

            push(cur,start,end); /** Pushdown to children node **/

            __update(lc, start, mid,l,min(r,mid), add);
            __update(rc, mid+1, end,max(l,mid+1),r, add);

            Tree[cur] = merge_nodes(Tree[lc],Tree[rc]);
        }
    }

    node __query(int cur,int start,int end,int l,int r) /** RANGE query **/
    {
        if(l>r) return node({-INF,0});

        if(start>=l && end<=r)
        {
            return Tree[cur];
        }

        int mid = (start+end)>>1;
        int lc = cur<<1, rc = lc|1;

        push(cur,start,end); /** Pushdown to children node **/

        node p1 = __query(lc,start,mid,l,min(r,mid));
        node p2 = __query(rc,mid+1,end,max(l,mid+1),r);

        return merge_nodes(p1,p2);

    }

};

void UNDO(int x, LazySegmentTree &lst, vector<vector<int>> &pos)
{
    int sz = pos[x].size();
    if(sz<4)
        return;

    int L = pos[x][sz-4]+1;
    int R = pos[x][sz-3];

    lst.update(L,R,-1);
}

void DO(int x, LazySegmentTree &lst, vector<vector<int>> &pos)
{
    int sz = pos[x].size();
    if(sz<4)
        return;

    int L = pos[x][sz-4]+1;
    int R = pos[x][sz-3];

    lst.update(L,R,+1);
}

int32_t main()
{
    optimizeIO();

    int n;
    cin>>n;

    LazySegmentTree LST(n);
    LST.build();

    vector<int>v(n+1);
    for(int i=1; i<=n; i++)
        cin>>v[i];

    int max_num = n+1;
    vector<int>last(max_num,0);

    vector<vector<int>>pos(max_num);

    node q = LST.query(1,n);
    DBG(q.mx);

    int ans = 0;

    for(int i=1; i<=n; i++)
    {
        int el = v[i];

        if(pos[el].empty())
            pos[el].push_back(0);

        UNDO(el,LST,pos);
        pos[el].push_back(i);
        DO(el,LST,pos);

        int L = last[el]+1;
        int R = i;

        last[el] = i;

        LST.update(L,R,-1);

        node q = LST.query(1,i);
        DBG(q.mx);

        if(q.mx.F==0) ans += q.mx.S;
    }

    cout<<ans<<endl;

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

