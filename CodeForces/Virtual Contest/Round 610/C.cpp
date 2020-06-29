
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

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

PLL ara[nmax];
LL d[nmax];

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        LL n,tot,a,b;
        cin>>n>>tot>>a>>b;

        LL cntEasy = 0 , cntHard = 0;

        for(LL i=1; i<=n; i++)
        {
            LL x;
            cin>>x;

            if(x)
                ara[i].S = b , cntHard++;
            else
                ara[i].S = a , cntEasy++;
        }

        for(LL i=1; i<=n; i++)
            cin>>ara[i].F;

        sort(ara+1,ara+n+1);

        for(LL i=1; i<=n; i++)
            d[i] = ara[i].F;

        cout<<endl;

        for(LL i=1; i<=n; i++)
            cout<<ara[i].S<<" ";
        cout<<endl;

        for(LL i=1; i<=n; i++)
            cout<<ara[i].F<<" ";
        cout<<endl;

        LL s = 0;
        LL ans = 0;

        for(LL i=1; i<=n; i++)
        {
            s += ara[i].S;

            DBG(s);
            int id = upper_bound(d+1,d+n+1,s)-d-1;
            DBG(id);

            if(id==i && i!=n)
                ans = i;
            if(i==n && s<=tot)
                ans = n;

        }

        LL beforeEasy = min(cntEasy,(d[1]-1)/a);
        LL left = d[1] - beforeEasy*a;
        LL beforHard = min(cntHard,left/b);

        cout<<"ANS : "<<max(ans,beforeEasy+beforHard)<<endl;
        cout<<endl;
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


