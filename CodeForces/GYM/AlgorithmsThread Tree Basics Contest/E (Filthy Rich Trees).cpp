
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

/** BIT / FENWICK TREE **/
/*** 1 based indexing ***/

double BIT[nmax];
double ara[nmax];
void update(int index,double val,int len)
{
    while(index<=len)
    {
        BIT[index] = BIT[index]+val;
        index += index&(-index);
    }
}

double query(int index)
{
    double sum=0;
    while(index>0)
    {
        sum = sum+BIT[index];
        index -= index&(-index);
    }
    return sum;
}

double query(int L,int R)
{
    double r_val = query(R);
    double l_val = query(L-1);

    return r_val - l_val;
}

void INIT(int len)
{
    adj = vector<vector<int>>(len);
    st = vector<int>(len);
    en = vector<int>(len);
    euler = vector<int>(len);
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    INIT(n+1);

    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1);

    DBG(st);
    DBG(en);
    DBG(euler);

    double init = log2(1.0);

    for(int i=1;i<=n;i++)
        update(i,init,n) , ara[i] = init;

    int q;
    cin>>q;

    while(q--)
    {
        int type;
        cin>>type;

        if(type==1) /// point update
        {
            int idx;
            double val;
            cin>>idx>>val;

            int po = st[idx];
            double add = log2(val) - ara[po];

            update(po,add,n);
            ara[po] = log2(val);
        }
        else /// range query
        {
            int x ,y;
            cin>>x>>y;

            double val_x = query(st[x],en[x]);
            double val_y = query(st[y],en[y]);

            if(val_x-val_y>=log2(INF))
            {
                cout<<INF<<endl;
            }
            else
            {
                cout.precision(12);
                cout << fixed;
                cout<<pow(2.0,val_x-val_y)<<endl;
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


