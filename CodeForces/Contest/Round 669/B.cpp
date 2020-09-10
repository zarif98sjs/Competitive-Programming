
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
        int n;
        cin>>n;

        vector<int>v(n);

        for(int i=0; i<n; i++)
            cin>>v[i];

        sort(ALL(v));
        reverse(ALL(v));

        int g = v[0];
        vector<bool>mark(n,false);
        mark[0] = true;

        vector<int>ans;
        ans.push_back(v[0]);

        for(int i=1;i<n;i++)
        {
            int mx = 0;
            int id = 0;

            for(int j=0;j<n;j++)
            {
                if(mark[j]==false)
                {
                    int tg = __gcd(g,v[j]);

                    if(tg>mx)
                    {
                        mx = tg;
                        id = j;
                    }
                }
            }

            ans.push_back(v[id]);
            g = __gcd(g,v[id]);
            mark[id] = true;
        }

        DBG(ans);

        for(int x:ans) cout<<x<<" ";
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
