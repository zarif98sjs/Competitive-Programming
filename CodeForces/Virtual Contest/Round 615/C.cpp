
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

PLL hasTwoDiv(LL n,LL no)
{
    for(LL i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i!=(n/i) && i!=no && (n/i)!=no)
                return {i,n/i};
        }
    }

    return {-1,-1};
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        LL n;
        cin>>n;

        bool ok = true;

        for(LL i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                PLL v1 = hasTwoDiv(i,n/i);
                PLL v2 = hasTwoDiv(n/i,i);

                if(v1.F!=-1)
                {
                    cout<<"YES"<<endl;
                    cout<<n/i<<" "<<v1.F<<" "<<v1.S<<endl;
                    ok = false;
                    break;
                }
                else if(v2.F!=-1)
                {
                    cout<<"YES"<<endl;
                    cout<<i<<" "<<v2.F<<" "<<v2.S<<endl;
                    ok = false;
                    break;
                }
            }
        }

        if(ok)
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


