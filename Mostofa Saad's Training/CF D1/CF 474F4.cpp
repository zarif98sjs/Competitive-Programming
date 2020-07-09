
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

const int nmax = 1e5+7;

LL ara[nmax];

struct node
{
    LL g;

    node(): g(0){}
    node(LL g) : g(g) {}

    void create_leaf(LL val)
    {
        g=val;
    }
};

node combine(node A,node B)
{
    node ret;
    ret.g = __gcd(A.g,B.g);
    return ret;
}

int n;  // array size
node t[2 * nmax];

void build()    // build the tree
{
    for (int i = 0; i < n; ++i)
        t[n+i].create_leaf(ara[i]);

    for (int i = n - 1; i > 0; --i)
        t[i] = combine(t[i<<1],t[i<<1|1]);
}

void modify(int p, int value)    // set value at position p
{
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p>>1] = combine(t[p],t[p^1]);
}

node query(int l, int r)    // sum on interval [l, r)
{
    node resl,resr;

    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) resl = combine(resl,t[l++]);
        if (r&1) resr = combine(t[--r],resr);
    }
    return combine(resl,resr);
}

void DEBUG()
{
    cout<<"Current state : ";
    for(int i=0;i<n;i++)
    {
        node res = query(i,i+1);
        cout<<res.g<<" ";
    }
    cout<<endl;
}

map<int,vector<int>>M;

int main()
{
    optimizeIO();

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>ara[i] , M[ara[i]].push_back(i);

    build();

    int q;
    cin>>q;

    while(q--)
    {
        int l ,r;
        cin>>l>>r;

        l-- , r--; /// 0 based indexing

        node res = query(l,r); /// query is [l, r]

        int gcd = res.g;

        int live = upper_bound(ALL(M[gcd]),r) - lower_bound(ALL(M[gcd]),l);
        int die = (r-l+1) - live;

        cout<<die<<endl;
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


