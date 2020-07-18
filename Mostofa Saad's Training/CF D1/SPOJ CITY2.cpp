
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
    LL mn;

    void create_leaf(LL val)
    {
        mn=val;
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

void query(node &res,int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(l>r)
    {
        res.mn = LLONG_MAX;
        return;
    }

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

void CLEAR()
{
    for(int i=0;i<nmax2;i++)
        Tree[i].create_leaf(0);
}

int main()
{
    optimizeIO();

    int n;
    int cs = 0;

    while(cin>>n)
    {
        map<LL,int>prev;
        CLEAR();

        for(int i=1;i<=n;i++)
            cin>>ara[i] , prev[ara[i]] = -1;

        build(1,1,n);

        int ans = 0;

        for(int i=1;i<=n;i++)
        {
            if(ara[i]==0)
                continue;

            if(prev[ara[i]]==-1)
            {
                ans++;
                prev[ara[i]] = i;
            }
            else
            {
                node t;
                query(t,1,1,n,prev[ara[i]],i);

                if(t.mn<ara[i])
                    ans++;

                prev[ara[i]] = i;
            }
        }

        cout<<"Case "<<++cs<<": ";
        cout<<ans<<endl;

    }

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


