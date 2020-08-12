
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

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
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

/** Bit Sieve **/

const int pnmax = 3.2e7+7;
LL LIM;
bitset<pnmax> bs;   /// can sieve upto 1e8 in ~ 1 sec
vector<LL> primes;

void bit_sieve(LL upperbound)
{
    LIM = upperbound + 1;
    bs.set();                                     /// set all bits to 1
    bs[0] = bs[1] = 0;
    for (LL i = 2; i <= LIM; i++) /** If I don't want to know the primes , it is enough to loop upto sqrt(LIM) here **/
        if (bs[i])
        {
            for (LL j = i * i; j <= LIM; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
}

bool isPrime(LL N)
{
    if (N <= LIM)
        return bs[N];                   /// O(1) for small primes

    /** note: only work for N <= (last prime in "primes" vector)^2 . So, if Sieve is done upto 10^6 , can know isPrime upto 10^12 **/
    for (LL x:primes)
        if (N % x == 0)
            return false;
    return true;                    /// it takes longer time if N is a large prime!
}



/** Prime Factorization **/

LL primeFactors_po_gcd(LL N)
{
    LL PF_idx = 0, PF = primes[PF_idx];
    LL g = 0;
    while (N != 1 && (PF * PF <= N))     /// stop at sqrt(N), but N can get smaller
    {
        LL power = 0;
        while (N % PF == 0)
        {
            N /= PF;    /// remove this PF
            power++;
        }
        PF = primes[++PF_idx];                              /// only consider primes!

        g = __gcd(g,2*power);
    }
    if (N != 1)
        g = __gcd(g,2LL);     /// special case if N is actually a prime

    return g;
}

LL findNthRoot(double x, int n)
{

// Initialize boundary values
    double low, high;
    if (x >= 0 and x <= 1)
    {
        low = x;
        high = 1;
    }
    else
    {
        low = 1;
        high = x;
    }

// used for taking approximations
// of the answer
    double epsilon = 0.00000001;

// Do binary search
    double guess = (low + high) / 2;
    while (abs((pow(guess, n)) - x) >= epsilon)
    {
        if (pow(guess, n) > x)
        {
            high = guess ;
        }
        else
        {
            low = guess ;
        }
        guess = (low + high) / 2;
    }

//    DBG(guess);

    return (LL)guess;
}

/// NOD
LL number_of_Divisors(LL N)
{
    LL PF_idx = 0, PF = primes[PF_idx], ans = 1;             /// start from ans = 1
    while (N != 1 && (PF * PF <= N))
    {
        LL power = 0;                                             /// count the power
        while (N % PF == 0)
        {
            N /= PF;
            power++;
        }
        ans *= (power + 1);                              /// according to the formula
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans *= 2;             /// (last factor has pow = 1, we add 1 to it)
    return ans;
}

map<LL,LL>isSq;

void precalc(LL lim)
{
    for(LL i=1; i<=lim; i++)
        isSq[i*i*i] = i*i;
}

int main()
{
    optimizeIO();

    //bit_sieve(3.2e7);
    precalc(1e5);

    int tc = 100;
    while(tc--)
    {

        LL n;
        cin>>n;

        if(isSq.find(n)!=isSq.end())
        {
            cout<<isSq[n]<<endl;
            continue;
        }

        for(LL i=1;i<=50;i++)
        {
            double v = powl(n,1/i);

            LL fv = floor(v);
            LL cv = ceil(v);

            LL v1 = powl(fv,i);
            LL v2 = powl(cv,i);

            if(v1==n || v2==n)
            {
                cout<<i<<endl;
                break;
            }
        }

        cout<<-1<<endl;
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


