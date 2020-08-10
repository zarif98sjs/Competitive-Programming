
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

    int tc = 1;

    while(tc--)
    {
        LL n,k;
        cin>>n>>k;

        vector<LL>a,b,c;

        for(int i=0;i<n;i++)
        {
            LL x,l1,l2;
            cin>>x>>l1>>l2;

            if(l1==1 && l1!=l2) a.push_back(x);
            if(l2==1 && l1!=l2) b.push_back(x);
            if(l1==1 && l2==1) c.push_back(x);
        }

        cout<<"asdas"<<endl;

//        c.push_back(0);

        sort(ALL(a));
        sort(ALL(b));
        sort(ALL(c));

        for(int i=1;i<a.size();i++) a[i] += a[i-1];
        for(int i=1;i<b.size();i++) b[i] += b[i-1];
        for(int i=1;i<c.size();i++) c[i] += c[i-1];

        cout<<"asdas"<<endl;
//
        cout<<a<<endl;
        cout<<b<<endl;
        cout<<c<<endl;


        LL mn = LLONG_MAX;

        for(int i=0;i<c.size();i++)
        {
            cout<<i<<endl;

            LL val1 = c[i];
            int take = i+1;

            int other = k - take;

            LL val2 = 0 , val3 = 0;

            LL take1 = take , take2 = take;

            if(other-1<a.size()) val2 = a[other - 1] , take1 += other ;
            if(other-1<b.size()) val3 = b[other - 1] , take2 += other ;

            if(take1>=k && take2>=k)
            {
                mn = min(mn,val1+val2+val3);
            }
        }

        if(mn==LLONG_MAX) cout<<-1<<endl;
        else  cout<<mn<<endl;

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


