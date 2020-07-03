
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

string ara[20];

int diff(string a,string b)
{
    int cnt = 0;
    for(int i=0; i<a.size(); i++)
        if(a[i]!=b[i])
            cnt++;

    return cnt;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,len;
        cin>>n>>len;

        for(int i=0; i<n; i++)
            cin>>ara[i];

        string ans;
        bool ok=false;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int d = diff(ara[i],ara[j]);

                string temp = ara[i];

                if(d==2)
                {
                    bool f = false;

                    for(int k=0; k<ara[i].size(); k++)
                        if(ara[i][k]!=ara[j][k] && f==false)
                            temp[k] = ara[j][k], f = true;
                }

                ok = true;
                for(int k=0; k<n; k++)
                {
                    if(diff(temp,ara[k])>1)
                        ok = false;
                }

                if(ok)
                {
                    ans = temp;
                    break;
                }


            }

            if(ok)
                break;
        }

        if(ok)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;


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
