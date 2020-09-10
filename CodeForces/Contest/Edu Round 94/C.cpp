
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
        string res;
        cin>>res;

        int n = res.size();

        int x;
        cin>>x;

        string main (n,'1');

        for(int i=0;i<n;i++)
        {
            if(res[i]=='0')
            {
                if(i-x>=0) main[i-x] = '0';
                if(i+x<n) main[i+x] = '0';
            }
        }

        bool ok = true;

        for(int i=0;i<n;i++)
        {
            bool one = false;

            if(res[i]=='1')
            {
                if(i-x>=0 && main[i-x]=='1') one = true;
                if(i+x<n && main[i+x]=='1') one = true;

                if(one==false) ok = false;
            }
        }

        DBG(ok);

        if(ok) cout<<main<<endl;
        else cout<<-1<<endl;

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
