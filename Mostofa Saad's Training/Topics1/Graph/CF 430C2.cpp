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

const int nmax = 2e5+7;

LL ar[nmax];
LL tar[nmax];

vector<int>adj[nmax];

int st[nmax];
int en[nmax];
LL ara[nmax];
int d[nmax];

int clk = 0;
vector<int>res;

void dfs(int u,int p,int od,int ev)
{
    int cur;

    if(d[u]%2==0)
    {
        cur = (ar[u]+ev)%2;

        if(tar[u]!=cur)
        {
            ev++;
            res.push_back(u);
        }
    }
    else
    {
        cur = (ar[u]+od)%2;

        if(tar[u]!=cur)
        {
            od++;
            res.push_back(u);
        }
    }

    for(int v:adj[u])
    {
        if(v==p)
            continue;

        d[v] = d[u]+1;

        dfs(v,u,od,ev);

    }
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
        cin>>ar[i];

    for(int i=1;i<=n;i++)
        cin>>tar[i];

    dfs(1,-1,0,0);

    cout<<res.size()<<"\n";

    for(int x:res) cout<<x<<"\n";

    return 0;
}

/**
7 100
1 5
1 6
6 7
6 4
4 2
4 3
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
