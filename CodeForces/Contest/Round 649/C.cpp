
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

int ara[nmax];
int ans[nmax];

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    set<int>st;

    for(int i=1; i<=n; i++)
        cin>>ara[i], st.insert(ara[i]);

    int v = *st.begin();

    if(st.size()==1 && v==0)
    {
        if(v==0)
        {
            for(int i=1; i<=n; i++)
                cout<<1<<" ";
            cout<<endl;
        }
        else if(v==1)
        {
            for(int i=1; i<=n; i++)
                cout<<2<<" ";
            cout<<endl;
        }
        else
            cout<<-1<<endl;

        return 0;
    }
    if(st.size()==2 && v==0)
    {
        int v1 = *st.begin();
        int v2 = *st.rbegin();

        if(v1==0 && v2==1)
        {
            for(int i=1; i<=n; i++)
            {
                if(ara[i]==0) cout<<2<<" ";
                if(ara[i]==1) cout<<0<<" ";
            }
            cout<<endl;
        }
        else if(v1==0 && v2==2)
        {
            for(int i=1; i<=n; i++)
            {
                if(ara[i]==0) cout<<1<<" ";
                if(ara[i]==2) cout<<0<<" ";
            }
            cout<<endl;
        }
        else
            cout<<-1<<endl;

        return 0;
    }

    if(v==0)
    {
        cout<<-1<<endl;
        return 0;
    }

    bool ok = true;
    int mx = -1;

    for(int i=1;i<=n;i++)
    {
        if(ara[i]>i)
        {
            ok = false;
            break;
        }

        if(ara[i]!=ara[i-1])
            mx++;

        ans[i] = mx ;
    }

    if(ok)
    {
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    else
        cout<<-1<<endl;

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


