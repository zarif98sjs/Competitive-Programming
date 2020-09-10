
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
const int INF = 1e9;

vector<int>solveLIS(vector<int> &v)
{
    int n = v.size();

    vector<int>d(n+1,INF);
    vector<int>LIS(n,1);
    d[0] = -INF;

    for(int i=0;i<n;i++)
    {
        int len = upper_bound(ALL(d),v[i]) - d.begin();

        if(v[i] > d[len-1] && v[i] < d[len])
            d[len] = v[i] , LIS[i] = len;
    }

    // DBG(d);
    // DBG(LIS);

    // int lis_len = 0;
    // for(int i=1;i<=n;i++)
    //     if(d[i]<INF)
    //         lis_len = i;

    // DBG(lis_len);

    return LIS;
}

int solve(vector<int> &v)
{
    int n = v.size();

    vector<int>LIS = solveLIS(v);
    // DBG(LIS);
    reverse(ALL(v));
    vector<int>LDS = solveLIS(v);
    // DBG(LDS);

    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int wavio = 2 * min(LIS[i],LDS[n-i-1]) - 1;
        ans = max(ans,wavio);
    }

    return ans;
}

int main()
{
    optimizeIO();

    // WRITE;

    int n;

    while(cin>>n)
    {
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];

        int longest_bitonic = solve(v);
        cout<<longest_bitonic<<endl;
        // DBG(longest_bitonic);
    
    }

    return 0;
}

/**
10
1 2 3 4 5 4 3 2 1 10
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


