
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

const int nmax = 2e3+7;

vector<int>adj[nmax];

int dfs(int u,int p)
{
    int depth = 1;

    for(int v:adj[u])
    {
        if(v==p) continue;

        depth = max(depth,dfs(v,u)+1);
    }

    return depth;
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int>root;

    for(int i=1;i<=n;i++)
    {
        int v;
        cin>>v;

        if(v!=-1)
        {
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
        else
            root.push_back(i);
    }

    int mx = 0;

    for(int x:root)
    {
        int depth = dfs(x,-1);
        mx = max(mx,depth);
    }

    cout<<mx<<endl;

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


