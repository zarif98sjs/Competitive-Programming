
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

const int nmax = 1e5+7;

LL ara[nmax];
LL cnt[nmax];

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    LL mx , mx_id;

    void create_leaf(LL val , LL id)
    {
        mx = val , mx_id = id;
    }

    void merge_nodes(node &A,node &B)
    {
        if(A.mx >= B.mx) mx_id = A.mx_id;
        else mx_id = B.mx_id;

        mx = max(A.mx,B.mx);
    }
};

const int nmax2 = nmax<<2;
node Tree[nmax2];

void build(int cur,int start,int end) /** build the segment tree **/
{
    if(start==end)
    {
        Tree[cur].create_leaf(ara[start],start);
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

void INIT(int n)
{
    int go = n<<2;
    for(int i=0;i<go;i++)
        Tree[i].create_leaf(0,0);
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,q;
        cin>>n>>q;

        INIT(n);

        for(int i=1; i<=n; i++) cin>>ara[i];
        for(int i=1; i<=n; i++) cin>>cnt[i];

        build(1,1,n);

        while(q--)
        {
            int type;
            cin>>type;

            if(type==1) /** POINT update **/
            {
                int l,r,add;
                cin>>l>>r>>add;

                node t;
                query(t,1,1,n,l,r);

                int id = t.mx_id;

                cnt[id] += add;

            }
            else /** RANGE query **/
            {
                int vis,pos,buy,thr;
                cin>>vis>>pos>>buy>>thr;

                int l = max(1,pos-vis);
                int r = min(n,pos+vis);

                node t;
                query(t,1,1,n,l,r);

                int id = t.mx_id;
                int mx = t.mx;

                if(mx<thr) cout<<"No purchase"<<endl;
                else
                {
                    if(cnt[id]-buy<0) cout<<"No purchase"<<endl;
                    else{
                        cnt[id] -= buy;
                        cout<<id<<endl;
                        DBG(id);
                    }
                }

            }
        }


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
