
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second
#define endl "\n"

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

vector<vector<int>>dir;

vector<int>col;
vector<bool>vis;

stack<int>stk;

bool hasCycle(int u)
{
    col[u] = 1; /** grey **/

    for(int next:dir[u])
    {
        if(col[next]==0)
        {
            if(hasCycle(next))
                return true;
        }
        else if(col[next]==1)
            return true;
    }

    col[u] = 2; /** black **/

    return false;
}

void dfs(int u)
{
    vis[u] = true;

    for(int v:dir[u])
    {
        if(vis[v]) continue;

        dfs(v);
    }

    stk.push(u);
}

void RESIZE(int n)
{
    dir = vector<vector<int>>(n);
    col = vector<int>(n);
    vis = vector<bool>(n);
}


int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,mq;
        cin>>n>>mq;

        RESIZE(n+1);

        vector<PII>dir_ed;
        vector<PII>undir_ed;

        for(int i=1;i<=mq;i++)
        {
            int t,x,y;
            cin>>t>>x>>y;

            if(t==1)
            {
                dir[x].push_back(y);
                dir_ed.push_back({x,y});
            }
            else
            {
                undir_ed.push_back({x,y});
            }

        }

        bool cycle = false;

        for(int i=1; i<=n; i++)
        {
            if(col[i]==0)
            {
                if(hasCycle(i))
                {
                    cycle = true;
                    break;
                }
            }
        }

        if(cycle)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            for(int i=1; i<=n; i++)
                if(!vis[i])
                    dfs(i);

            vector<int>pos(n+1);
            int cnt = 0;

            while(!stk.empty())
            {
                int now = stk.top();
                stk.pop();
                pos[now] = ++cnt;
            }

            cout<<"YES"<<endl;

            for(auto p:dir_ed)
                cout<<p.F<<" "<<p.S<<endl;

            for(auto p:undir_ed)
            {
                int u = p.F , v = p.S;

                if(pos[u]>pos[v]) swap(u,v);

                cout<<u<<" "<<v<<endl;
            }
        }
    }

    return 0;
}

/**
YES
1 2
2 3
2 4
3 1
3 4
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


