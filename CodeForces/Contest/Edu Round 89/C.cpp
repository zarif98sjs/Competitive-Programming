
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

int ara[55][55];
int dist[55][55];
vector<int>v[200];

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        for(int i=0;i<200;i++)
            v[i].clear();

        int r,c;
        cin>>r>>c;

        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                cin>>ara[i][j];

        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                dist[i][j] = abs(i-1) + abs(j-1);

        int mx = 0;

        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                dist[i][j] = min(dist[i][j],abs(r-i) + abs(c-j)) , mx = max(mx,dist[i][j]);


        int val = r+c-1;

        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                v[dist[i][j]].push_back(ara[i][j]);

        int ans = 0;
        int lim = val/2;

        for(int d=0;d<lim;d++)
        {
            int zero = 0;
            int one = 0;

            for(int x :v[d])
            {
                if(x==0) zero++;
                else one++;
            }
//
//            DBG(d);
//            DBG(zero);
//            DBG(one);

            ans = ans + min(zero,one);
        }


        cout<<ans<<endl;
//        cout<<endl;


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


