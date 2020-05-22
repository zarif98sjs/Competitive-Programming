
/**

TAG : BINARY SEARCH | MEET IN THE MIDDLE
=========================================

The idea is that you split the large set into two small sets, small enough for you to handle them using the standard algorithm you know,
and then use the result from these two small sets to arrive at the required solution.

Problem Link :https://www.codechef.com/INSQ2015/problems/INSQ15_C

Related Problems :

LightOj 1127
LightOj 1235

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
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>
using indexed_set = tree<
                    TIn, null_type, less<TIn>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/*
PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

*/

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

const int nmax = 1e6+7;
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

bool isprime[nmax];
LL factors[nmax];
void sieve(int n)
{
    for (int i = 0; i <= n; i++) {
		isprime[i] = 1;
        factors[i] = 1;
	}
	isprime[1] = 0;
	isprime[2] = 1;
	for (int i = 2; i <= n; i++) {
		if (isprime[i]) {
            factors[i] = i;
			for (int j = 2; i*j <= n; j++) {
                int product = i*j;
                isprime[product] = 0;
                factors[product] *= i;
			}
		}
    }
}

int k;

vector<vector<LL> > subsetSum(const vector<LL> &v)
{
    int n = v.size();

    vector<vector<LL> >sum(17);

    for(int i=0; i<(1<<n); i++)
    {
        LL s = 0;

//        if(__builtin_popcount(i)>k)
//            continue;

        int set_bits = 0;

        for(int j=0; j<n; j++)
        {
            if(i&(1<<j))
            {
                s += factors[v[j]];
                set_bits++;
            }

        }

        sum[set_bits].push_back(s);
    }

    return sum;

}

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    sieve(1e6);

    int n;
    LL a,b;

    cin>>n>>k>>a>>b;

    vector<LL>v1,v2;

    for(int i=0; i<n; i++)
    {
        LL x;
        cin>>x;

        if(i&1)
            v2.push_back(x);
        else
            v1.push_back(x);
    }

    vector< vector<LL> > subsetSum1 = subsetSum(v1);
    vector< vector<LL> > subsetSum2 = subsetSum(v2);

    int mid = (n+1)/2;

    for(int i=0; i<=mid; i++)
        sort(ALL(subsetSum2[i]));

    LL ans = 0;

    for(int l1=0; l1<=mid; l1++)
    {
        for(int l2=0; l2<=mid; l2++)
        {
            if(l1+l2>k)
                continue;

            for(auto s1:subsetSum1[l1])
            {
                LL a2 = a - 1 - s1;
                LL b2 = b - s1;

                /** SOLVE(B) - SOLVE(A-1) **/

                ans += upper_bound(ALL(subsetSum2[l2]),b2) - subsetSum2[l2].begin();
                ans -= upper_bound(ALL(subsetSum2[l2]),a2) - subsetSum2[l2].begin();
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}

/**

4 2 3 6
5 2 3 4

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






