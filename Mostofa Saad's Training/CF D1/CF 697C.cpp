
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

const int nmax = 2e5+7;

map<PLL,LL>m;

LL lca_eff(LL u,LL v)
{
    while(u!=v)
    {
        if(v<u) /// v is the big one
            swap(u,v);

        v = v>>1LL;
    }

    return v;
}

void update(LL u,LL v,LL w)
{
    LL l = lca_eff(u,v);
    LL pu = u>>1LL;

    while(pu>=l)
    {
        m[{u,pu}] += w;

        u = pu;
        pu = u>>1LL;
    }

    LL pv = v>>1LL;

    while(pv>=l)
    {
        m[{v,pv}] += w;

        v = pv;
        pv = v>>1LL;
    }
}

LL query(LL u,LL v)
{
    LL l = lca_eff(u,v);

    LL ans = 0;

    LL pu = u>>1LL;

    while(pu>=l)
    {
        ans += m[{u,pu}];

        u = pu;
        pu = u>>1LL;
    }

    LL pv = v>>1LL;

    while(pv>=l)
    {
        ans += m[{v,pv}];

        v = pv;
        pv = v>>1LL;
    }

    return ans;
}

int main()
{
    optimizeIO();

    int q;
    cin>>q;

    while(q--)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            LL u,v,w;
            cin>>u>>v>>w;

            update(u,v,w);

        }
        else
        {
            LL u,v;
            cin>>u>>v;

            cout<<query(u,v)<<endl;
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


