
/**

down[node] = number of ways to paint the subtree of node when node is black
up[node] = number of ways to paint vertices NOT in the subtree of node when node is black

Final ans = down[node] * up[node]

Calculating down[node]
======================
way = Multiplication (Answer for all child)
    = Multiplication ( The child is white OR The child is black)
    = Multiplication ( 1  + down[child])

so , down[node] = Multiplication ( 1  + down[child])

Calculating up[node]
======================
2 ways :
    way1 =  The parent is white = 1
    way2 =  The parent is black = up[parent] * Multiplication ( Answer for all child of parents except node aka brothers)
                                = up[parent] * Multiplication ( The brother is white OR The brother is black)
                                = up[parent] * Multiplication ( 1  + down[brother]) // use a prefix and suffix multiplication array to calculate this to avoid division

so , up[node] = 1 + up[parent] * Multiplication ( 1  + down[brother])

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>

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
int mod;

VVI adj;
VI down;
VI up;

VVI pref , suf;

int mul(int a ,int b)
{
    return (1LL * a * b)%mod;
}

void dfs_down(int u,int p=-1)
{
    down[u] = 1; /// color this node black

    for(int v:adj[u])
    {
        if(v!=p)
        {
            dfs_down(v,u);

            down[u] = mul(down[u],1+down[v]);
        }
    }

    int sz = adj[u].size();

    pref[u].resize(sz);
    suf[u].resize(sz);

    for(int i=0;i<sz;i++)
    {
        int prv = 1 , cur = 1;
        int v = adj[u][i];

        if(i != 0) prv = pref[u][i-1];
        if(v != p) cur = 1 + down[v];

        cur %= mod;

        pref[u][i] = mul(prv,cur);
    }

    for(int i=sz-1;i>=0;i--)
    {
        int prv = 1 , cur = 1;
        int v = adj[u][i];

        if(i != sz-1) prv = suf[u][i+1];
        if(v != p) cur = 1 + down[v];

        cur %= mod;

        suf[u][i] = mul(prv,cur);
    }
}

void dfs_up(int u,int p=-1)
{
    if(p == -1) up[u] = 1; /// as he has no brothers , initializing his answer

    int sz = (int)adj[u].size();
    for(int i=0;i<sz;i++)
    {
        int v = adj[u][i];

        if(v!=p)
        {
            int way1 = 1 ; /// parent is white
            int way21 = 1 , way22 = 1;

            if(i != 0)    way21 = pref[u][i-1];
            if(i != sz-1) way22 = suf[u][i+1];

            up[v] = way1 + mul(up[u],mul(way21,way22));
            up[v] %= mod;

            dfs_up(v,u);
        }
    }
}

void INIT(int len)
{
    adj = VVI(len);
    pref = VVI(len);
    suf = VVI(len);
    down = VI(len);
    up = VI(len);
}

int main()
{
    optimizeIO();

    int n;
    cin>>n>>mod;

    INIT(n+1);

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_down(1);
    dfs_up(1);

    for(int i=1;i<=n;i++)
    {
        int ans = mul(down[i],up[i]);
        cout<<ans<<endl;
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


