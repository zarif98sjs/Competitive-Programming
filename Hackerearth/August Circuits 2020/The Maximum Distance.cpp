#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

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

#define int long long

int32_t main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;

            for(int i=l;i<=r;i++)
                v[i] += x;
        }
        if(type==2)
        {
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;

            for(int i=l;i<=r;i++)
                v[i] *= x;
        }
        if(type==3)
        {
            int val;
            cin>>val;

            vector<int>po;

            for(int i=0;i<n;i++)
            {
                if(v[i]==val)
                    po.push_back(i);
            }

            int sz = (int)po.size();

            if(sz==0) cout<<-1<<endl;
            else if(sz==1) cout<<1<<endl;
            else
            {
                int mx = 0;

                for(int i=1;i<sz;i++)
                    mx = max(mx,po[i]-po[i-1]+1);

                cout<<mx<<endl;
            }
        }
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
