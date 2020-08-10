
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

int main()
{
    optimizeIO();

    int na,nb,k;
    cin>>na>>nb>>k;

    vector<LL>va(na);
    vector<LL>vb(nb);

    for(int i=0;i<na;i++) cin>>va[i];
    for(int i=0;i<nb;i++) cin>>vb[i];

    for(int i=1;i<na;i++) va[i] += va[i-1];
    for(int i=1;i<nb;i++) vb[i] += vb[i-1];

    int mx = 0;

    for(int i=0;i<na;i++)
    {
        LL val = va[i];
        LL rem = k-val;

        int id = upper_bound(ALL(vb),rem)-vb.begin();
//        DBG(id);

        if(val<=k)
        {
            int pos = i+1 + id;
//            DBG(pos);
            mx = max(mx,pos);
        }
    }

    for(int i=0;i<nb;i++)
    {
        LL val = vb[i];
        LL rem = k-val;

        int id = upper_bound(ALL(va),rem)-va.begin();
//        DBG(id);

        if(val<=k)
        {
            int pos = i+1 + id;
//            DBG(pos);
            mx = max(mx,pos);
        }
    }

    cout<<mx<<endl;

    return 0;
}

/**
3 4 10
60 90 120
80 150 80 150

3 4 230
60 90 120
80 150 80 150

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


