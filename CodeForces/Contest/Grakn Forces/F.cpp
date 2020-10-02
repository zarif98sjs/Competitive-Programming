
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

    int sz = 1;

    while(sz<=n)
    {
        sz = sz<<1;
    }

    sz = sz>>1;

    DBG(sz);

    vector<PII>p;

    for(int add = 1;add<=15000; add = add<<1)
    {
        vector<bool>done(n+1,false);

        for(int i=1;i<=sz;i++)
        {
            if(done[i]) continue;

            int j = i+add;

            if(j<=sz) p.push_back({i,j});
            else break;

            done[i] = true;
            done[j] = true;
        }
    }

    for(int add = 1;add<=15000; add = add<<1)
    {
        vector<bool>done(n+1,false);

        for(int i=n,t=sz;t>0;i--,t--)
        {
            if(done[i]) continue;

            int j = i-add;

            if(j>n-sz) p.push_back({i,j});
            else break;

            done[i] = true;
            done[j] = true;
        }
    }

    int ans = p.size();
    cout<<ans<<endl;

    for(auto x:p)
    {
        cout<<x.F<<" "<<x.S<<endl;
    }
}

int32_t main()
{
    optimizeIO();

    int tc = 1;
//    cin>>tc;

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
