
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

int32_t solve()
{
    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    sort(ALL(v));

    int mul=1 , len = 5;

    if (v[n - 1] == 0 && (len & 1))
        return 0;

    if (v[n - 1] <= 0 && (len & 1))
    {
        for (int i = n - 1; i >= n - len; i--)
            mul *= v[i];
        return mul;
    }

    vector<int>f,pos,neg;

    for(int x:v)
    {
        if(x>=0) pos.push_back(x);
        else neg.push_back(x);
    }

    sort(ALL(pos));
    reverse(ALL(pos)); /// large to small

    sort(ALL(neg));

    DBG(pos);
    DBG(neg);

    int t1 = 5;
    int t2 = 0;

    int mx = LLONG_MIN;

    for(int round=1;round<=3;round++)
    {
        int taken1 = 0, taken2 = 0;
        int s1 = 1, s2 = 1;

        for(int i=0;i<min((int)pos.size(),t1);i++) s1 *= pos[i] , taken1++;
        for(int i=0;i<min((int)neg.size(),t2);i++) s2 *= neg[i] , taken2++;

        if(taken1==t1 && taken2==t2) mx = max(mx,s1*s2);

        t1 -= 2;
        t2 += 2;
    }


    t2 = 5;
    t1 = 0;

    for(int round=1;round<=3;round++)
    {
        int taken1 = 0, taken2 = 0;
        int s1 = 1, s2 = 1;

        for(int i=0;i<min((int)pos.size(),t1);i++) s1 *= pos[i] , taken1++;
        for(int i=0;i<min((int)neg.size(),t2);i++) s2 *= neg[i] , taken2++;

        if(taken1==t1 && taken2==t2) mx = max(mx,s1*s2);

        t1 += 2;
        t2 -= 2;
    }

    return mx;
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
10
10
1 2 3 5 4 -10 -20 -30 -40 -50
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
