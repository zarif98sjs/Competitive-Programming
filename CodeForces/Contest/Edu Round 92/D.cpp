
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

    int tc;
    cin>>tc;

    while(tc--)
    {
        LL n,k;
        cin>>n>>k;

        PLL l , r;
        cin>>l.F>>l.S;
        cin>>r.F>>r.S;

        if(l>r) swap(l,r);

        LL a = l.F , b = l.S;
        LL c = r.F , d = r.S;

        LL INT = max(0LL,min(b,d) - max(a,c));

        if(k<=n*INT)
        {
            cout<<0<<endl;
            continue;
        }

        k -= n*INT;

        LL cost1 = max(c-b,0LL);
        LL cost2 = max(b,d) - a - INT; /** NOT d-a , NOT d-a-INT **/

        LL ans = LLONG_MAX;

        for(int i=1;i<=n;i++)
        {
            LL mv = i*cost1;

            LL kp = i*cost2;

            if(k<= kp) mv += k;
            else
            {
                mv += kp;
                LL diff = k - kp;
                mv += 2*diff;
            }

            ans = min(ans,mv);
        }

        cout<<ans<<endl;
    }

    return 0;
}

/**
10
10 1696
266 654
34 347

72 says: cost1 = 0
73 says: cost2 = 539
74 says: INT = 81
92 says: mv = 2691
92 says: mv = 2152
92 says: mv = 1615
92 says: mv = 1615
92 says: mv = 1615
92 says: mv = 1615
92 says: mv = 1615
92 says: mv = 1615
92 says: mv = 1615
92 says: mv = 1615
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


