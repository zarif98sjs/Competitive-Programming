
/**

Check if a directed Graph is a Tree or not

Insights
========
1 . A tree has only 1 root

2 . A vertex can't be visited more than once
(If it is visited more than once , then there is 2 paths from the root .
But in a tree there is always only 1 path to a vertex)

One extra condition for Undirected Graph : only a parent can be visited twice .

3. After DFS from the root , all vertex will be explored .

Common Mistake
==============

1.

bool dfs(int u)
{
    vis[u] = true;

    for(int v:adj[u])
    {
        if(!vis[v]) return dfs(v);
        else return false;
    }

    return true;
}

In DFS , Don't write
return dfs(v)
Then it will explore only 1 child and return it's value .

One way to mitigate is return , only when false . This way we are sure .

bool dfs(int u)
{
    vis[u] = true;

    for(int v:adj[u])
    {
        if(!vis[v])
        {
            if(dfs(v)==false)
                return;
        }

        else return false;
    }

    return true;
}

Best is to explore all the vertexes

**/

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

const int nmax = 1e6+7;

vector<int>adj[nmax];
vector<int>in(nmax);
vector<bool>vis(nmax,0);

map<int,int>m;

bool dfs(int u) /// is Tree
{
    vis[u] = true;

    bool ok = true;

    for(int v:adj[u])
    {
        if(!vis[v])
            ok &= dfs(v);
        else
            ok = false;
    }

    return ok;
}

int main()
{
    optimizeIO();

    bool tree = true;

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
    }

    int rt_cnt = 0;
    int rt = 0;

    for(int i=1; i<=n; i++)
    {
        if(in[i]==0)
        {
            rt_cnt++;
            rt = i;
        }
    }

    if(rt_cnt!=1) tree = false;
    else
    {
        tree = dfs(rt);

        for(int i=1; i<=n; i++)
            if(!vis[i])
                tree = false;
    }

    if(tree) cout<<"Tree"<<endl;
    else cout<<"Not a tree"<<endl;

    return 0;
}

/**
6 8  5 3  5 2  6 4
5 6  0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0
-1 -1

53 says: u = 5
54 says: v = 1
53 says: u = 1
54 says: v = 2
53 says: u = 5
54 says: v = 3
53 says: u = 3
54 says: v = 2
53 says: u = 3
54 says: v = 4
53 says: u = 5
54 says: v = 6
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


