
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

template<class TIn>
using indexed_multiset = tree<
                         pair<TIn,TIn>, null_type, less< pair<TIn,TIn> >,
                         rb_tree_tag, tree_order_statistics_node_update>;
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

const int nmax = 1e6+7;
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

int binary_search_bit(LL v,int N) // v is the value we are searching
{
	int l = 1, r = N;
	while(l != r)
	{
		int mid = (l+r) / 2;
		if(query(mid) < v)
			l = mid+1;
		else
			r = mid;
	}
	return l;
}

int binary_search_bit2(LL v,int N)
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

		if( next_idx < N && sum + BIT[next_idx] < v)
		{
			sum += BIT[next_idx];
			pos = next_idx;
		}
	}

	return pos + 1; /// +1 because 'pos' will have position of largest value less than 'v'
}


// Finds the first index x such that tree_sum(x) >= sum.
int binary_search_bit3(LL sum,int N) {
    // Find the last index x such that tree_sum(x) < sum, and then add one.
    int index = 0;
    int k = 0;

    while (1 << (k + 1) <= N)
        k++;

    while (k >= 0) {
        int next_index = index + (1 << k);

        if (next_index <= N && BIT[next_index] < sum) {
            index = next_index;
            sum -= BIT[index];
        }

        k--;
    }

    return index + 1;
}

int main()
{
    optimizeIO();

    int n,q;
    cin>>n>>q;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;

        update(x,1LL,n);
    }

    while(q--)
    {
        LL k;
        cin>>k;

        if(k<0)
        {
            int val = binary_search_bit2(abs(k),n);
            update(val,-1,n);
        }
        else if(k>0)
        {
            update(k,1,n);
        }
    }

    if(query(n)==0) cout<<0<<endl;
    else  cout<<binary_search_bit2(1LL,n)<<endl;

    return 0;
}

/**

6 10000
3 3 4 4 4 5
1 2 3 4 5 6
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


