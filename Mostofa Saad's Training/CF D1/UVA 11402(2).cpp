
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

const int nmax = 1024010;

LL ara[nmax];

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    LL sum ;

    bool lazy;
    int lazy_type;

    node()
    {
        sum = 0;

        lazy = false;
        lazy_type = -1;
    }

    void create_leaf(LL val)
    {
        sum = val;

        lazy = false;
        lazy_type = -1;
    }

    void merge_nodes(node &A,node &B)
    {
        sum = A.sum + B.sum;
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

void node_update(int cur,int st,int en,int type)
{
    if(type == 0) Tree[cur].sum = 0; /// assign 0
    if(type == 1) Tree[cur].sum = (en-st+1); /// assign 1
    if(type == 2) Tree[cur].sum = (en-st+1) - Tree[cur].sum; /// flip

    if(type == 0 || type == 1)
        Tree[cur].lazy_type = type;
    if(type == 2)
    {
        if(Tree[cur].lazy_type == 0) Tree[cur].lazy_type = 1;
        else if(Tree[cur].lazy_type == 1) Tree[cur].lazy_type = 0;
        else if(Tree[cur].lazy_type == 2) Tree[cur].lazy_type = -1;
        else Tree[cur].lazy_type = 2;
    }

    Tree[cur].lazy = true;
}

void push(int cur,int st,int en)
{
    int mid = (st + en)>>1;
    int lc = cur<<1, rc = lc|1;

    node_update(lc,st,mid,Tree[cur].lazy_type);
    node_update(rc,mid+1,en,Tree[cur].lazy_type);

    Tree[cur].lazy = false;
    Tree[cur].lazy_type = -1;
}

void update(int cur, int start, int end, int l,int r, int type)
{
    if(start>r || end<l)
        return;

    if (l<=start && r>=end)
    {
        node_update(cur,start,end,type);
        return;
    }
//    else
//    {
        int mid = (start + end)>>1;
        int lc = cur<<1, rc = lc|1;

        if(Tree[cur].lazy) push(cur,start,end);

        update(lc, start, mid,l,r, type);
        update(rc, mid+1, end,l,r, type);

        Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
//    }
}


LL query(int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(start>r || end<l)
        return 0;

    if(start>=l && end<=r)
    {
        return Tree[cur].sum;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    if(Tree[cur].lazy) push(cur,start,end);

    LL p1 = query(lc,start,mid,l,r);
    LL p2 = query(rc,mid+1,end,l,r);

    return p1+p2; /// sum

}

void CLEAR()
{
    for(int i=0;i<nmax2;i++)
        Tree[i].create_leaf(0);
}

void DEBUG(int n)
{
    cout<<"Current State : ";
    for(int i=1;i<=n;i++)
    {
        LL t = query(1,1,n,i,i);

        cout<<t<<" ";
    }
    cout<<endl;
}

void DEBUG2(int n)
{
    for(int i=1;i<=n;i++)
    {
        query(1,1,n,i,i);
    }
}

int main()
{
    optimizeIO();

//    WRITE;

    int tc;
    cin>>tc;

    int cs = 0;

    while(tc--)
    {
        CLEAR();

        int num;
        cin>>num;

        string f = "";

        for(int i=1;i<=num;i++)
        {
            int c;
            string s;
            cin>>c>>s;

            for(int j=1;j<=c;j++)
                f += s;

        }

        int n = f.size();
//        DBG(f);

        for(int i=1;i<=n;i++)
            ara[i] = f[i-1]-'0';

        build(1,1,n);

        cout<<"Case "<<++cs<<":\n";

        int q;
        cin>>q;

        int ql = 0;

        while(q--)
        {
//            DEBUG(n);

            string type;
            cin>>type;

            int l,r;
            cin>>l>>r;

            l++,r++;

            if(type=="F")
            {
                update(1,1,n,l,r,1);
            }
            else if(type=="E")
            {
                update(1,1,n,l,r,0);
            }
            else if(type=="I")
            {
                update(1,1,n,l,r,2);
            }
            else
            {
                LL v = query(1,1,n,l,r);
                cout<<"Q"<<++ql<<": "<<v<<"\n";
            }
        }

    }

    return 0;
}

/**

2
2
5
10
2
1000
5
F 0 17
I 0 5
S 1 10
E 4 9
S 2 10
3
3
1
4
0
2
0
2
I 0 2
S 0 8
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


