
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

const int nmax = 1e6+7;

int ara[nmax];

/** Bit Sieve **/

const int pnmax = 1e6+7;
LL LIM;
bitset<pnmax> bs;   /// can sieve upto 1e8 in ~ 1 sec
int spf[pnmax];

void bit_sieve(LL upperbound)
{
    LIM = upperbound + 1;
    bs.set();                                     /// set all bits to 1
    bs[0] = bs[1] = 0;
    for (LL i = 2; i <= LIM; i++) /** If I don't want to know the primes , it is enough to loop upto sqrt(LIM) here **/
        if (bs[i])
        {
            for (LL j = i * i; j <= LIM; j += i)
                bs[j] = 0, spf[j] = i;
            spf[i] = i;
        }
}

/** Prime Factorization **/

bool ok = true;
bool vis[nmax];

void primeFactors(LL N)
{
    while(N>1)
    {
        LL sml = spf[N];

        if(N%sml==0)
        {
            if(vis[sml]==true) ok = false;
            else vis[sml] = true;

            while(N%sml==0)
            {
                N/=sml;
            }
        }
    }
}

int main()
{
    optimizeIO();

    bit_sieve(1e6);

    int n;
    cin>>n;


    for(int i=1; i<=n; i++) cin>>ara[i];

    int g = ara[1];

    for(int i=1; i<=n; i++)
    {
        g = __gcd(g,ara[i]);

        primeFactors(ara[i]);
    }

    if(ok) cout<<"pairwise coprime"<<endl;
    else
    {
        if(g==1)cout<<"setwise coprime"<<endl;
        else cout<<"not coprime"<<endl;
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
