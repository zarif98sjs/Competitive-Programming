
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

        vector<int>v(n);
        vector<string>ans;

        int mx = 1;

        for(int i=0;i<n;i++)
            cin>>v[i] , mx = max(mx,v[i]);

        string s = "";
        for(int j=0; j<mx; j++)
                s += 'a';
        ans.push_back(s);

        for(int i=0;i<n;i++)
        {
            string t = ans[i];

            int go = v[i];

            string now = "";

            for(int j=0;j<go;j++) now += t[j];
            for(int j=go;j<mx;j++)
            {
                int tc = t[j] - 'a';
                int nv = (tc + 1)%26;
                now = now + char('a'+nv);
            }

            ans.push_back(now);
        }


//        cout<<ans[0].substr(0,max(1,v[0]))<<"\n";

        for(string x:ans)
        {
            cout<<x<<"\n";
        }


    }

    return 0;
}

/**
1
4
2 0 2 0
aa
aa
aa
aa
a
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


