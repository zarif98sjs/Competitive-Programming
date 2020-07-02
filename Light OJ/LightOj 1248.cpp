
/**

First expected value problem I solved was : https://atcoder.jp/contests/dp/tasks/dp_j

Now , I took idea from that problem and solved it .
Another way to look at this problem is there are n 1's and in one move we can make any 1 to 0 .
Now the question becomes the expected value of all becoming 0 .

**/

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

const int nmax = 1e5+7;
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

//    WRITE;

    int tc;
    scanf("%d",&tc);

    for(int q=1;q<=tc;q++)
    {
        int n;
        scanf("%d",&n);

        vector<double>p(n+1);  /** probability **/
        vector<double>ev(n+1); /** expected value **/

        /// (n) -> (0)

        p[n] = 1;

        for(int i=n; i>=0; i--)
        {
            if(i==0)
                continue;

            double p_waste = (double)(n-i)/n;
            /// ev_waste = p_waste + p_waste^2 + ....
            double ev_waste = p_waste/(1-p_waste) + 1 ; /** +1 is because I also need to move to some other state other than wasting **/

            ev[i] += ev_waste * p[i];

            /// remove 1 from 1's pile
            if(i!=0)
            {
                double p_here = 1; /** probability of coming to this state is i/i **/
                p[i-1] += p[i] * p_here;
                ev[i-1] += ev[i] * p_here;
            }
        }

        printf("Case %d: ",q);
        printf("%0.6f\n",ev[0]);
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


