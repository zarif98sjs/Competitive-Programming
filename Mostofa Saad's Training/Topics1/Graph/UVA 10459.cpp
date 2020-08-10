
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

const int nmax = 5e3+7;

vector<int>adj[nmax];
vector<int>d(nmax);

/**

As this is a tree , every node is visited once . So we don't need visited array

**/

void dfs(int u,int p)
{
    if(p!=-1)
        d[u] = d[p] + 1;

    for(int v:adj[u])
        if(v!=p)
            dfs(v,u);
}

void solve(int n)
{
    vector<int>d1,d2;

    d[1] = 0;
    dfs(1,-1);

    int farthest1 = -1;
    int mx = 0;

    for(int i=1; i<=n; i++)
    {
        if(d[i]>mx)
        {
            farthest1 = i;
            mx = d[i];
        }
    }

    d[farthest1] = 0;
    dfs(farthest1,-1);
    d1 = d;

    mx = 0;

    int farthest2 = -1;

    for(int i=1; i<=n; i++)
    {
        if(d[i]>mx)
        {
            farthest2 = i;
            mx = d[i];
        }
    }

    d[farthest2] = 0;
    dfs(farthest2,-1);
    d2 = d;

    int di = mx;

    vector<int>best;
    vector<int>worst;

//    DBG(di);
//    DBG(farthest1);
//    DBG(farthest2);

    if(di%2==0)
    {
        int need = di/2;

        for(int i=1; i<=n; i++)
        {
            if(d1[i]+d2[i]==di && d1[i]==need)
                best.push_back(i);
            else if(d1[i]==di || d2[i]==di)
                worst.push_back(i);
        }
    }
    else
    {
        int need = di/2;

        for(int i=1; i<=n; i++)
        {
            if(d1[i]+d2[i]==di && (d1[i]==need || d1[i]==need+1))
                best.push_back(i);
            else if(d1[i]==di || d2[i]==di)
                worst.push_back(i);
        }
    }

    cout<<"Best Roots  :";

    for(int x:best)
        cout<<" "<<x;
    cout<<endl;

    cout<<"Worst Roots :";
    for(int x:worst)
        cout<<" "<<x;
    cout<<endl;

}


int main()
{
    optimizeIO();

//    WRITE;

    int n;

    while(cin>>n)
    {
        for(int i=0;i<nmax;i++)
            adj[i].clear();

        for(int i=1; i<=n; i++)
        {
            int num;
            cin>>num;

            while(num--)
            {
                int x;
                cin>>x;

                adj[i].push_back(x);
            }
        }


        solve(n);
    }

    return 0;
}

/**
7
2 2 3
3 1 6 7
3 1 4 5
1 3
1 3
1 2
1 2
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


