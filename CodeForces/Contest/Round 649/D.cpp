
/**

Start with an empty graph and keep adding vertices from 1 to K in increasing order, using a DSU to keep track of connected components. If you ever add an edge that joins two vertices that were already joined, you have a cycle of length at most K.

Otherwise, you have a forest of size K, and can split it into vertices of even and odd depth. The larger one will be an independent set of size at least (K+1)/2.

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

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
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

vector<int>adj[nmax];
vector<int>adj2[nmax];

class DisjointSet
{
public:

    unordered_map<int, int> parent;

    void makeSet(int N)
    {
        for (int i = 1; i <= N; i++)
            parent[i] = i;
    }

    int Find(int k)
    {
        // if k is root
        if (parent[k] == k)
            return k;

        return parent[k] = Find(parent[k]);
    }

    void Union(int a, int b)
    {
        int x = Find(a);
        int y = Find(b);

        parent[y] = x;
    }

    void printParent(int N)
    {
        for (int i = 1; i <= N; i++)
            cout<<parent[i]<<" ";
        cout<<endl;

    }
};

bool vis[nmax];
vector<int>cycle;

void dfs(int u,int p)
{
    vis[u] = true;
    cycle.push_back(u);

    for(int v:adj[u])
    {
        if(v==p)
            continue;
        if(vis[v])
        {
            cout<<cycle.size()<<endl;

            for(int x:cycle)
                cout<<x<<" ";
            cout<<endl;
            exit(0);
        }
        dfs(v,u);
    }

    cycle.pop_back();
    vis[u] = false;
}

vector<int>odd,ev;

void bicolor(int u,int p,int h)
{
//    DBG(u);

    vis[u] = true;
    if(h&1)
        odd.push_back(u);
    else
        ev.push_back(u);

    for(int v:adj2[u])
    {
        if(v!=p && vis[v]==false)
            bicolor(v,u,h+1);
    }
}

int main()
{
    optimizeIO();

    int n,m,k;
    cin>>n>>m;

    k = ceil(sqrt(n));
//    DBG(k);

    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;

        if(a<=k && b<=k)
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        adj2[a].push_back(b);
        adj2[b].push_back(a);
    }

    DisjointSet ds;
    ds.makeSet(n);

    bool isCycle = false;
    int c = -1;

    for(int i=1; i<=n; i++)
    {
        for(int v:adj[i])
        {
            if(v<i)
            {
                if(ds.Find(i)!=ds.Find(v))
                    ds.Union(i,v);
                else
                {
                    isCycle = true, c = i;
                    cout<<2<<endl;
                    dfs(c,-1);
                    return 0;
                }

            }
        }
    }

//    memset(vis,0,sizeof vis);

    for(int i=1; i<=k; i++)
        if(vis[i]==false)
            bicolor(i,-1,1);

    vector<int>ans = odd;

    if(odd.size()<ev.size())
        ans = ev;

    cout<<1<<endl;
    for(int i=0; i<k; i++)
        cout<<ans[i]<<" ";
    cout<<endl;


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


