
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

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int n;
    cin>>n;

    vector<int>v1(n) , v2(n);

    for(int i=0;i<n;i++)
        cin>>v1[i];

    for(int i=0;i<n;i++)
        cin>>v2[i];

    bool one = false;
    vector<int>v1t1,v1t2;
    for(int i=0;i<n;i++)
    {
        if(v1[i]==1) one = true;

        if(one) v1t1.push_back(v1[i]);
        else v1t2.push_back(v1[i]);
    }

    vector<int>v1t = v1t1;

    for(int x:v1t2)
        v1t.push_back(x);

    one = false;
    vector<int>v2t1,v2t2;
    for(int i=0;i<n;i++)
    {
        if(v2[i]==1) one = true;

        if(one) v2t1.push_back(v2[i]);
        else v2t2.push_back(v2[i]);
    }

    vector<int>v2t = v2t1;

    for(int x:v2t2)
        v2t.push_back(x);

    int ans = 0;
    for(int i=0;i<n;i++)
        if(v1t[i]==v2t[i])
            ans++;

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


