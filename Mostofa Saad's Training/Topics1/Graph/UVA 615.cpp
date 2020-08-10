
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

const int nmax = 1e6+7;

vector<int>adj[nmax];
vector<int>in(nmax);
vector<int>out(nmax);
vector<bool>vis(nmax,0);

map<int,int>m;

bool dfs(int u) /// is Tree
{
    vis[u] = true;

    for(int v:adj[u])
    {
        DBG(u);
        DBG(v);

        if(!vis[v])
        {
            if(dfs(v)==false)
                return false;
        }
        else
            return false;
    }

    return true;
}

int main()
{
    optimizeIO();

    int cs = 0;

    while(1)
    {
        bool en = false;
        bool tree = true;

        fill(ALL(in),0);
        fill(ALL(out),0);

        for(int i=1;i<nmax;i++)
            adj[i].clear();
        m.clear();

        int mx = 0;
        int cnt = 0;

        while(1)
        {
            int a,b;
            cin>>a>>b;

            if(a==-1 && b==-1)
            {
                en = true;
                break;
            }

            if(a==0 && b==0)
            {
                break;
            }

            if(m.find(a)==m.end()) m[a] = ++cnt;
            if(m.find(b)==m.end()) m[b] = ++cnt;

            a = m[a];
            b = m[b];

            adj[a].push_back(b);

            mx = max(mx,a);
            mx = max(mx,b);

            in[b]++;
            out[a]++;
        }

        if(en)
            break;

        int n = mx;
        int rt_cnt = 0;
        int rt = 0;

        for(int i=1;i<=n;i++)
        {
            if(in[i]==0 && out[i]!=0)
            {
                rt_cnt++;
                rt = i;
            }
        }

        fill(ALL(vis),0);

        if(rt_cnt!=1)
            tree = false;
        else
            tree = dfs(rt);

        for(int i=1;i<=n;i++)
            if(!vis[i])
                tree = false;

        if(tree) cout<<"Case "<<++cs<<" is a tree."<<endl;
        else cout<<"Case "<<++cs<<" is not a tree."<<endl;


    }

    return 0;
}

/**
6 8  5 3  5 2  6 4
5 6  0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0
-1 -1
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


