
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


#define int long long

int solve()
{
    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    sort(ALL(v));

    vector<int>pos,neg;
    int zero = 0;

    for(int x:v)
    {
        if(x>0) pos.push_back(x);
        else if(x<0) neg.push_back(x);
        else zero++;
    }

    sort(pos.rbegin(),pos.rend());
    sort(ALL(neg));

    int psz = pos.size();
    int nsz = neg.size();

    int ans = LLONG_MIN;
    if(zero) ans = 0;

    for(int i=0;i<=5;i++)
    {
        for(int j=0;j<=5;j++)
        {
            if(i+j==5)
            {
                if(i>psz || j>nsz) continue;

                if(j%2==0)
                {
                    /// large pos ... large negative -> large positive
                    int pr = 1;
                    for(int k=0;k<i;k++) pr *= pos[k];
                    for(int k=0;k<j;k++) pr *= neg[k];
                    ans = max(ans,pr);
                }
                else if(j&1) /// WHEN TAKING ODD NUMBER OF MINUSES
                {
                    /// small pos ... small negative -> small negative
                    int pr = 1;
                    for(int k=0;k<i;k++) pr *= pos[psz-k-1];
                    for(int k=0;k<j;k++) pr *= neg[nsz-k-1];

                    ans = max(ans,pr);
                }
            }
        }
    }

    return ans;
}

int32_t main()
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
