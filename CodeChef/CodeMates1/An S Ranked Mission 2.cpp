
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ll long long
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

/**
Segmented Sieve
Range of [L,R] ~ 1e7 and R ~ 1e12
**/

const int pnmax = 1e6+10;  /** ~ sqrt(R) **/
const int pnmax2 = 5e5+10; /** diff of R and L **/

LL LIM = 1e6+5; /** ~ sqrt(R) **/
vector<LL>primes;
bool isP[pnmax];
bool isPFinal[pnmax2];
LL cnt[pnmax2];

void sieve()
{
    for(LL i=2; i<=LIM; i++)
        isP[i] = true;

    for(LL i=2; i<=LIM; i++) /** If I don't want to know the primes , it is enough to loop upto sqrt(LIM) here **/
    {
        if(isP[i]==true)
        {
            primes.push_back(i);
            for(LL j=i*i; j<=LIM; j+=i)
                isP[j]=false;
        }
    }
}

/** Number of Divisors **/

/// NOD
LL number_of_Divisors(LL N,vector<LL>&factors)
{
    LL ans = 1;

    for(auto PF:factors)
    {
        LL power = 0;     /// count the power
        while (N % PF == 0)
        {
            N /= PF;
            power++;
        }
        ans *= (power + 1);  /// according to the formula
    }

    if (N != 1) ans *= 2;  /// (last factor has pow = 1, we add 1 to it)

    return ans;
}

void segmented_sieve(LL L,LL R)
{
    vector<vector<int>>factors(pnmax2);

    for(auto p:primes)
    {
        if(p*p > R)
            break;

        LL j=p*p;

        if(j<L)
            j=((L+p-1)/p)*p;

        for(; j<=R; j+=p)
            factors[j-L].push_back(p);

    }

    /** print **/
    for(LL i=L; i<=R; i++)
    {
        cnt[i-L] = number_of_Divisors(i,factors[i-L]);
    }
}

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}


int32_t main()
{
    optimizeIO();

    sieve();

    int tc;
    cin>>tc;

    while(tc--)
    {
        LL l,r;
        cin>>l>>r;

        for(ll i=l; i<=r; i++)
        {
            cnt[i-l] = 0 ;
        }
        segmented_sieve(l,r);
        ll mini = 1e18, maxi = -1;
        ll sum = 0;
        ll scmin =0, scmax = 0, scsum =0;
        for(ll i=0; i<r-l+1; i++)
        {
            mini = min(mini, cnt[i]);
            maxi = max(maxi, cnt[i]);
        }
        for(ll i=0; i<r-l+1; i++)
        {
            if(cnt[i]==mini)
            {
                scmin+= i+l;
            }
            if(cnt[i]== maxi)
            {
                scmax+= i+l;
            }
            if(cnt[i]!=mini && cnt[i]!=maxi)
            {
                scsum+= i+l;
                sum+= cnt[i];
            }
        }
        ll idx1 = mini%26;
        ll idx2 = sum%26;
        ll idx3 = maxi%26;
        string s="";
        if(idx1%2==0)
        {
            s+= ('A'+ idx1);
        }
        else
        {
            s+= ('a'+idx1);
        }
        s+= to_str(scmin);
        if(idx2%2==0)
        {
            s+= ('A'+ idx2);
        }
        else
        {
            s+= ('a'+idx2);
        }
        s+= to_str(scmax);
        if(idx3%2==0)
        {
            s+= ('A'+ idx3);
        }
        else
        {
            s+= ('a'+idx3);
        }
        if(scsum%2)
        {
            reverse(s.begin(),s.end());
        }
        cout<<s<<"\n";


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
