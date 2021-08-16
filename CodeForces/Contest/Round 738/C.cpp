
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
    int n;
    cin>>n;

    vector<int>v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    if(v[n] == 0) /// n -> n+1
    {
        for(int i=1;i<=n;i++)
            cout<<i<<" ";
        cout<<n+1<<endl;
        return;
    }

    if(v[1] == 1) /// n+1 -> 1
    {
        cout<<n+1<<" ";
        for(int i=1;i<=n;i++)
            cout<<i<<" ";
        cout<<endl;
        return;
    }

    for(int i=1;i<n;i++)
    {
        if(v[i] == 0 && v[i+1] == 1)
        {
            for(int j=1;j<i;j++) cout<<j<<" ";
            cout<<i<<" "<<n+1<<" "<<i+1<<" ";
            for(int j=i+2;j<=n;j++) cout<<j<<" ";
            cout<<endl;

            return;
        }
    }

    cout<<-1<<endl;
}

int32_t main()
{
    optimizeIO();

    int tc = 1;
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

