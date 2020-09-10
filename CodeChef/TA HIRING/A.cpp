
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

int nodes,edges;
vector<int>adj[nmax];
bool visited[nmax];
vector<int>stk;
vector<PII>VE;

vector<int>comp(nmax);
int COMP = 0;

void dfs(int node)
{
    comp[node] = COMP;
    visited[node]=true;

    for(int next:adj[node])
    {
        if(!visited[next])
            dfs(next);
    }

    stk.push_back(node);
}

void init()
{
    for(int i=0; i<nmax; i++)
        adj[i].clear();

    fill(visited,visited+nmax,false);

    stk.clear();

}

int solve()
{
    int ok = 0;

    for(int j=1; j<=nodes; j++)
    {
        if(!visited[j])
        {
            ++COMP;
            stk.clear();

            dfs(j);

            DBG(stk);
            ok += (int)stk.size();
            ok -= 1;
        }
    }


    for(auto e:VE)
    {
       int u = e.F;
       int v = e.S;

       if(comp[u] != comp[v]) ok++;
    }

    int cut = edges - ok;

    return cut;
}


int main()
{
    optimizeIO();

    //init();

    scanf("%d %d",&nodes,&edges);

    for(int j=1; j<=edges; j++)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        adj[a].push_back(b);
        adj[b].push_back(a);

        VE.push_back({a,b});
    }

    int ans = solve();
    cout<<ans<<endl;

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
