/**
Problem : Longest Increasing Subsequence
**/


/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#endif

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

/** 1 based indexing **/

/**
LIS[i] = LIS ending at index i
**/

int solveLIS(vector<int>&v)
{
    int n = v.size();

    vector<int> temp = v;
    sort(ALL(temp));

    vector<int>LIS(n,1); /** length of longest increasing sequence ending at i **/

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(v[i]>v[j])
            {
                if(LIS[j]+1 > LIS[i])
                {
                    LIS[i] = LIS[j]+1;
                }
            }
        }
    }

    int lis_len = *max_element(ALL(LIS));

}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    int ans = solveLIS(v);
    DBG(ans);

    return 0;
}
/**
5
1 6 2 3 5
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
    for(T i:v)
    {
        os<<i<<" " ;
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
