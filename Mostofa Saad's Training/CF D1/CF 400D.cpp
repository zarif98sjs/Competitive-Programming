

/**

Graph 1 :
Remove all weights > 0 .
DFS from every type and check if all other vertices of this type is reachable or not

Graph 2 :
Make a graph according to type .
Dijkstra from each type .

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
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

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
const int INF = 1e9+7;

vector<int>g[nmax];
vector<PII>tg[nmax];

int ans[505][505];

int type(int id,const vector<int>&v)
{
    int lo = lower_bound(ALL(v),id)-v.begin();

    return lo+1;
}

vector<bool>vis(nmax,false);

void dfs(int u)
{
    vis[u] = true;

    for(int v:g[u])
    {
        if(!vis[v])
            dfs(v);
    }
}

vector<int>dist(nmax,INF);

void dijkstra(int s)
{
    priority_queue< PII,vector<PII>,greater<PII> >PQ;

    fill(ALL(dist),INF);

    dist[s] = 0;
    PQ.push({0,s});

    while(!PQ.empty())
    {
        int now = PQ.top().S;
        PQ.pop();

        for(auto x:tg[now])
        {
            int next = x.F;
            int ed = x.S;

            if(dist[now] + ed < dist[next])
            {
                dist[next] = dist[now] + ed;
                PQ.push({dist[next],next});
            }
        }
    }
}

int main()
{
    optimizeIO();

    int n,m,k;
    cin>>n>>m>>k;

    vector<int>c(k);
    vector<int>c_sum(k);

    for(int i=0;i<k;i++)
        cin>>c[i];

    c_sum[0] = c[0];

    for(int i=1;i<k;i++)
        c_sum[i] = c_sum[i-1]+c[i];

    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;

        int ta = type(a,c_sum);
        int tb = type(b,c_sum);

        if(w==0)
        {
            g[a].push_back(b);
            g[b].push_back(a);
        }

        tg[ta].push_back({tb,w});
        tg[tb].push_back({ta,w});
    }

    bool ok = true;

    for(int i=0;i<k;i++)
    {
        int st = 1;
        if(i>0) st = c_sum[i-1] + 1;
        int en = c_sum[i];

        fill(ALL(vis),false);
        dfs(st);

        for(int j=st;j<=en;j++)
            if(vis[j]==false)
                ok = false;
    }

    if(!ok)
        cout<<"No"<<endl;
    else
    {

        cout<<"Yes"<<endl;

        for(int i=1;i<=k;i++)
        {
            dijkstra(i);

            for(int j=1;j<=k;j++)
            {
                if(dist[j]==INF) ans[i][j] = -1;
                else ans[i][j] = dist[j];
            }
        }


         for(int i=1;i<=k;i++)
         {
            for(int j=1;j<=k;j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
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


