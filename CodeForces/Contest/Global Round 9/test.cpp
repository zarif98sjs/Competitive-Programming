
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

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

const int nmax = 3e5+7;

int ara[nmax];

/** Merge Sort Tree **/

struct node
{
    vector<int>v;

    void create_leaf(int val)
    {
        v.push_back(val);
    }

    void merge_nodes(node &A,node &B)
    {
        merge(ALL(A.v),ALL(B.v),back_inserter(v));
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

int query(int cur,int start,int end,int l,int r,int k) /** RANGE query **/
{
    if(end<l || start>r)
        return 0;

    if(start>=l && end<=r)
    {
        return lower_bound(ALL(Tree[cur].v),k) - Tree[cur].v.begin();
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    int p1 = query(lc,start,mid,l,r,k);
    int p2 = query(rc,mid+1,end,l,r,k);

    return p1 + p2;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        for(int i=1;i<=n;i++)
            cin>>ara[i];

        vector<int>left(n+1,0);
        vector<int>right(n+1,0);

        int mn = INT_MAX;
        int mx = 0;

        for(int i=1;i<=n;i++)
        {
            int l = -1;
            if(mn>ara[i]) l = 0;
            if(ara[i]-mn==1) l = 1;

            left[i] = l;
            mn = min(mn,ara[i]);
        }

        for(int i=n;i>=1;i--)
        {
            int r = -1;
            if(mx<ara[i]) r = 0;
            if(mx-ara[i]==1) r = 1;

            right[i] = r;
            mx = max(mx,ara[i]);
        }

//        build(1,1,n);

        PII a = {0,0};
        PII b = {0,1};
        PII c = {1,0};

        int cnt = 0;



        for(int i=1;i<=n;i++)
        {


//            int l = query(1,1,n,1,i-1,ara[i]);
//            int r_temp = query(1,1,n,i+1,n,ara[i]);
//            int r = n-(i+1) + 1 - r_temp;

            PII p = {left[i],right[i]};
//            DBG(p);

            if(p==a || p==b ||p==c)
                cnt++;
        }

//        DBG(cnt);

        if(cnt>1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
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


