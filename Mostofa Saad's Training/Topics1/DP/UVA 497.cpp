
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

    cin.ignore();
    cin.ignore();

    while(tc--)
    {
        vector<int>v;
        string s;
        while (getline(cin, s) && s != "")
        {
            stringstream ss(s);
            int val;

            ss>>val;
            v.push_back(val);
        }

        int n = v.size();

        vector<int>dp(n,1); /** length of longest increasing sequence ending at i **/
        vector<vector<int>>seq = vector<vector<int>>(n); /** longest increasing sequence ending at i **/

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[i] > v[j])
                {
                    if(dp[j]+1 > dp[i])
                    {
                        seq[i] = seq[j];
                        dp[i] = dp[j]+1;
                    }
                }
            }

            seq[i].push_back(v[i]);
            DBG(seq[i]);
        }

        DBG(dp);

        int mx = 0;
        vector<int>MX;

        for(int i=0;i<n;i++)
        {
            if(dp[i]>mx)
            {
                mx = dp[i];
                MX = seq[i];
            }
        }

        cout<<"Max hits: "<<mx<<endl;
        for(int x:MX)
            cout<<x<<endl;

        if(tc)
            cout<<endl;
    }

    return 0;
}

/**
1

1
6
2
3
5
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


