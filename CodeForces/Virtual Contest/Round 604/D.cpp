
/**

EDITORIAL
----------
Firstly, let's arrange even numbers. It is optimal to arrange those numbers as 0,0,0,…,0,2,2,…2.
Because we can place number 1 anywhere while number 3 only between two numbers 2 or at the end beside a number 2.
So we need to maximize the number of positions where we can place number 3.
The above gives us an optimal way. The next step is to place the remaining numbers 1,3.
Inserting them in internal positions first then at the ends later.

Base on the above argument, we can do as following way that eliminates corner case issues:

Starting from a number (try all possible value 0,1,2,3).
At any moment, if x is the last element and there is at least number x−1 remains, we append x−1
otherwise we append x+1 or stop if there is no x+1 left.
If we manage to use all numbers then we have a beautiful sequence and answer is 'YES'.

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

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    map<int,int>n;
    int sum = 0;

    for(int i=0;i<4;i++)
        cin>>n[i] , sum +=n[i] ;

    for(int i=0;i<4;i++)
    {
        if(!n[i]) continue;

        vector<int>ans;

        auto temp = n;

        temp[i]--;
        ans.push_back(i);
        int last = i;

        for(int j=1;j<=sum-1;j++)
        {
            if(temp[last-1])
            {
                temp[last-1]--;
                ans.push_back(last-1);
                last--;
            }
            else if(temp[last+1])
            {
                temp[last+1]--;
                ans.push_back(last+1);
                last++;
            }
            else
                break;
        }

        if(ans.size()==sum)
        {
            cout<<"YES"<<endl;

            for(auto x:ans)
                cout<<x<<" ";
            cout<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;

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


