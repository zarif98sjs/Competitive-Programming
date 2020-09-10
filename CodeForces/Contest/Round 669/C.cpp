
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

int sum(int n)
{
    return (n*(n+1)) / 2 ;
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    if(n==1)
    {
        cout<<"! 1\n";
        cout<<flush;

        return 0;
    }

    vector<int>ans(n+1,-1);

    int p1 = 1,p2 = 2;

    int s = 0;

    while(p2<=n)
    {
        int m1 ,m2;
        cout<<"? "<<p1<<" "<<p2<<"\n";
        cout<<flush;

        cin>>m1;

        cout<<"? "<<p2<<" "<<p1<<"\n";
        cout<<flush;

        cin>>m2;

        if(m1>m2) ans[p1] = m1 , p1 = p2 , p2++ , s += m1;
        else ans[p2] = m2 , p2++ , s += m2;
    }

    int left = sum(n) - s;

    for(int i=1;i<=n;i++) if(ans[i]==-1) ans[i] = left;

    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout << flush;

    return 0;
}

/**
4
? 1 2
1
? 2 1
2
? 1 3
0
? 3 1
1
? 1 4
3
? 4 1
1
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
