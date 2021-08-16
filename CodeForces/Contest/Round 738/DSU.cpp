
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct DisjointSet
{
    unordered_map<int, int> parent;
    vector<int>sz;
    int comp;

    vector<vector<int>>g; /// extra part

    void makeSet(int N)
    {
        sz = vector<int>(N+1,1);
        g = vector<vector<int>>(N+1); /// extra part

        for (int i = 1; i <= N; i++)
            parent[i] = i, g[i].push_back(i);

        comp = N;
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

        if(x==y) return;

        /**
            merge is done according to size
            if we do that, when we maintain adjacency list, we can merge small to large component
            this optimizes the union process
        **/

        if(sz[x] < sz[y]) swap(x,y);

        sz[x] += sz[y];
        parent[y] = x;

        g[x].insert(g[x].end(), ALL(g[y]));
        g[y].clear();

        comp--;
    }

    void printParent(int N)
    {
        for (int i = 1; i <= N; i++)
            cout<<parent[i]<<" ";
        cout<<endl;
    }
};

void solveTC()
{
    int n , m1 , m2;
    cin>>n >> m1 >> m2;

    DisjointSet d1, d2;

    d1.makeSet(n);
    d2.makeSet(n);

    vector<PII> e;

    for(int i=1;i<=m1;i++)
    {
        int a,b;
        cin>>a>>b;
        d1.Union(a,b);
    }

    for(int i=1;i<=m2;i++)
    {
        int a,b;
        cin>>a>>b;
        d2.Union(a,b);
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


