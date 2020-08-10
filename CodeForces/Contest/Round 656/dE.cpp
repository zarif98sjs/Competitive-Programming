
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

vector<int>adj[nmax];
vector<int>dir[nmax];
map<PII,int>m;

vector<int>col(nmax,0);

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
    col[u] = 1; /** grey **/

    for(int next:adj[u])
    {
        if(col[next]==0)
        {
            dfs(next);
        }
        else if(col[next]==1 && m[{u,next}]!=1)
        {

            m[ {next,u} ] = 2;

            PII p = {next,u};
            DBG(p);
        }
    }

    col[u] = 2; /** black **/
}

void CLEAR()
{
    for(int i=0;i<nmax;i++)
    {
        adj[i].clear();
        dir[i].clear();
    }

    m.clear();
    fill(ALL(col),0);
}


int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {

        CLEAR();

        int n,mq;
        cin>>n>>mq;

        for(int i=1;i<=mq;i++)
        {
            int t,x,y;
            cin>>t>>x>>y;

            if(t==1)
            {
                dir[x].push_back(y);

                adj[x].push_back(y);
                m[{x,y}] = 1;
            }
            else
            {
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }

        for(auto p:m)
        {
            cout<<p.F.F<<" "<<p.F.S<<"\n";
        }

        bool ok = false;

        for(int i=1; i<=n; i++)
        {
            if(col[i]==0)
            {
                if(hasCycle(i))
                {
                    ok = true;
                    break;
                }
            }
        }


        if(ok)
        {
            cout<<"NO\n";
        }
        else
        {
            fill(ALL(col),0);

            for(int i=1; i<=n; i++)
            {
                if(col[i]==0)
                {
                    dfs(i);
                }
            }

            cout<<"YES\n";

            for(auto p:m)
            {
                if(p.S ==1 || p.S==2)cout<<p.F.F<<" "<<p.F.S<<"\n";
            }
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


