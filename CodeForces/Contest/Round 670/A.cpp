
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
#define endl "\n"
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

int solve()
{
    int n;
    cin>>n;

    vector<int>v(n);

    int off = 0;
    for(int i=0; i<n; i++)
        cin>>v[i], off += (v[i]==0);

    if(off==0) return 0;
    else if(off==1)
    {
        int mex = 0;
        set<int>st;
        for(int x:v) st.insert(x);
        while(st.find(mex)!=st.end())
            mex++;

        return mex;
    }
    else if(off>=2)
    {
        set<int>st1,st2;

        for(int x:v)
        {
            if(st1.find(x)==st1.end()) st1.insert(x);
            else st2.insert(x);
        }

        int mex1 = 0;
        while(st1.find(mex1)!=st1.end())
            mex1++;

        int mex2 = 0;
        while(st2.find(mex2)!=st2.end())
            mex2++;

        return mex1+mex2;
    }

}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int ans = solve();
        DBG(ans);
        cout<<ans<<endl;

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
