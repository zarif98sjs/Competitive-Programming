
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

void solveTC()
{
    int n;
    cin>>n;

    vector<int>a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    vector<int>endPA(n+1,-1); /// ending position in a

    for(int i=0;i<n;i++) endPA[a[i]] = i;

    int max_shift = 0;

    for(int i=0;i<n;i++)
    {
        if(i>0 && b[i]==b[i-1]) continue;
        if(endPA[b[i]]==-1) continue;

        int stPB = i;
        if(stPB <= endPA[b[i]])
        {
            int shift = endPA[b[i]] - stPB + 1;
            max_shift = max(shift,max_shift);
        }
    }

    vector<int>new_pos(n),ans(n);

    for(int i=0;i<n;i++) new_pos[i] = (i + max_shift) % n;
    for(int i=0;i<n;i++) ans[new_pos[i]] = b[i];

    bool hobe = true;
    for(int i=0;i<n;i++) if(a[i]==ans[i]) hobe = false;

    if(hobe)
    {
        cout<<"Yes"<<endl;
        for(int x:ans) cout<<x<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    DBG(ans);
}

int32_t main()
{
    optimizeIO();

    int tc = 1;

    while(tc--)
    {
        solveTC();
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
