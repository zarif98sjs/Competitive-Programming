
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
ostream &operator <<(ostream &os, multiset<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;

int main()
{
    optimizeIO();

    int nr,ng,nb;
    cin>>nr>>ng>>nb;

    multiset<int>r,g,b;

    int x;
    for(int i=0;i<nr;i++) cin>>x  , r.insert(x);
    for(int i=0;i<ng;i++) cin>>x  , g.insert(x);
    for(int i=0;i<nb;i++) cin>>x  , b.insert(x);

    LL ans = 0;

    while(true)
    {
        int cnt = 0;

        if(r.empty())cnt++;
        if(g.empty())cnt++;
        if(b.empty())cnt++;

        if(cnt>=2) break;

        int v1 = 0 , v2 = 0 , v3 = 0;

        if(!r.empty()) v1 = *r.rbegin();
        if(!g.empty()) v2 = *g.rbegin();
        if(!b.empty()) v3 = *b.rbegin();

        DBG(r);
        DBG(g);
        DBG(b);

        int mn = min(v1,min(v2,v3));

        if(mn==v1)
        {
            ans += (1LL*v2*v3);
            g.erase(g.lower_bound(v2));
            b.erase(b.lower_bound(v3));
        }
        else if(mn==v2)
        {
            ans += (1LL*v1*v3);
            r.erase(r.lower_bound(v1));
            b.erase(b.lower_bound(v3));
        }
        else if(mn==v3)
        {
            ans += (1LL*v1*v2);
            r.erase(r.lower_bound(v1));
            g.erase(g.lower_bound(v2));
        }
    }

    cout<<ans<<endl;
    DBG(ans);

    return 0;
}

/**
10 1 1
11 7 10 10 10 14 2 4 13 14
8
11
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
ostream &operator <<(ostream &os, multiset<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}


