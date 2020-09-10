
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

const int nmax = 5e4+7;

class Solution {
public:

    int dp[nmax];

    int solve(int pos,vector<int>&v)
    {
        int n = v.size();

        if(pos<0 || pos>n-1) return false;
        if(v[pos]==0) return true;

        int &ret = dp[pos];
        if(ret != -1) return ret;

        ret = false;

        if(solve(pos-v[pos],v)) return ret = true;
        if(solve(pos+v[pos],v)) return ret = true;

        return ret = false;
    }

    bool canReach(vector<int>& arr, int start) {
        memset(dp,-1,sizeof dp);
        return solve(start,arr);
    }
};

int main()
{
    optimizeIO();

    int n , st;
    cin>>n >>st;

    vector<int>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    Solution sol;

    int ans = sol.canReach(v,st);
    DBG(ans);


    return 0;
}

/**

7 5
4 2 3 0 3 1 2

5 2
3 0 2 1 2

[4,2,3,0,3,1,2], start = 5
[3,0,2,1,2], start = 2
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


