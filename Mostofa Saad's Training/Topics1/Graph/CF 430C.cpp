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

const int nmax = 2e5+7;

LL ar[nmax];
LL tar[nmax];

vector<int>adj[nmax];

int st[nmax];
int en[nmax];
LL ara[nmax];
int d[nmax];

int clk = 0;

void dfs(int u,int p)
{
    st[u] = ++clk;

    ara[clk] = ar[u];

    for(int v:adj[u])
    {
        if(v==p)
            continue;

        d[v] = d[u]+1;

        dfs(v,u);

    }

    en[u] = clk;
}

/** Segment Tree **/
/*** 1 based indexing ***/

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

const int nmax2 = nmax<<2;
node Tree[3][nmax2];

void build(int num,int cur,int start,int end) /** build the segment tree **/
{
    if(start==end)
    {
        Tree[num][cur].create_leaf(ara[start]);
        return;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    build(num,lc,start,mid);
    build(num,rc,mid+1,end);

    Tree[num][cur].merge_nodes(Tree[num][lc],Tree[num][rc]);

}

void node_update(int num,int v,int st,int en,LL add)
{
    Tree[num][v].sum += (en-st+1)*add; /** Multiplying the size of the current node **/
    Tree[num][v].lazy += add;
}

void push(int num,int v,int st,int en)
{
    int mid = (st+en)>>1;
    int lc = v<<1, rc = lc|1;

    if(Tree[num][v].lazy)
    {
        node_update(num,lc,st,mid,Tree[num][v].lazy);   /** Multiplying the size of the left node with the parent's lazy value **/
        node_update(num,rc,mid+1,en,Tree[num][v].lazy); /** Multiplying the size of the right node with the parent's lazy value **/

        Tree[num][v].lazy = 0;
    }
}


void update(int num,int cur, int start, int end, int l,int r, LL add)
{
    if(l>r)
        return;

    if (l==start && r==end)
    {
        node_update(num,cur,start,end,add);
    }
    else
    {
        int mid = (start + end)>>1;
        int lc = cur<<1, rc = lc|1;

        push(num,cur,start,end); /** Pushdown to children node **/

        update(num,lc, start, mid,l,min(r,mid), add);
        update(num,rc, mid+1, end,max(l,mid+1),r, add);

        Tree[num][cur].merge_nodes(Tree[num][lc],Tree[num][rc]);
    }
}

LL query(int num,int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(l>r)
        return 0;

    if(start>=l && end<=r)
    {
        return Tree[num][cur].sum;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    push(num,cur,start,end); /** Pushdown to children node **/

    LL p1 = query(num,lc,start,mid,l,min(r,mid));
    LL p2 = query(num,rc,mid+1,end,max(l,mid+1),r);

    return p1+p2; /// sum

}

//void DEBUG(int n)
//{
//    cout<<"Current State : ";
//    for(int i=1;i<=n;i++)
//    {
//        LL t = query(1,1,n,i,i);
//
//        cout<<t<<" ";
//    }
//    cout<<endl;
//}

vector<int>lvl[nmax];

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
        cin>>ar[i];

    for(int i=1;i<=n;i++)
        cin>>tar[i];

    dfs(1,-1);

//    cout<<"Start : ";
//    for(int i=1;i<=n;i++)
//        cout<<st[i]<<" ";
//    cout<<endl;
//
//    cout<<"End : ";
//    for(int i=1;i<=n;i++)
//        cout<<en[i]<<" ";
//    cout<<endl;
//
//    cout<<"Depth : ";
//    for(int i=1;i<=n;i++)
//        cout<<d[i]<<" ";
//    cout<<endl;


    build(0,1,1,n);
    build(1,1,1,n);

    for(int i=1;i<=n;i++)
        lvl[d[i]].push_back(i);

    vector<int>res;

    for(int i=0;i<n;i++)
    {
        for(int now:lvl[i])
        {
            int x = now;

            LL ans = query(d[x]%2,1,1,n,st[x],st[x]);
            ans %= 2;

            if(tar[x]!=ans)
            {
                update(d[x]%2,1,1,n,st[x],en[x],1);
                res.push_back(x);
            }
        }
    }

    cout<<res.size()<<"\n";

    for(int x:res) cout<<x<<"\n";

    return 0;
}

/**
7 100
1 5
1 6
6 7
6 4
4 2
4 3
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
