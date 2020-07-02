
/**

Suffix Array

Idea :

Let's think of an easier version of the current problem . How many distinct substrings are possible ?
- If you notice the LCP array carefully , you will notice that you can get the repeated substring from each value of the array
i.e lcp[i] number of substrings are repeated for that prefix.
So , The number of distinct substring = Number of total possible substrings - (Sum of all LCP values)

Now , we think of our current problem .
Notice that for each LCP[i] , length of string 1 , 2 ... lcp[i] are repeated .
So , for each LCP[i] , number of distinct substring of length 1 , 2 ... lcp[i] is reduced by 1.

Initially , number of substring of length i is n-i+1
i.e number of substring of length 1 is n ,
number of substring of length 2 is n-1 and so on.

We can do the range update operation in many ways , like applying segment tree or BIT .
Although they are overkill in this case as we have only update operations .
We can thus simply maintain a dummy array to do the update operation .

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

void count_sort(vector<int> &p,vector<int> &c)
{
    int n = p.size();

    vector<int>cnt(n);

    for(auto el:c)
        cnt[el]++;

    vector<int>np(n);
    vector<int>pos(n); /// pos[i] = first empty position in bucket i

    pos[0] = 0;
    for(int i=1; i<n; i++)
        pos[i] = pos[i-1] + cnt[i-1];

    for(auto el:p)
    {
        int i = c[el]; /// bucket
        np[pos[i]] = el; /// putting element in bucket
        pos[i]++; /// empty position in bucket i increased
    }

    p = np;

}

vector<int> buildSuffixArray(string s)
{
    s += "$";

    int n = s.size();

    /// init p , c

    vector<PII>v(n);

    for(int i=0; i<n; i++)
        v[i] = {s[i],i};
    sort(ALL(v));

    vector<int>p(n), c(n);
    for(int i=0; i<n; i++)
        p[i] = v[i].S;

    c[p[0]] = 0;
    for(int i=1; i<n; i++)
    {
        if(v[i].F!=v[i-1].F)
            c[p[i]] = c[p[i-1]] + 1;
        else
            c[p[i]] = c[p[i-1]];
    }

    /// logN times

    int k = 0;

    while((1<<k) < n)
    {
        for(int i=0; i<n; i++)
            p[i] = (p[i] - (1<<k) + n)%n;

        count_sort(p,c);

        vector<int>nc(n);

        nc[p[0]] = 0;
        for(int i=1; i<n; i++)
        {
            PII now  = { c[p[i]], c[ (p[i]+(1<<k))%n] };
            PII prev = { c[p[i-1]], c[ (p[i-1]+(1<<k))%n] };

            if(now!=prev)
                nc[p[i]] = nc[p[i-1]] + 1;
            else
                nc[p[i]] = nc[p[i-1]];
        }

        c = nc;
        k++;
    }

    /// after all the iterations , c[i] = position of the suffix i in p

    return p;
}

vector<int> buildLCPArray(string s,vector<int> &p)
{
    s+="$";
    int n = s.size();

    vector<int>rnk(n);

    for(int i=0; i<n; i++)
        rnk[p[i]] = i; /// this is basically the c array after all iterations

    vector<int>lcp(n);

    int k = 0;

    for(int i=0; i<n-1; i++)
    {
        int pi = rnk[i];
        int j = p[pi-1];

        /// lcp[i] = lcp(s[i...],s[j...])

        while(s[i+k]==s[j+k])
            k++;
        lcp[pi] = k;
        k = max(k-1,0);
    }

    return lcp;
}

int main()
{
    optimizeIO();

//    WRITE;

    int tc;
    cin>>tc;

    for(int qq=1;qq<=tc;qq++)
    {
        string s;
        cin>>s;

        int left , right;
        cin>>left>>right;

        vector<int>p = buildSuffixArray(s);
        vector<int>lcp = buildLCPArray(s,p);

//        for(int i=0; i<(int)p.size(); i++)
//        cout<<p[i]<<" "<<lcp[i]<<" "<<s.substr(p[i],s.size()-p[i])<<endl;
//        cout<<endl;

        int n = s.size();

        vector<int>sub(n+1),dummy(n+1,0);

        for(int i=1;i<=n;i++)
            sub[i] = n-i+1; /// sub[i] = number of substring of length i

        for(int i=1; i<(int)lcp.size(); i++)
        {
            int l = 1;
            int r = lcp[i];

            if(l<=r)
            {
                int upd = -1;

                dummy[l] += upd;
                if(r+1<=n) dummy[r+1] -= upd;
            }
        }


        for(int i=1;i<(int)dummy.size();i++)
            dummy[i] += dummy[i-1];

        for(int i=1;i<=n;i++)
            sub[i] += dummy[i];

        LL ans = 0;

        for(int i=left;i<=right;i++)
            ans += sub[i];

        cout<<"Case "<<qq<<": ";
        cout<<ans<<endl;
    }



    return 0;
}

/**
abb@bbabb
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


