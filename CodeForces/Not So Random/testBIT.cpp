
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

LL ara[nmax];

/** BIT / FENWICK TREE **/
/*** 1 based indexing ***/

LL BIT[nmax];
void update(int index,LL val,int len) /** POINT update , adds to the current value **/
{
    while(index<=len)
    {
        BIT[index] = BIT[index]+val;
        index += index&(-index);
    }
}

LL query(int index) /** RANGE query **/
{
    LL sum=0;
    while(index>0)
    {
        sum = sum+BIT[index];
        index -= index&(-index);
    }
    return sum;
}


///===================================================================================\\\

/** binary search on BIT : lower_bound and upper_bound **/

/// for 1 based indexing with n elements , set lo = 1 , hi = n+1

int lowerBound_BIT(int lo,int hi,int key) /** O( (logN)^2 ) **/
{
    while(lo!=hi)
    {
        int mid = lo + (hi-lo)/2;

        if(query(mid)<key) lo = mid + 1;
        else hi = mid;
    }

    return lo;
}

int upperBound_BIT(int lo,int hi,int key) /** O( (logN)^2 ) **/
{
    while(lo!=hi)
    {
        int mid = lo + (hi-lo)/2;

        if(query(mid)<=key) lo = mid + 1;
        else hi = mid;
    }

    return lo;
}

/** binary search on BIT : lower_bound and upper_bound [OPTIMIZED] using Binary Lifting **/

int lowerBound_BIT_efficient(LL v,int N) /** O( logN ) **/
{
	LL sum = 0;
	LL pos = 0;

	int k = 0;
    while (1 << (k + 1) <= N)
        k++;

    /** k = log(N) **/

	for(int i=k; i>=0; i--)
	{
	    int next_idx = pos + (1 << i);

		if( next_idx < N && sum + BIT[next_idx] < v) /// For upper_bound change to "BIT[next_idx] < v" to "BIT[next_idx] <= v"
		{
			sum += BIT[next_idx];
			pos = next_idx;
		}
	}

	return pos + 1; /// +1 because 'pos' will have position of largest value less than 'v'
}

int main()
{
    //optimizeIO();

    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>ara[i];
        update(i,ara[i],n);
    }

    while(q--)
    {
        int type;
        cin>>type;

        if(type==1) /** POINT update **/
        {
            int idx,val;
            cin>>idx>>val;

            update(idx,val,n);
        }
        else /** RANGE query **/
        {
            int l,r;
            cin>>l>>r;

            cout<<query(r) - query(l-1)<<endl;
        }
    }

    return 0;
}

/**

5 100
0 0 0 0 0

**/
