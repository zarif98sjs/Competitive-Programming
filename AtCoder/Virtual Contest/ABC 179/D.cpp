
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

#define int long long
const int nmax = 2e5+7;
const int MOD = 998244353;

/** BIT / FENWICK TREE **/
/*** 1 based indexing ***/

struct Fenwick{

    vector<LL>BIT;
    int N;

    Fenwick (int n) : BIT(n+1,0) , N(n) {}

    inline int LSB(int x) {return x&(-x);} /// find the number with first bit set

    /// POINT update : adds val to index idx
    void add(int idx,LL val)
    {
        for(int i = idx ; i<=N ; i += LSB(i)) /// adding LSB , jumping to next segment covered by this index
            BIT[i] += val , BIT[i] %= MOD;
    }

    /// prefix sum upto index idx
    LL pref(int idx)
    {
        LL sum = 0;

        for(int i = idx ; i>0 ; i -= LSB(i)) /// removing LSB , jumping to next segment covering upto index
            sum += BIT[i] , sum %= MOD;

        return sum;
    }

    /// RANGE update : adds val to [l,r]
    void update(int l,int r,LL val)
    {
        add(l,val%MOD);
        add(r+1,(-val+MOD)%MOD);
    }

    void debug()
    {
        cout<<"Prefix Sum Array : ";
        for(int i=1;i<=N;i++)
            cout<<pref(i)<<" ";
        cout<<endl;
    }
};

void solveTC()
{
    int n,k;
    cin>>n>>k;

    vector<PII>segment(k);

    for(int i=0;i<k;i++)
    {
        int l,r;
        cin>>l>>r;

        segment[i] = {l,r};
    }

    Fenwick f(2*n);

    f.update(1,1,1);

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            int here = f.pref(i);
            here %= MOD;

            int l = segment[j].F;
            int r = segment[j].S;

            f.update(i+l,i+r,here);
        }
    }

    int ans = f.pref(n);
    cout<<ans<<endl;
    DBG(ans);
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
