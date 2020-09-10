
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

const int nmax = 3e5+7;
const double INF = 1e9;

vector<vector<int>>adj;
vector<int>st;
vector<int>en;
vector<int>euler;

int clk = 0;

void dfs(int u,int p)
{
    st[u] = ++clk;
    euler[clk] = u;

    for(int v:adj[u])
    {
        if(v != p)
            dfs(v,u);
    }

    en[u] = clk;
}

void INIT(int len)
{
    adj = vector<vector<int>>(len);
    st = vector<int>(len);
    en = vector<int>(len);
    euler = vector<int>(len);
}

int solve(int node,int k,int n)
{
    int desired_pos = st[node] + k -1;

    if(desired_pos > en[node]) return -1;

    return euler[desired_pos];
}

int main()
{
    optimizeIO();

    int n,q;
    cin>>n>>q;

    INIT(n+1);

    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;

        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    dfs(1,-1);

    while(q--)
    {
        int node,k;
        cin>>node>>k;

        int ans = solve(node,k,n);
        cout<<ans<<endl;
        DBG(ans);
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


