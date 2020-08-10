
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

const int nmax = 1e3+7;

vector<int>adj[nmax];

int ask(int u,int v)
{
    cout<<"? "<<u<<" "<<v<<"\n";
    cout << flush;

    int lca;
    cin>>lca;

    assert(lca != -1);

    return lca;
}

void reply(int root)
{
    cout<<"! "<<root<<"\n";
    cout << flush;
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int>in(n+1,0);
    vector<bool>doom(n+1,false);
    vector<bool>vis(n+1,false);

    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);

        in[a]++;
        in[b]++;
    }

    queue<int>q;

    for(int i=1;i<=n;i++)
        if(in[i]==1) q.push(i) , vis[i] = true;

    while(1)
    {
        if(q.size()<2)
            break;

        int u = q.front();
        q.pop();
        int v = q.front();
        q.pop();

        int lca = ask(u,v);

        if(lca==u || lca==v)
        {
            reply(lca);
            return 0;
        }

        in[u] = 0;
        in[v] = 0;

        doom[u] = true;
        doom[v] = true;

        for(int au:adj[u])
            in[au]--;

        for(int av:adj[v])
            in[av]--;

        for(int i=1;i<=n;i++)
            if(in[i]==1 && !vis[i])
                q.push(i) , vis[i] = true;
    }

    for(int i=1;i<=n;i++)
    {
        if(!doom[i])
        {
            reply(i);
            return 0;
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


