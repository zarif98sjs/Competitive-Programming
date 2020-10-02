
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

#define int long long

const int nmax = 2e5+7;

void solveTC()
{
    int N,start,MOD;
    cin>>N>>start>>MOD;

    vector<int>v;
    v.push_back(start);

    map<int,int>ID;

    int rem = N-1;
    int ans = start;

    for(int i=0;i<N-1;i++)
    {
        int now = v.back();
        ID[now] = i;

        now *= now;
        now %= MOD;

        if(ID.count(now))/// cycle
        {
            int clen = 0;
            int csum = 0;

            for(int j=ID[now];j<(int)v.size();j++)
            {
                csum += v[j];
                clen++;
            }

            int c = rem/clen; /// how many full cycle
            ans += c*csum;

            rem %= clen;

            for(int j=ID[now];rem>0;j++,rem--)
                ans += v[j];

            break;
        }

        ans += now;
        v.push_back(now);

        rem--;
    }

    cout<<ans<<endl;
    DBG(ans);
}

int32_t main()
{
    optimizeIO();

    int tc = 1;
//    cin>>tc;

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
