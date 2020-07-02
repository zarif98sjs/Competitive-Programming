
/**

Suffix Array + 2 Pointer

Idea:

Let's think an easier version of this problem . We have to find the longest common substring of 2 strings .
In that case , we concatenate 2 strings and build the suffix array .
Now the answer is the max of all LCP(i,j) where i belongs to the suffix starting from the first string and j belongs to the suffix starting from the second string.
and LCP(i,j) means longest common prefix of suffix starting from i and j .
We can find LCP(i,j) by finding the minimum value in the LCP array in the range [i+1,j] .
Bruteforcing all the i , j value will lead to O(N^2) solution . We can see in the suffix array that the resulting answer can be found only checking the adjacent suffixes if the belong from different strings.
You can easily prove why that is the case (Think about the sorted property of Suffix Array)

Now let's think of the current problem . We have to find the longest common substring of 3 strings .
We similarly concatenate 3 strings and build the suffix array .
Now the answer is the max of all LCP(i,j,k) where i,j,k belongs to suffix starting from the first , second and third string respectively .
We can see that our range will contain at least one type of each string in every possible cases .
Thus we can make a 2 pointer solution and find all the ranges where each type of string occurs at least once . And query LCP of that range .

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

LL ara[nmax];

/** Segment Tree **/
/*** 1 based indexing ***/

struct node
{
    LL mn;

    void create_leaf(LL val)
    {
        mn=val;
    }

    void merge_nodes(node &A,node &B)
    {
        mn = min(A.mn , B.mn);
    }

};

const int nmax2 = nmax<<2;
node Tree[nmax2];

void build(int cur,int start,int end) /** build the segment tree **/
{
    if(start==end)
    {
        Tree[cur].create_leaf(ara[start]);
        return;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    build(lc,start,mid);
    build(rc,mid+1,end);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);

}

void query(node &res,int cur,int start,int end,int l,int r) /** RANGE query **/
{
    if(l>r)
        return;

    if(start>=l && end<=r)
    {
        res = Tree[cur];
        return;
    }

    int mid = (start+end)>>1;
    int lc = cur<<1, rc = lc|1;

    if(r<=mid)
        query(res,lc,start,mid,l,r);
    else if(l>mid)
        query(res,rc,mid+1,end,l,r);
    else
    {
        node left,right;
        query(left,lc,start,mid,l,r);
        query(right,rc,mid+1,end,l,r);
        res.merge_nodes(left,right);
    }
}

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

int longestCommonSubstring(string s1,string s2,string s3)
{
    string s = s1 + char(38) + s2 + char(37) + s3 + char(36);

//    cout<<s<<endl;

    int sz1 = s1.size();
    int sz2 = s2.size();

    vector<int>p = buildSuffixArray(s);
    vector<int>lcp = buildLCPArray(s,p);

    for(int i=0;i<lcp.size();i++)
        ara[i] = lcp[i];

    build(1,1,lcp.size());

    vector<int>TYPE(lcp.size());

    for(int i=0;i<p.size();i++)
    {
        int now = p[i];

        int type = -1;

        if(now>sz1+sz2+1) type = 2;
        else if(now>sz1) type = 1;
        else type = 0;

        TYPE[now] = type;
    }

//    for(int i=0; i<(int)p.size(); i++)
//        cout<<i<<" "<<p[i]<<" "<<lcp[i]<<" "<<TYPE[p[i]]<<" "<<s.substr(p[i],s.size()-p[i])<<endl;
//    cout<<endl;

    int mx = 0;
    string ans = "";

    int p1 = 0;
    int p2 = 0;

    int lim = lcp.size();

    vector<int>ok(3,0);

    while(1)
    {
        while(p2<lim && (ok[0]==0 || ok[1]==0 || ok[2]==0))
        {
            ok[TYPE[p[p2]]]++;
            p2++;
        }

        while(p2<lim && ok[TYPE[p[p1]]]>1)
        {
            ok[TYPE[p[p1]]]--;
            p1++;
        }

        if(ok[0]>0 && ok[1]>0 && ok[2]>0)
        {
            node temp;
            query(temp,1,1,lim,p1+1,p2-1);
            int mn = temp.mn;
            mx = max(mx,mn);
        }

        ok[TYPE[p[p1]]]--;
        p1++;

        if(p1>=lim && p2>=lim)
            break;
    }

    return mx;
}

int main()
{
    optimizeIO();

//    WRITE;

    int tc;
    cin>>tc;

    for(int qq=1; qq<=tc; qq++)
    {
        string s1,s2,s3;
        cin>>s1>>s2>>s3;

        int ans = longestCommonSubstring(s1,s2,s3);

        cout<<"Case "<<qq<<": ";
        cout<<ans<<endl;
    }

    return 0;
}

/**
xrjpreppn
yjprep
mwcyjprepsy
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


