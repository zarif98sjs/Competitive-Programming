
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

    int r,c;
    cin>>r>>c;

    vector< vector<int> > v(r, vector<int>(c) );

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>v[i][j] , v[i][j]--;

    LL ans = 0;

    /**

    rather than doing what could be the answer for n cyclic shifts ,
    we calculate for each element how many cyclic shifts they need .

    **/

    for(int j=0;j<c;j++)
    {
        vector<int>shift(r);

        for(int i=0;i<r;i++)
        {
            if(v[i][j]%c==j) /// this element belongs to this column
            {
                int pos = v[i][j] / c;
                if(pos<r)
                {
                    int shft = (i-pos+r)%r;
                    shift[shft]++;
                }
            }
        }

        int mn = r;

        for(int i=0;i<r;i++)
        {
            int val = r - shift[i] + i;
            mn = min(mn,val);
        }

        ans += mn;
    }

    cout<<ans<<endl;

    return 0;
}

/**

4 3
7 2 3
10 5 6
1 8 9
4 11 12

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


