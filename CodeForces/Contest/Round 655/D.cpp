
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

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<LL>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<LL>od,ev;

    for(int i=0;i<n;i++)
    {
        if(i&1) od.push_back(v[i]);
        else ev.push_back(v[i]);
    }

    vector<LL>ara;

    for(LL x:ev) ara.push_back(x);
    for(LL x:od) ara.push_back(x);

    int sz = ara.size();
    for(int i=0;i<sz;i++) ara.push_back(ara[i]);

    int k = (n+1)/2;
    LL sum = 0;
    LL mx = 0;

    n = ara.size();
//    DBG(ara);

    for(int i=0;i<n;i++)
    {
        sum += ara[i];

        if(i>=k-1)
        {
            if(i-k>=0) sum -= ara[i-k];

            DBG(sum);
            mx = max(mx,sum);
        }
    }

    cout<<mx<<endl;


    return 0;
}

/**
7
1 2 3 4 5 6 7
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


