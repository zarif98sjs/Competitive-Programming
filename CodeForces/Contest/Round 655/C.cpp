
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

        for(int i=1;i<=n;i++) cin>>v[i];

        bool zero = true;

        for(int i=1;i<=n;i++)
        {
            if(v[i]!=i)
                zero = false;
        }

        if(zero)
        {
            cout<<0<<endl;
        }
        else
        {
            bool ok = false;

            vector<int>pos;

            for(int i=1; i<=n; i++)
            {
                if(v[i]!=i)
                {
                    pos.push_back(i);
                }
            }

            pos.push_back(n+10);

            int sz = pos.size();

            int cnt = 0;

            for(int i=1;i<sz;i++)
            {
                if(pos[i]-pos[i-1]>1)
                    cnt++;
            }

            if(cnt>1) cout<<2<<endl;
            else cout<<1<<endl;
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


