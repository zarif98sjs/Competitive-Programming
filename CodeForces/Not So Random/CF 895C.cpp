
/**

**/

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

const int MOD = 1e9+7;
const int MX = 70;

template <class T>
T bm(T b, T p, T m ) /// Faster than recursive one
{
    T res = 1 % m, x = b % m;
    while ( p )
    {
        if ( p & 1 )
            res = ( 1LL * res * x ) % m;
        x = ( 1LL * x * x ) % m;
        p >>= 1;
    }
    return res;
}

int mul(int a,int b)
{
    return a * 1LL * b %MOD;
}

int add(int a,int b)
{
    return (a+b)%MOD;
}

vector<int>primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int dp[MX+1][1<<19];

int32_t main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int>v(n),freq(MX+5),mask(MX+5);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x , freq[x]++;
    }

    vector<int>ev(MX+5,1); /// take nC0 + nC2 + ... = 2 ^ (n-1) , if no freq then nC0 = 1 way
    for(int val=1;val<=MX;val++) if(freq[val]) ev[val] = bm(2,freq[val]-1,MOD);

    vector<int>od(MX+5); /// take nC1 + nC3 + ... = 2 ^ (n-1)
    for(int val=1;val<=MX;val++) if(freq[val]) od[val] = ev[val];


    for(int num=1;num<=MX;num++)
    {
        for(int i=0;i<(int)primes.size();i++)
        {
            int val = num;

            int p = primes[i];
            int cnt = 0;

            while(val % p == 0)
            {
                val /= p;
                cnt++;
            }

            if(cnt&1) mask[num] |= (1<<i);
        }
    }


    int pmx = 19;

    dp[0][0] = 1;

    for(int val = 1;val<=MX;val++)
    {
        for(int msk=0;msk<(1<<pmx);msk++)
        {
            dp[val][msk] += mul(ev[val],dp[val-1][msk]); /// take even number of times , nothing will happen
            dp[val][msk] += mul(od[val],dp[val-1][msk^mask[val]]); /// take odd number of times , bitmask will change

            dp[val][msk] %= MOD;
        }
    }

    int ans = (dp[70][0] - 1 + MOD)%MOD;

    cout<<ans<<endl;
    DBG(ans);

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
