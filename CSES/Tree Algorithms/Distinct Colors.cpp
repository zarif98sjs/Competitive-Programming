

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

int block_size;

struct Query
{
    int l, r, idx;
};

bool cmp(const Query &a,const Query &b)
{
    return make_pair(a.l / block_size, a.r) <
           make_pair(b.l / block_size, b.r);
}

struct MoAlgo{

    vector<int>ara;

    vector<int>cnt;

    int distinct = 0; /// set size

    MoAlgo(int n,vector<int> &og)
    {
        block_size = sqrt(n);
        ara = og;

        cnt = vector<int>(n+10);
    }

    void add(int idx)
    {
        int val = ara[idx];

        if(cnt[val]==0) distinct++;

        cnt[val]++;
    }

    void remov(int idx)
    {
        int val = ara[idx];
        cnt[val]--;

        if(cnt[val]==0)
            distinct--;
    }

    int get_answer()
    {
        return distinct;
    }

    vector<int> mo_s_algorithm(vector<Query> queries)
    {
        vector<int> answers(queries.size()+1);
        sort(queries.begin(), queries.end(),cmp);

        // TODO: initialize data structure

        int cur_l = 1;
        int cur_r = 0;
        // invariant: data structure will always reflect the range [cur_l, cur_r]
        for (Query q : queries)
        {
            while (cur_l > q.l)
            {
                cur_l--;
                add(cur_l);
            }
            while (cur_r < q.r)
            {
                cur_r++;
                add(cur_r);
            }
            while (cur_l < q.l)
            {
                remov(cur_l);
                cur_l++;
            }
            while (cur_r > q.r)
            {
                remov(cur_r);
                cur_r--;
            }
            answers[q.idx] = get_answer();
        }
        return answers;
    }
};

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

struct Graph
{
    int n;
    bool dir;
    vector<vector<int>>adj;

    /// problem
    vector<int>col;

    /// tree flatten
    vector<int>st,en;
    int timer = 0;
    vector<int>new_tree;

    Graph(int n,bool dir)
    {
        this->n = n;
        this->dir = dir;
        int len = n+1;

        adj = vector<vector<int>>(len);

        /// problem
        col = vector<int>(len);

        /// tree flatten
        st = vector<int>(len);
        en = vector<int>(len);
        new_tree = vector<int>(len);
    }

    void add_edge(int u,int v)
    {
        adj[u].push_back(v);
        if(!dir) adj[v].push_back(u);
    }

    void tree_flatten(int u,int p)
    {
        st[u] = ++timer;
        new_tree[timer] = col[u];

        for(int v:adj[u])
        {
            if(v==p) continue;

            tree_flatten(v,u);
        }

        en[u] = timer;
    }

    vector<Query> gather_queries()
    {
        vector<Query>q;

        for(int i=1;i<=n;i++)
            q.push_back({st[i],en[i],i});

        return q;
    }

    void solve()
    {
        col = compress(col);
        tree_flatten(1,-1);

        MoAlgo m(n,new_tree);

        vector<Query> q = gather_queries();

        vector<int> ans = m.mo_s_algorithm(q);

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
