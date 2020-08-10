
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

void TEST_CASE()
{
    int n;
    cin>>n;

    string s,t;
    cin>>s>>t;

    vector<vector<int>>conv(26,vector<int>(26));

    for(int i=0;i<n;i++)
    {
        if(t[i]<s[i])
        {
            cout<<-1<<endl;
            return;
        }
        else if(s[i]<t[i])
        {
            conv[s[i]-'a'][t[i]-'a'] = true;
        }

    }

    int ans = 0;

    for(int i=0;i<26;i++)
    {
        for(int j=i+1;j<26;j++)
        {
            if(conv[i][j])
            {
                ans++;

                for(int k=j+1;k<26;k++)
                {
                    if(conv[i][k])
                        conv[j][k] = true;
                }

                break;
            }
        }
    }

    cout<<ans<<endl;
    DBG(ans);
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        TEST_CASE();
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


