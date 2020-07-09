
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

LL lcm(LL a,LL b)
{
    LL g = __gcd(a,b);

    return (a/g)*b;
}

int main()
{
    optimizeIO();

    while(1)
    {
        int n,t;
        cin>>n>>t;

        if(n==0 && t==0)
            break;

        vector<LL>v(n);

        for(int i=0; i<n; i++)
            cin>>v[i];

        for(int i=0; i<t; i++)
        {
            LL x;
            cin>>x;

            LL ans1 = 0 , ans2 = LLONG_MAX;

            for(int i=0; i<n; i++)
                for(int j=i+1; j<n; j++)
                    for(int k=j+1; k<n; k++)
                        for(int m=k+1; m<n; m++)
                        {
                            vector<int>temp;
                            temp.push_back(v[i]);
                            temp.push_back(v[j]);
                            temp.push_back(v[k]);
                            temp.push_back(v[m]);

                            LL l = temp[0];
                            for(LL xx:temp)
                                l = lcm(l,xx);

                            LL mn = (x/l)*l;
                            LL mx = mn;

                            if(mx!=x) mx += l;

                            ans1 = max(ans1,mn);
                            ans2 = min(ans2,mx);

                        }



            cout<<ans1<<" "<<ans2<<endl;
        }

    }

    return 0;
}

/**
4 2
50
100
200
400
1000
2000

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


