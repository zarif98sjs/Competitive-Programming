
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

void solveTC()
{
    int nn;
    cin>>nn;

    vector<int>v(nn),l(nn);

    for(int i=0; i<nn; i++)
        cin>>v[i];
    for(int i=0; i<nn; i++)
        cin>>l[i];

    vector<int>p,n,pos;

    for(int i=0; i<nn; i++)
        if(l[i]==0)
        {
            if(v[i]>=0) p.push_back(v[i]);
            if(v[i]<0) n.push_back(v[i]);

            pos.push_back(i);
        }

    sort(ALL(p));
    reverse(ALL(p));

    sort(ALL(n));
    reverse(ALL(n));

    vector<int> t = p;
    for(int x:n) t.push_back(x);

    vector<int> ans = v;

    for(int i=0; i<(int)pos.size(); i++)
        ans[pos[i]] = t[i];

    for(int x:ans)
        cout<<x<<" ";
    DBG(ans);

}

int32_t main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        solveTC();
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
