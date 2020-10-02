
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

struct Graph
{
    int n;
    bool dir;
    vector<vector<int>>adj;

    /// problem
    vector<int>col;

    /// small to large technique
    vector<int>sz;
    vector<bool>big;

    /// like mo
    vector<int>cnt;
    int distinct = 0;

    vector<LL>ans;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);

        /// problem
        col = vector<int>(len);

        /// small to large
        sz = vector<int>(len);
        big = vector<bool>(len);

        /// like mo
        cnt = vector<int>(len);

        ans = vector<LL>(len);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    void subtree_dfs(int u,int p)
    {
        sz[u] = 1;

        for(int v:adj[u])
        {
            if(v==p) continue;

            subtree_dfs(v,u);

            sz[u] += sz[v];
        }
    }

    void add(int u,int p)
    {
        int val = col[u];
        if(cnt[val]==0) distinct++;
        cnt[val]++;

        for(int v:adj[u])
        {
            if(v!=p && !big[v])
                add(v,u);
        }
    }

    void remov(int u,int p)
    {
        int val = col[u];
        cnt[val]--;

        if(cnt[val]==0) distinct--;

        for(int v:adj[u])
        {
            if(v!=p && !big[v])
                remov(v,u);
        }
    }

    void compute_answer(int u)
    {
        ans[u] = distinct;
    }

    void dfs(int u,int p,int keep)
    {
        int bigChildSize = -1 , bigChild = -1;

        /// finding the big child
        for(int v:adj[u])
        {
            if(v!=p && sz[v]>bigChildSize)
                bigChildSize = sz[v] , bigChild = v;
        }

        /// run dfs from small childs and delete their contribution
        for(int v:adj[u])
        {
            if(v!=p && v!=bigChild)
                dfs(v,u,0);
        }

        if(bigChild != -1)
        {
            dfs(bigChild,u,1); /// don't delete big child's contribution
            big[bigChild] = 1; /// marking bigchild
        }

        add(u,p);

        /// now we have the information of subtree rooted at u
        compute_answer(u);


        if(bigChild != -1) big[bigChild] = 0;
        if(keep == 0) remov(u,p); /// removing small child's contribution

    }

    vector<int> compress(vector<int> &v) /// compress v to [1,max distinct number range]
    {
        vector<int>c = v;
        map<int,int>m;

        for(int x:c) m[x] = 1;

        int val = 0;
        for(auto x:m) m[x.F] = ++val;

        for(int &x:c) x = m[x];

        return c;
    }

    void solve()
    {
        col = compress(col);

        subtree_dfs(1,-1);
        dfs(1,-1,0);

        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }

};

void solveTC()
{
    int n;
    cin>>n;

    Graph g(n,false);

    for(int i=1;i<=n;i++) cin>>g.col[i];

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        g.add_edge(a,b);
    }

    g.solve();

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

