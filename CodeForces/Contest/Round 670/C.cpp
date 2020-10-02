
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

const int nmax = 2e5+7;

vector<vector<int>>adj;


vector<int> Centroid(int n)
{
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev)
    {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto v : adj[u])
            if (v != prev)
            {
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > n / 2)
                    is_centroid = false;
            }
        if (n - sz[u] > n / 2)
            is_centroid = false;
        if (is_centroid)
            centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}


void INIT(int len)
{
    adj = vector<vector<int>>(len);
}

void solve()
{
    int n;
    cin>>n;

    INIT(n+1);

    int ed = n-1;

    while(ed--)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto centroids = Centroid(n);
    DBG(centroids);
    if (centroids.size() == 1)
    {
        int c = centroids[0];

        cout<<c+1<<" "<<adj[c][0]+1<<endl;
        cout<<c+1<<" "<<adj[c][0]+1<<endl;

    }
    else if (centroids.size() == 2)
    {
        int c1 = centroids[0];
        int c2 = centroids[1];

        int paisi = 0;

        for(int x:adj[c1])
        {
            if(x!=c2)
            {
                paisi = x;
                break;
            }
        }

        cout<<c1+1<<" "<<paisi+1<<endl;
        cout<<c2+1<<" "<<paisi+1<<endl;
    }
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        solve();
    }

    return 0;
}

/**
8
1 4
2 4
3 4
4 5
5 6
5 7
5 8
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
