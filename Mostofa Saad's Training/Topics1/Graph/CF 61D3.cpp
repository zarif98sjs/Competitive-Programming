
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

const int nmax = 1e5+7;

vector<PII>adj[nmax];
vector<LL>cost(nmax);

void dfs(int u,int p)
{
    DBG(u);
    cost[u] = 0;
    LL mx = 0;

    for(PII next:adj[u])
    {
        int v = next.F;
        int w = next.S;

        if(v!=p)
        {
            dfs(v,u);

            cost[u] += 2*w;
            cost[u] += cost[v];

            mx = max(mx,cost[v]+w);
        }

    }

    cost[u] -= mx;

    DBG(u);
    DBG(cost[u]);
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1; i<n; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;

        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    dfs(1,-1);

    DBG(cost[1]);

    cout<<cost[1]<<endl;

    return 0;
}

/**

3
1 2 2
1 3 3

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

