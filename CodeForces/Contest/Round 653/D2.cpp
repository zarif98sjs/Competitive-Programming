
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
//    optimizeIO();

    int tc;
    scanf("%d",&tc);

    while(tc--)
    {
        int n,k;
        scanf("%d %d",&n,&k);

        vector<int>v(n);
//
//        LL ans = 0;

        for(int i=0; i<n; i++)
        {
            scanf("%d",&v[i]);

            v[i] = v[i]%k;
        }

        sort(ALL(v));

        int cnt= 0;
        LL ans = 0;

//        cout<<v<<endl;

        for(int i=1; i<n; i++)
        {
            if(v[i]!=v[i-1])
            {
//                DBG(v[i-1]);
                LL val = nth(k-v[i-1],k,cnt+1);
//                DBG(val);
                if(v[i-1]!=0)
                    ans = max(ans,val);

                cnt = 0;
            }
            else
                cnt++;
        }

        if(v[n-1]!=0)
        {
            LL val = nth(k-v[n-1],k,cnt+1);
            ans = max(ans,val);
        }



        if(ans !=0)
            ans++;

        printf("%lld\n",ans);
//
//        if(ans!=0) cout<<ans+1<<"\n";
//        else cout<<ans<<"\n";
//        cout<<endl;

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


