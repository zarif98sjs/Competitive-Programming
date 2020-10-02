
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

const int nmax = 2e5+7;

struct Fenwick{

    vector<LL>BIT;
    int N;

    Fenwick(){}

    Fenwick (int n) : BIT(n+1,0) , N(n) {}

    inline int LSB(int x) {return x&(-x);} /// find the number with first bit set

    /// POINT update : adds val to index idx
    void add(int idx,LL val)
    {
        for(int i = idx ; i<=N ; i += LSB(i)) /// adding LSB , jumping to next segment covered by this index
            BIT[i] += val;
    }

    /// prefix sum upto index idx
    LL pref(int idx)
    {
        LL sum = 0;

        for(int i = idx ; i>0 ; i -= LSB(i)) /// removing LSB , jumping to next segment covering upto index
            sum += BIT[i];

        return sum;
    }

    /// RANGE Sum query [l,r]
    LL sum(int l,int r)
    {
        return pref(r) - pref(l-1);
    }

    void debug()
    {
        cout<<"Sum : ";
        for(int i=1;i<=N;i++)
            cout<<sum(i,i)<<" ";
        cout<<endl;
    }
};

struct Graph
{
    int n;
    bool dir;
    vector<vector<int>>adj;

    vector<int>val;

    /// euler
    vector<int>st,en;
    int timer = 0;

    Fenwick f;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);

        val = vector<int>(len);

        /// euler
        st = vector<int>(len);
        en = vector<int>(len);

        f = Fenwick(2*n);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    void euler(int u,int p)
    {
        st[u] = ++timer;

        for(int v:adj[u])
        {
            if(v==p) continue;

            euler(v,u);
        }

        en[u] = ++timer;
    }

    void init()
    {
        for(int i=1;i<=n;i++)
        {
            f.add(st[i],val[i]);
            f.add(en[i],-val[i]);
        }
    }

    void point_update(int node,int new_val)
    {
        int add = new_val - f.sum(st[node],st[node]);

        f.add(st[node],add);
        f.add(en[node],-add);
    }

    LL root_path_sum(int node)
    {
        return f.sum(1,st[node]);
    }
};

void solveTC()
{
    int n,q;
    cin>>n>>q;

    Graph g(n,false);

    for(int i=1;i<=n;i++) cin>>g.val[i];

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        g.add_edge(a,b);
    }

    g.euler(1,-1);
    g.init();

    while(q--)
    {
//        g.f.debug();

        int type;
        cin>>type;

        if(type == 1)
        {
            int node,new_val;
            cin>>node>>new_val;

            g.point_update(node,new_val);
        }
        else
        {
            int node;
            cin>>node;

            cout<<g.root_path_sum(node)<<endl;
        }
    }
}

int32_t main()
{
    optimizeIO();

    int tc = 1;
//    cin>>tc;

    while(tc--)
    {
        solveTC();
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

