
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

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        string s;
        cin>>s;

        vector<int>c(5,0);

        for(char x:s)
            c[x-'0']++;

        int n = s.size();
        s = "x"+s;

        vector<int>cnt(5,0);

        int p1 = 1, p2 = 1;
        int ans = INT_MAX;

        while(1)
        {
            while(p2<=n && (cnt[1]==0 || cnt[2]==0 || cnt[3]==0 ) )
            {
                cnt[s[p2]-'0']++;
                p2++;
            }

//            DBG(p1);
//            DBG(p2);

            while(p2<=n && cnt[s[p1]-'0']>1)
            {
                 cnt[s[p1]-'0']--;
                 p1++;
            }

//            DBG(p1);
//            DBG(p2);

            if(cnt[1]!=0 && cnt[2]!=0 && cnt[3]!=0 ) ans = min(ans,p2-p1);

            cnt[s[p1]-'0']--;
            p1++;

            if(p2>n && p1>n)
                break;
        }

        if(ans==INT_MAX)
            cout<<0<<endl;
        else
            cout<<ans<<endl;

    }



    return 0;
}

/**

232323123213

122231

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


