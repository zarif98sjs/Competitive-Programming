
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
#define DBG(x) cout << __LINE__ << " says: " << #x << " = " << (x) << endl
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


    int tc = 1;

    while(tc--)
    {
        string s;
        cin>>s;

        int n = s.size();

        int mx = 0;
        vector<int>ansl;
        vector<int>ansr;

        for(int i=0;i<n;i++)
        {
            vector<int>l;
            for(int j=0;j<=i;j++)
            {
                if(s[j]=='(')
                    l.push_back(j);
            }

            vector<int>r;
            for(int j=i+1;j<n;j++)
            {
                if(s[j]==')')
                    r.push_back(j);
            }

            int left = l.size();
            int right = r.size();
            int match = min(left,right);

            if(match>mx)
            {
                mx = match;

                ansl = l;
                ansr = r;
            }
        }

        if(mx==0) cout<<0<<endl;
        else
        {
            cout<<1<<endl;
            cout<<2*mx<<endl;

            vector<int>ans;

            for(int i=0;i<mx;i++) ans.push_back(ansl[i]+1);

            reverse(ALL(ansr));
            for(int i=0;i<mx;i++) ans.push_back(ansr[i]+1);

            sort(ALL(ans));

            for(int x:ans) cout<<x<<" ";
            cout<<endl;
        }

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


