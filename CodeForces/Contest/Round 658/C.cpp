
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

string flip_rev(string x)
{
    for(int i=0;i<(int)x.size();i++)
    {
        if(x[i]=='0') x[i] = '1';
        else if(x[i]=='1') x[i] = '0';
    }

    reverse(ALL(x));

    return x;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        string s1,s2;
        cin>>s1>>s2;

        s1 = s1 + '0';
        s2 = s2 + '0';

        vector<int>v1;
        vector<int>v2;

        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s1[i+1]) v1.push_back(i);
        }

        for(int i=0;i<n;i++)
        {
            if(s2[i]!=s2[i+1]) v2.push_back(i);
        }

        vector<int>ans;

        for(int x:v1) ans.push_back(x);
        reverse(ALL(v2));
        for(int x:v2) ans.push_back(x);

        int as = ans.size();

        cout<<as<<" ";

        for(int x:ans)
            cout<<x+1<<" ";
        cout<<endl;
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


