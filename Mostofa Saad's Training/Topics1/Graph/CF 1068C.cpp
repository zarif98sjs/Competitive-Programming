
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

const int nmax = 100+7;

vector<int>adj[nmax];

vector<PII>p[nmax];
map<int,int>prv;

void solve(int n)
{
    int r = 1;
    int c = 1;

    for(int i=1;i<=n;i++)
    {
        for(int v:adj[i])
        {
            p[i].push_back({r,c});
            p[v].push_back({r+1,c});

            if(prv.find(i)!=prv.end())
            {
                p[i].push_back({prv[i],c});
            }
            if(prv.find(v)!=prv.end())
            {
                p[v].push_back({prv[v],c});
            }

            prv[i] = r;
            prv[v] = r+1;

            r+=2;
            c+=1;
        }

        int sz = adj[i].size();

        if(sz==0)
        {
            p[i].push_back({r,c});

            if(prv.find(i)!=prv.end())
            {
                p[i].push_back({prv[i],c});
            }
            prv[i] = r;

            r+=1;
            c+=1;
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<p[i].size()<<"\n";

        for(PII pos:p[i])
            cout<<pos.S<<" "<<pos.F<<"\n";
    }

}

int main()
{
    optimizeIO();

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        if(a>b)
            swap(a,b);

        adj[a].push_back(b);
    }

    solve(n);



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


