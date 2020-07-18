
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
const LL INF = 1e17;

LL ara[nmax];

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    LL mn;
    LL lazy;

    node()
    {
        mn = INF;
        lazy = 0;
    }

    void create_leaf(LL val)
    {
        mn = val;
        lazy = 0;
    }

    void merge_nodes(node &A,node &B)
    {
        mn = min(A.mn,B.mn);
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

void push(int v) {

    int lc = v<<1, rc = lc|1;

    Tree[lc].mn += Tree[v].lazy;
    Tree[lc].lazy += Tree[v].lazy;

    Tree[rc].mn += Tree[v].lazy;
    Tree[rc].lazy += Tree[v].lazy;

    Tree[v].lazy = 0;

}

void update(int cur, int start, int end, int l,int r, LL add)
{
    if(l>r)
        return;

    if(l==start && r==end)
    {
        Tree[cur].mn += add;
        Tree[cur].lazy += add;
    }
    else
    {
        int mid = (start + end)>>1;
        int lc = cur<<1, rc = lc|1;

        push(cur);

        update(lc, start, mid,l,min(r,mid), add);
        update(rc, mid+1, end,max(l,mid+1),r, add);

        Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
    }
}

LL query(int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(l>r)
        return INF;

    if(start>=l && end<=r)
    {
        DBG(Tree[cur].mn);
        return Tree[cur].mn;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    push(cur);

    LL p1 = query(lc,start,mid,l,min(r,mid));
    LL p2 = query(rc,mid+1,end,max(l,mid+1),r);

    return min(p1,p2); /// minimum

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
char s[1000010];
int main()
{
    //optimizeIO();

    int tc = 1;

    while(tc--)
    {
        CLEAR();

        int n;
        cin>>n;

        for(int i=1;i<=n;i++)
            cin>>ara[i];

        build(1,1,n);

        int q;
        cin>>q;

        gets(s);

        while(q--)
        {
            gets(s);

            stringstream in(s);

            int l,r,add;
            in>>l>>r;

            l++,r++;

            if(in>>add)
            {
                if(l<=r)
                {
                    update(1,1,n,l,r,add);
                }
                else
                {
                    update(1,1,n,1,r,add);
                    update(1,1,n,l,n,add);
                }
            }
            else
            {
                LL mn1 = LLONG_MAX;
                LL mn2 = LLONG_MAX;

                if(l<=r)
                {
                    mn1 = query(1,1,n,l,r);
                }
                else
                {
                    mn1 = query(1,1,n,1,r);
                    mn2 = query(1,1,n,l,n);
                }

                LL mn = min(mn1,mn2);
                cout<<mn<<endl;
//                cout<<endl;
            }
        }
    }

    return 0;
}

/**

5
1 2 3 4 5

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


