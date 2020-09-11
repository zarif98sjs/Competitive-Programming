
/**

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

const int nmax = 1e5+7;

vector<vector<int>>adj;

vector<int>parent;
vector<int>node_value;
vector<int>L;

int sptable[nmax][17]; /** adjust 2nd dimension according to log of nmax **/
int val_sptable[nmax][17];

void dfs(int u,int par,int lvl)
{
    parent[u] = par;
    L[u] = lvl;

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
        sptable[i][0] = parent[i]; /// 2^0 th parent

    for(int j=1; (1<<j)<n; j++)
        for(int i=1; i<=n; i++)
            if(sptable[i][j-1]!=-1)
                sptable[i][j] = sptable[sptable[i][j-1]][j-1];


    memset(val_sptable,-1,sizeof val_sptable);

    for(int i=1; i<=n; i++)
        val_sptable[i][0] = node_value[parent[i]];

    for(int j=1; (1<<j)<n; j++)
        for(int i=1; i<=n; i++)
            if(val_sptable[i][j-1]!=-1)
                val_sptable[i][j] = val_sptable[sptable[i][j-1]][j-1];

}

int Lift(int node,int key)
{
    int log;
    for(log = 1; (1<<log)<=L[node]; log++);
    log--;

    for(int i=log; i>=0; i--)
        if(sptable[node][i]!=-1 && val_sptable[node][i]>=key) /// lift as long as it satisfies the condition i.e the node value >= key
        {
            node = sptable[node][i];
        }

    return node;
}

void INIT(int len)
{
    adj = vector<vector<int>>(len);
    parent = vector<int>(len);
    L = vector<int>(len);
    node_value = vector<int>(len);
}

int main()
{
    optimizeIO();

    int tc;
    scanf("%d",&tc);

    int cs = 0;

    while(tc--)
    {
        printf("Case %d:\n",++cs);

        int n,q;
        scanf("%d %d",&n,&q);

        INIT(n+1);

        node_value[1] = 1;
        for(int i=2; i<=n; i++)
        {
            int p,val;
            scanf("%d %d",&p,&val);
            p++;

            adj[i].push_back(p);
            adj[p].push_back(i);

            node_value[i] = val;
        }

        /** PRE-WORK **/
        dfs(1,-1,0);
        lca_init(n);

        while(q--)
        {
            int node, key;
            scanf("%d %d",&node,&key);
            node++;

            int ans = Lift(node,key);
            ans--;
            DBG(ans);
            printf("%d\n",ans);
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
