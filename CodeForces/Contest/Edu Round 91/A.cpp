
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
        int n;
        cin>>n;

        vector<int>v(n+1);

        for(int i=1;i<=n;i++)
            cin>>v[i];

        vector<PII>mn(n+1);
        vector<PII>mx(n+1);

        int mnv = INT_MAX;
        int mnid = -1;
        int mxv = INT_MAX;
        int mxid = -1;

        for(int i=1;i<=n;i++)
        {
            mn[i] = {mnv,mnid};
            if(v[i]<mnv)
            {
                mnv = min(mnv,v[i]);
                mnid = i;
            }
        }

        for(int i=n;i>=1;i--)
        {
            mx[i] = {mxv,mxid};
            if(v[i]<mxv)
            {
                mxv = min(mxv,v[i]);
                mxid = i;
            }
        }
//
//        DBG(mn);
//        DBG(mx);

        bool ok = false;


        for(int i=1;i<=n;i++)
        {
            if(v[i]>mn[i].F && v[i]>mx[i].F)
            {
                cout<<"YES"<<endl;
                cout<<mn[i].S<<" "<<i<<" "<<mx[i].S<<endl;
                ok = true;
                break;
            }
        }

        if(!ok)
            cout<<"NO"<<endl;

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


