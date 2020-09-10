
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

#define int long long

int32_t main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        int lplus= 0 , rminus = 0;
        int tot_lplus = 0;

        for(int i=0;i<n;i++)
        {
            if(v[i]<0)
            {
                int add = min(-v[i],lplus);
                v[i] += add;
                lplus -= add;
                tot_lplus += add;
            }

            if(v[i]>0) lplus += v[i];
        }
//        DBG(v);

        for(int i=0;i<n;i++)
        {
            if(v[i]>0)
            {
                int minus = min(v[i],tot_lplus);
                v[i] -= minus;
                tot_lplus -= minus;
            }
        }

//        DBG(v);

        int ans = 0;
        for(int x:v) if(x>0) ans += x;

        cout<<ans<<endl;
        DBG(ans);

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
