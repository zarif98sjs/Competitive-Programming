
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

const int nmax = 2e5+7;

#define int long long 

int32_t main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int>large(n,0),small(n,0);
    indexed_set<int>st;

    st.insert(v[0]);
    for(int i=1;i<n;i++)
    {
        int l = 0;
        int r = i-1;

        int cnt = r-l+1 - st.order_of_key(v[i]);
        large[i] = cnt;

        st.insert(v[i]);
    }
    st.clear();

    st.insert(v[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        int cnt = st.order_of_key(v[i]);
        small[i] = cnt;
        st.insert(v[i]);
    }

    DBG(large);
    DBG(small);

    int ans = 0;
    for(int i=0;i<n;i++)
        ans += large[i]*small[i];

    cout<<ans<<endl;

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


