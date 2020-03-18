
/**

Idea : Try to make n with numbers such that sum is n and the product is maximum

2 = 2
3 = 3
4 = 2+2 -> 2*2 = 4
5 = 2+3 -> 2*3 = 6
6 = 3+3 -> 3*3 = 9
7 = 3+4 = 3 + 2 + 2 -> 3*2*2 = 12
8 = 3+3+2 -> 3*3*2 = 18
9 = 3+3+3 -> 3*3*3 = 27

Slowly you will see that all the numbers can be made with 2 and 3 . Finding the formula is
pretty much straight-forward.

**/


/**Which of the favors of your Lord will you deny ?**/

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

inline void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

string to_str(LL x)
{
	stringstream ss;
	ss<<x;
	return ss.str();
}

LL po(LL x,LL n) /// x^n
{
    LL res = 1;

    while(n>0)
    {
        if(n&1) res = res*x;

        x = x*x;
        n >>= 1;
    }

    return res;
}

LL bigMod(LL x,LL n,LL mo) /// x^n % mo
{
    x %= mo;

    LL res = 1;

    while(n>0)
    {
        if(n&1) res = ((res%mo)*(x%mo)) % mo;

        x = ((x%mo)*(x%mo)) %mo;
        n >>= 1;
    }

    return res;

}

/*--------------------------Template Ends-------------------------------------*/

const int nmax = 2e5+7;
const LL LINF = 1e17;
//const LL MOD = 1e9+7;

int main()
{
	optimizeIO();

	int tc;
    cin>>tc;

    while(tc--)
    {
        LL n;
        cin>>n;

        LL ans;

        LL val = n/3;

        if(n%3==0) ans = bigMod(3,val,MOD);
        else if(n%3==1) ans = (bigMod(3,val - 1,MOD) * bigMod(2,2,MOD))%MOD;
        else if(n%3==2) ans = (bigMod(3,val,MOD) * bigMod(2,1,MOD))%MOD;

        if(n==1) ans = 1;

        cout<<ans%MOD<<endl;

    }

	return 0;
}
