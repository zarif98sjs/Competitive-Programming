
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

    for(int i=0;i<n1;i++) cin>>v1[i];
    for(int i=0;i<n2;i++) cin>>v2[i];

    for(int x:v2)
    {
        bitset<10>val2(x);
        DBG(val2);
    }


    for(int i=0;i<n1;i++)
    {
        cout<<"HERE "<<i<<endl;
        for(int j=0;j<n2;j++)
        {
            c[i] = min(c[i],v1[i]&v2[j]);

            bitset<10>b(v1[i]&v2[j]);
            DBG(b);
        }
    }

    int ans = 0;

     for(int x:c)
     {
        bitset<10>f(x);
        DBG(f);
     }

    for(int x:c)
        ans |= x;

    DBG(ans);

    bitset<10>mee(ans);
    DBG(mee);

    bitset<10>act(147);
    DBG(act);

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


