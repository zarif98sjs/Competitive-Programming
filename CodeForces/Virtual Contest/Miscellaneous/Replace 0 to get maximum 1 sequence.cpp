
/**

Technique
=========

Two Pointer | Sliding Window

Problem
=======

Given a binary array , find the index of 0 to be replaced with 1 to get the maximum length sequence of continuous 1's

Idea
====

There can be only one 0 in the window


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

int ara[nmax];

void printArray(int A[],int l,int r)
{
    cout<<"[ ";
    for(int i=l; i<=r; i++)
        cout<<A[i]<<" ";
    cout<<"] \n";
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>ara[i];

    bool zero_ase = false;
    int cur_zero_idx = -1;
    int zero_idx = -1;

    int p1 = 1, p2 = 1;
    int mx = 0;


    while(p2<=n)
    {
        while(p2<=n && ((ara[p2]==1) || (ara[p2]==0 && zero_ase==false))) /** if 1 or if first 0 , progress right pointer **/
        {
            if(ara[p2]==0) zero_ase = true , cur_zero_idx = p2;
            p2++;
        }

//        DBG(p1);
//        DBG(p2);
//        DBG(cur_zero_idx);

        if(p2-p1>mx)
        {
            mx = p2-p1;
            zero_idx = cur_zero_idx;
        }

        while(p2<=n && (ara[p2]==0 && zero_ase==true)) /** unless one 0 is removed , progress left pointer **/
        {
            if(ara[p1]==0) zero_ase = false;
            p1++;
        }
    }

    cout<<"Index of the zero to be replaced : "<<<zero_idx<<endl;
    cout<<"Maximum length of the sequence : "<<mx<<endl;

    return 0;
}

/**

10
0 0 1 0 1 1 1 0 1 1

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


