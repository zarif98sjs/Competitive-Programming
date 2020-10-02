
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

const int nmax = 2e5+7;

void solveTC()
{
    int n,q;
    cin>>n>>q;

    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    indexed_set<int>s;
    multiset<int>d;

    sort(ALL(v));

    for(int x:v)
        s.insert(x);
    for(int i=1; i<n; i++)
        d.insert(v[i]-v[i-1]);

    int lo = *s.begin();
    int hi = *s.rbegin();
    int max_d = 0;
    if((int)d.size()>0) max_d = *d.rbegin();
    else max_d = 0;

    int ans = hi-lo-max_d;

    cout<<ans<<endl;
    DBG(ans);

    while(q--)
    {
        int type,val;
        cin>>type>>val;

        if(type==0)
        {
            int nxt = *s.upper_bound(val);
            int nxt_idx = s.order_of_key(nxt);

            if(*s.rbegin()==val) nxt_idx = s.size();
            int prv = 0;
            if(nxt_idx-2>=0) prv = *s.find_by_order(nxt_idx-2);

            DBG(prv);
            DBG(nxt);

            if(*s.rbegin()==val && *s.begin()==val)
            {
                s.erase(val);
            }
            else if(*s.rbegin()==val)
            {
                s.erase(val);
                if(!d.empty())d.erase(d.lower_bound(val-prv));
            }
            else if(*s.begin()==val)
            {
                s.erase(val);
                if(!d.empty())d.erase(d.lower_bound(nxt-val));
            }
            else
            {
                int diff = nxt-prv;

                s.erase(val);
                d.insert(diff);
                if(!d.empty())d.erase(d.lower_bound(val-prv));
                if(!d.empty())d.erase(d.lower_bound(nxt-val));
            }

            if(!s.empty())lo = *s.begin();
            if(!s.empty())hi = *s.rbegin();
            if((int)d.size()>0)max_d = *d.rbegin();
            else max_d = 0;

//
//            DBG(lo);
//            DBG(hi);


            ans = hi-lo-max_d;
            if(s.empty()) ans = 0;
            cout<<ans<<endl;
            DBG(ans);

        }
        else
        {
            int nxt = 0;
            if(!s.empty()) nxt = *s.lower_bound(val);
            int nxt_idx = s.order_of_key(nxt);

            if(!s.empty() && *s.rbegin()<val) nxt_idx = s.size();
            int prv = 0;
            if(nxt_idx-1>=0) prv = *s.find_by_order(nxt_idx-1);

//            DBG(prv);
//            DBG(nxt);

            if(s.empty())
            {
                s.insert(val);
            }
            else if(*s.rbegin()<val)
            {
                s.insert(val);
                d.insert(val-prv);
            }
            else if(*s.begin()>val)
            {
                s.insert(val);
                d.insert(nxt-val);
            }
            else
            {
                int diff = nxt-prv;

                s.insert(val);
                if(!d.empty())d.erase(d.lower_bound(diff));
                d.insert(val-prv);
                d.insert(nxt-val);
            }

            if(!s.empty())lo = *s.begin();
            if(!s.empty())hi = *s.rbegin();
            if((int)d.size()>0)max_d = *d.rbegin();
            else max_d = 0;

            DBG(lo);
            DBG(hi);
            DBG(max_d);
            ans = hi-lo-max_d;
            if(s.empty()) ans = 0;
            cout<<ans<<endl;
            DBG(ans);
        }

    }
}

int32_t main()
{
    optimizeIO();

    int tc = 1;
    while(tc--)
    {
        solveTC();
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
