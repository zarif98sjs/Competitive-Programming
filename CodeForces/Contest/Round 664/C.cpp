
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

    int n1,n2;
    cin>>n1>>n2;

    vector<int>v1(n1);
    vector<int>v2(n2);

    vector<int>c(n1,1e8);

    for(int i=0; i<n1; i++)
        cin>>v1[i];
    for(int i=0; i<n2; i++)
        cin>>v2[i];

    int ans = 1000;

    for(int b=0; b<(1<<9); b++)
    {
        vector<bool>ok(n1,false);

        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
               int now = v1[i] & v2[j];

               if( (now & b) == now ) ok[i] = true;
            }
        }

        bool hobe = true;

        for(int i=0;i<n1;i++)
            if(ok[i]==false) hobe = false;

        if(hobe)
        {
//            DBG(b);
            ans = min(ans,b);
        }

    }

    cout<<ans<<endl;
    DBG(ans);

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


