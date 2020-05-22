
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

int ara[nmax];
int cnt[nmax];

int main()
{
    //freopen("out.txt","w",stdout);

    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        memset(cnt,0,sizeof cnt);

        int n;
        cin>>n;

        for(int i=1; i<=n; i++)
            cin>>ara[i], cnt[ara[i]]++;

        int g = cnt[ara[1]];

        int s = 0, b = 0;

        bool sok = false;

        for(int i=2; i<=n; i++)
        {
            if(ara[i]!=ara[i-1] && sok==false)
            {
                if(s<=g)
                    s += cnt[ara[i]];
                if(s>g)
                {
                    sok = true;
                    continue;
                }

            }

            if(ara[i]!=ara[i-1] && sok==true)
            {
                if(g+s+b+cnt[ara[i]]<=n/2)
                    b += cnt[ara[i]];
                else
                    break;
            }
        }

        if(s>g && b>g && g+s+b<=n/2 && g>0 && s>0 && b>0)
        {
            cout<<g<<" "<<s<<" "<<b<<endl;
        }
        else
            cout<<0<<" "<<0<<" "<<0<<endl;

    }

    return 0;
}

/**

5
12
5 4 4 3 2 2 1 1 1 1 1 1
20
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
32
64 64 63 58 58 58 58 58 37 37 37 37 34 34 28 28 28 28 28 28 24 24 19 17 17 17 17 16 16 16 16 11

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



