
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

LL ara[nmax];

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    LL sign;

    void create_leaf(LL val)
    {
        if(val==0) sign = 0;
        else if (val>0) sign = +1;
        else if (val<0) sign = -1;
    }

    void merge_nodes(node &A,node &B)
    {
        sign = A.sign * B.sign;
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

    while(cin>>n>>q)
    {
        for(int i=1;i<=n;i++)
            cin>>ara[i];

        build(1,1,n);

        while(q--)
        {
            char ch;
            cin>>ch;

            if(ch=='C')
            {
                LL pos,val;
                cin>>pos>>val;
                update(1,1,n,pos,val);
            }
            else
            {
                LL l,r;
                cin>>l>>r;

                node t;
                query(t,1,1,n,l,r);

                if(t.sign==0) printf("0");
                else if(t.sign==1) printf("+");
                else if(t.sign==-1) printf("-");
            }
        }

        printf("\n");
    }


    return 0;
}

/**
4 6
-2 6 0 -1
C 1 10
P 1 4
C 3 7
P 2 2
C 4 -5
P 1 4
5 9
1 5 -2 4 3
P 1 2
P 1 5
C 4 -5
P 1 5
P 4 5
C 3 0
P 1 5
C 4 -5
C 4 -5
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


