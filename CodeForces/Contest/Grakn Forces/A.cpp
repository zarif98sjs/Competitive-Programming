
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

    vector<vector<int>>v(3,vector<int>(n));

    for(int k=0;k<3;k++)
        for(int i=0;i<n;i++) cin>>v[k][i];

    int prv =  -1;
    int now = -1;

    int f  = -1;

    for(int i=0;i<n;i++)
    {
        if(v[0][i]!=prv) now = v[0][i];
        else if(v[1][i]!=prv) now = v[1][i];
        else if(v[2][i]!=prv) now = v[2][i];

        if(i==n-1)
        {
            if(v[0][i] != prv && v[0][i] != f) now = v[0][i];
            else if(v[1][i] != prv && v[1][i] != f) now = v[1][i];
            else if(v[2][i] != prv && v[2][i] != f) now = v[2][i];
        }

        if(i==0) f = now;

        cout<<now<<" ";
        prv = now;
    }

    cout<<endl;

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
