
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

    int tc;
    cin>>tc;

    int cs = 1;

    while(tc--)
    {
        int n;
        cin>>n;

        vector<int>ara(n);

        for(int i=0;i<n;i++)
            cin>>ara[i];

        vector<int>v;

        for(int i=1;i<n;i++)
        {
            if(ara[i]>ara[i-1]) v.push_back(0);
            if(ara[i]<ara[i-1]) v.push_back(1);
        }

        int sz = v.size();

        int ans = 0;

        for(int i=0;i<sz;i++)
        {
            int j = i , cnt = 0;

            while(j<sz && v[j]==v[i]) cnt++ , j++;
            ans += (cnt/4);

            i = j-1;
        }

        cout<<"Case #"<<cs<<": ";
        cout<<ans<<endl;
        cs++;
    }

    return 0;
}

/**
100
9
1 2 3 4 5 4 3 2 1
8
1 2 3 4 5 4 3 2
8
5 4 3 2 1 2 3 4
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


