
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

vector<int>adj[nmax];

map<PII,int>m;
vector<LL>d(nmax);

void dfs(int u,int p)
{
    if(p!=-1) d[u] = d[p] + m[{p,u}];

    for(int v:adj[u])
    {
        if(v!=p)
        {
            dfs(v,u);
        }
    }
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    LL s = 0;

    for(int i=1;i<n;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;

        adj[a].push_back(b);
        adj[b].push_back(a);

        m[{a,b}] = w;
        m[{b,a}] = w;

        s += 2*w;
    }

    dfs(1,-1);

    LL mx = 0;

    for(int i=1;i<=n;i++)
        mx = max(mx,d[i]);

    cout<<s-mx<<endl;

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


