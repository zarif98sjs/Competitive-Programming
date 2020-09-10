
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

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        vector<int>v1(3);
        vector<int>v2(3);

        cin>>v1[0]>>v1[1]>>v1[2];
        cin>>v2[0]>>v2[1]>>v2[2];

        int ans = 0;

        int t21 = min(v1[2],v2[1]);
        ans += 2*t21;

        v1[2] -= t21;
        v2[1] -= t21;

        DBG(v1);
        DBG(v2);

        for(int i=2;i>=0;i--)
        {
            int txy = min(v1[i],v2[i]);
            v1[i] -= txy;
            v2[i] -= txy;

            txy = min(v1[i],v2[0]);
            v1[i] -= txy;
            v2[0] -= txy;

            txy = min(v1[0],v2[i]);
            v1[0] -= txy;
            v2[i] -= txy;
        }

        DBG(v1);
        DBG(v2);

        ans -= 2*min(v1[1],v2[2]);
        cout<<ans<<endl;
        DBG(ans);
        // if(v1[2]>=v2[1]) v1[2] -= v2[1] , v1[1] = 0;
        // else if(v1[2]<v2[1]) v2[1] -= v1[2] , v2[1] = 0;



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


