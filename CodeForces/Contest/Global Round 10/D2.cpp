
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
        string s;
        cin>>n>>s;

        int cnt = 0;

        for(int i=0;i<n;i++)
            if(s[i]==s[0]) cnt++;

        if(cnt==n)
        {
            cout<<(cnt+2)/3<<endl;
        }
        else
        {
            cnt = 1;

            s = s + "#";
            vector<int>c;

            for(int i=1;i<=n;i++)
            {
                if(s[i]==s[i-1]) cnt++;
                else
                {
                    c.push_back(cnt);
                    cnt = 1;
                }
            }

            int len = c.size();

            int ans = 0;

            for(int i=1;i<=len-2;i++)
                ans += (c[i]/3);

            if(s[0]==s[n-1])
            {
                int lagbe = c[0] + c[len-1];
                ans += (lagbe/3);
            }
            else
            {
                ans += (c[0]/3);
                ans += (c[len-1]/3);
            }

            cout<<ans<<endl;
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

