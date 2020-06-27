
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

bool cmp(const PII &A,const PII &B)
{
    if(A.F==B.F)
        return A.S<B.S;

    return A.F < B.F;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        vector<PII>v(n);

        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v[i] = {x,y};
        }

        v.push_back({0,0});

        sort(ALL(v),cmp);

        bool ok = true;

        string ans = "";

        for(int i=0;i<(int)v.size()-1;i++)
        {
            int x1 = v[i].F , y1 = v[i].S;
            int x2 = v[i+1].F , y2 = v[i+1].S;

            if(x2-x1<0 || y2-y1<0)
            {
                ok = false;
                break;
            }

            for(int j=0;j<(x2-x1);j++)
                ans += "R";
            for(int j=0;j<(y2-y1);j++)
                ans += "U";
        }

        if(ok)
        {
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }
        else
            cout<<"NO"<<endl;

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


