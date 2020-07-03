
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

//const int nmax = 2e5+7;
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

const int nmax = 1e6+5;
const int nmax2 = nmax<<2;

string s;
int n;

struct node
{
    int left,right , pfx , sum;

    node()
    {
        left = right = pfx = sum = 0;
    }

    void merge_nodes(node &a,node &b)
    {
        int matched = min(a.left,b.right);
        left = a.left + b.left - matched;
        right = a.right + b.right - matched;

        sum = a.sum + b.sum;
        pfx = max(a.pfx, a.sum+b.pfx);
    }

    void create_leaf(char ch,int val = 0)
    {
        if(ch=='(') left = 1 , right = 0;
        else if(ch==')') left = 0 , right = 1;
        else left = 0 , right = 0;

        pfx = sum = val;
        return;
    }

};

node Tree[nmax2];

void build(int cur,int start,int end)
{
    if(start==end)
    {
        Tree[cur].create_leaf(s[start]);
        return;
    }

    int lc = 2*cur, rc = 2*cur+1;
    int mid = (start+end)/2;

    build(lc,start,mid);
    build(rc,mid+1,end);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);

}

void update(int cur, int start, int end, int updex, char value ,int value2) /** POINT update , replaces the current value **/
{
    if (start == end)
    {
        Tree[cur].create_leaf(value,value2);
        return;
    }

    int mid = (start + end)>>1;
    int lc = cur<<1, rc = lc|1;

    if (updex <= mid)
        update(lc, start, mid, updex, value,value2);
    else
        update(rc, mid+1, end, updex, value,value2);

    Tree[cur].merge_nodes(Tree[lc],Tree[rc]);
}


void query(node &res,int cur,int start,int end,int l,int r)
{
    if(start>=l && end<=r)
    {
        res = Tree[cur];
        return;
    }

    int lc = 2*cur, rc = 2*cur+1;
    int mid = (start+end)/2;

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

int main()
{
    optimizeIO();

//    string s;
//    cin>>s;
//
//    int n = s.size();
//    vector<int>v(n);
//
//    for(int i=0;i<n;i++)
//    {
//        if(s[i]=='(') v[i] = 1;
//        else if(s[i]==')') v[i] = -1;
//
//        if(i>0) v[i]+=v[i-1];
//    }
//
//    cout<<v<<endl;

    cin>>n;
    s = "#";

    for(int i=1;i<=n;i++) s +="#";

    build(1,1,n);

    string m;
    cin>>m;

    int p = 1;
    int mx = p;


    for(int i=0;i<(int)m.size();i++)
    {
        if(m[i]=='R') p++;
        else if(m[i]=='L') {if(p>1) p--;}
        else if(m[i]=='(') update(1,1,n,p,'(',1) , s[p] = m[i];
        else if(m[i]==')') update(1,1,n,p,')',-1), s[p] = m[i];
        else if(s[p]!='#') update(1,1,n,p,'#',0);

//        if(m[i]!='R' && m[i]!='L')
//        {
//            s[i] = m[i];
//            DBG(s);
//        }

        mx = max(mx,p);

        node t;
        query(t,1,1,n,1,mx);

//        DBG(m[i]);
//        DBG(p);

//        DBG(i);
//        DBG(t.left);
//        DBG(t.right);
//        DBG(t.pfx);

        if(t.left>0 || t.right>0) cout<<-1<<" ";
        else cout<<t.pfx<<" ";
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


