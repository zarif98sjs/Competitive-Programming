
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

int main()
{
    optimizeIO();

    LL n,d,lim;
    cin>>n>>d>>lim;

    vector<LL>l , s;
    for(LL i=0; i<n; i++)
    {
        LL x;
        cin>>x;

        if(x>lim) l.push_back(x);
        else s.push_back(x);
    }

    sort(ALL(s));
    sort(ALL(l));
    reverse(ALL(l));

    DBG(s);

    LL ss = (LL)s.size();
    LL ls = (LL)l.size();

    vector<LL>cs(ss+1),cl(ls+1);

    for(int i=1;i<=ss;i++) cs[i] = cs[i-1] + s[i-1];
    for(int i=1;i<=ls;i++) cl[i] = cl[i-1] + l[i-1];

    LL ans = 0;
    for(LL k=0;k<=ls;k++)
    {
        LL already_wasted = ls-k;
        LL waste = (k-1)*d - already_wasted; /// what is wasted is already wasted . why waste more waste for that waste :)
        waste = max(0LL,waste);

        if(waste > ss) continue;

        LL cur = cl[k] + cs[ss] - cs[waste];
        ans = max(ans,cur);
    }

    cout<<ans<<endl;
    DBG(ans);


    return 0;
}

/**
20 2 16
20 5 8 2 18 16 2 16 16 1 5 16 2 13 6 16 4 17 21 7

5 2 10
1 11 11 11 12
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


