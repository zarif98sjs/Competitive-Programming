
/**

**/

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

const int nmax = 1e3+7;
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

LL mod = 1e9+7;
LL f[nmax];
LL po2[nmax];

void precalc()
{
    f[0] = 1;
    po2[0] = 1;

    for(int i=1; i<nmax; i++)
        f[i] = (f[i-1]%mod * i%mod)%mod;

    for(int i=1; i<nmax; i++)
        po2[i] = (po2[i-1]%mod * 2)%mod;
}

LL bigMod(LL x,LL n,LL mo)
{
    if(n==0)
        return 1;

    LL u = bigMod(x,n/2,mo);
    u = ((u%mo)*(u%mo))%mo;

    if(n%2==1)
        u = ((u%mo)*(x%mo))%mo;

    return u;
}

LL invMod(LL a,LL mo)
{
    LL uttor = bigMod(a,mo-2,mo);

    return uttor;
}

int ara[nmax];

int main()
{
    optimizeIO();

    precalc();

    int n,m;
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        int x;
        cin>>x;
        ara[x] = 1;
    }

    ara[n+1] = 1;

    LL cnt = 0;

    vector<LL>v;

    for(int i=1; i<=n+1; i++)
    {
        if(ara[i]==0)
            cnt++;
        else
        {
            v.push_back(cnt);
            cnt = 0;
        }
    }

//    cout<<v<<endl;

    LL ans = f[n-m];
//    DBG(ans);

    for(auto x:v)
    {
        ans = (ans%mod * invMod(f[x],mod)%mod)%mod;
    }

//    DBG(ans);

    if(v.size()>2)
    {
        for(int i=1;i<v.size()-1;i++)
            if(v[i]>0) ans = (ans * po2[v[i]-1])%mod;
    }

    cout<<ans<<endl;

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


