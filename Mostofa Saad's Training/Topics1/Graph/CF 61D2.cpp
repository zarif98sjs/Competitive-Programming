
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

/**

DP 1st parameter : Weight if all the edges are traversed twice
DP 2nd parameter : Maximum weighted path leading up to this vertex

**/

PLL dfs(int u,int p)
{
    PLL now = {0,0};

    for(auto next:adj[u])
    {
        int v = next.F;
        LL w = next.S;

        if(v==p)
            continue;

        PLL ch = dfs(v,u);

        now.F += 2*w; /// traverse current edge twice
        now.F += ch.F; /// add current child value

        now.S = max(now.S,ch.S+w); /// finding the maximum path value upto 'u'
    }

    return now;
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;

        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    PLL ans = dfs(1,-1);

    cout<<ans.F-ans.S<<endl;

    return 0;
}

/**

5

5 3 60

4 3 63

2 1 17

3 1 14


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
