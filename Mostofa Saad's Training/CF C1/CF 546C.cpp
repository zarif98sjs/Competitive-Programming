
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

set< pair< deque<int>,deque<int> > >S;

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    int k1;
    cin>>k1;

    deque<int>a;
    for(int i=0; i<k1; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    int k2;
    cin>>k2;

    deque<int>b;
    for(int i=0; i<k2; i++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }

    int cnt = 0 ;

    bool ok = true;

    while(1)
    {

        int v1 = a.front();
        int v2 = b.front();

        a.pop_front();
        b.pop_front();

        if(v1<v2)
        {
            b.push_back(v1);
            b.push_back(v2);
        }
        else
        {
            a.push_back(v2);
            a.push_back(v1);
        }

        cnt++;

        if(a.empty() || b.empty())
            break;

        if(S.count(MP(a,b))) /** A visited state is again visited , means cycle **/
        {
            ok = false;
            break;
        }
        else
            S.insert(MP(a,b));
    }


    if(ok)
    {
        cout<<cnt<<" ";

        if(a.empty())
            cout<<2<<endl;
        if(b.empty())
            cout<<1<<endl;

    }
    else
        cout<<-1<<endl;

    return 0;
}

/**

4
2 1 2
2 4 3

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


