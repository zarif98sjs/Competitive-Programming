
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second

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

LL s(LL a,LL d,LL n)
{
    LL v = n*(2*a+(n-1)*d);
    v = v/2;

    return v;
}

LL nth(LL a,LL d,LL n)
{
    LL v = a + (n-1)*d;

    return v;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,k;
        cin>>n>>k;

        vector<int>v(n);
        map<int,int>c;

        for(int i=0;i<n;i++) cin>>v[i] , c[v[i]%k]++;


        LL ans = 0;

        for(auto x:c)
        {
            DBG(x.F);
//            DBG(x.S);

            if(x.F==0)
                continue;

//            LL val = s(k-x.F,k,x.S);
            LL val = nth(k-x.F,k,x.S);
            DBG(val);
            ans = max(ans,val);
        }

        if(ans!=0) cout<<ans+1<<endl;
        else cout<<ans<<endl;
//        cout<<endl;

    }

    return 0;
}

/**
102 says: x.F = 1
110 says: val = 17
102 says: x.F = 2
110 says: val = 16
102 says: x.F = 3
110 says: val = 9
102 says: x.F = 4
110 says: val = 2
102 says: x.F = 5
110 says: val = 1
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
