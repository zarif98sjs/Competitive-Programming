
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

const int nmax = 3e5+7;

vector<vector<int>>adj;
vector<int>st,en,euler;
int timer = 0;

vector<int> parent;
vector<int> L;
vector<int> dist;
int sptable[nmax][17]; /** adjust 15 according to log of nmax **/

void dfs(int u,int par,int lvl)
{
    parent[u] = par;
    L[u] = lvl;

    if(par!=-1)
        dist[u] = dist[par] + 1;

    for(int v:adj[u])
    {
        if(v!=par)
            dfs(v,u,lvl+1);
    }
}

void lca_init(int n)
{
    memset(sptable,-1,sizeof sptable);

    for(int i=1; i<=n; i++)
        sptable[i][0] = parent[i];

    for(int j=1; (1<<j)<n; j++)
        for(int i=1; i<=n; i++)
            if(sptable[i][j-1]!=-1)
                sptable[i][j] = sptable[sptable[i][j-1]][j-1];
}

int lca_query(int u,int v)
{
    if(L[u]<L[v])
        swap(u,v);

    int dis = L[u] - L[v];

    int log;
    for(log = 1; (1<<log)<=L[u]; log++);
    log--;

    ///making the levels same
    for(int i=log; i>=0; i--)
        if(dis &(1<<i))
            u = sptable[u][i];

    if(u==v)
        return u;

    for(int i=log; i>=0; i--)
        if(sptable[u][i]!=-1 && sptable[v][i]!=-1 && sptable[u][i]!=sptable[v][i])
        {
            u = sptable[u][i];
            v = sptable[v][i];
        }

    return parent[u];
}

void dfs_flatten(int u,int p)
{
    st[u] = ++timer;

    for(int v:adj[u])
    {
        if(v!=p)
            dfs_flatten(v,u);
    }

    en[u] = ++timer;
}

void INIT(int len)
{
    timer = 0;
    adj = vector<vector<int>>(len);
    st = vector<int>(len);
    en = vector<int>(len);
    euler = vector<int>(len);
    parent = vector<int>(len);
    L = vector<int>(len,0);
    dist = vector<int>(len,0);
}

/** BIT / FENWICK TREE **/
/*** 1 based indexing ***/

struct Fenwick{

    vector<LL>BIT;
    int N;

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

    LL sum(int l,int r)
    {
        return pref(r) - pref(l-1);
    }

    void debug()
    {
        cout<<"Prefix Sum Array : ";
        for(int i=1;i<=N;i++)
            cout<<sum(i,i)<<" ";
        cout<<endl;
    }
};

int main()
{
    int tc;
    scanf("%d",&tc);

    int cs = 0;

    while(tc--)
    {
        printf("Case %d:\n", ++cs);

        int n;
        scanf("%d",&n);

        INIT(n+1);

        Fenwick f(2*n);

        vector<int>v(n+1);
        vector<int>cur(n+1);
        for(int i=1;i<=n;i++) scanf("%d",&v[i]);

        int edges = n-1;
        while(edges--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            a++,b++;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        /** PRE-WORK **/
        dfs(1,-1,0);
        lca_init(n);

        dfs_flatten(1,-1);

        DBG(st);
        DBG(en);

        for(int i=1;i<=n;i++)
        {
            f.add(st[i],v[i]);
            f.add(en[i],-v[i]);

            cur[i] = v[i];
        }

        int q;
        scanf("%d",&q);

        while(q--)
        {
            int type;
            scanf("%d",&type);

            if(type==0)
            {
                int node1,node2;
                scanf("%d %d",&node1,&node2);
                node1++,node2++;

                int lca = lca_query(node1,node2);

                LL path1 = f.sum(st[lca],st[node1]);
                LL path2 = f.sum(st[lca],st[node2]);
                LL minus = f.sum(st[lca],st[lca]);
                LL ans = path1+path2-minus;
                printf("%lld\n",ans);
            }
            else
            {
                int idx,new_val;
                scanf("%d %d",&idx,&new_val);
                idx++;

                int add = new_val - cur[idx];
                f.add(st[idx],add);
                f.add(en[idx],-add);
                cur[idx] = new_val;
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
