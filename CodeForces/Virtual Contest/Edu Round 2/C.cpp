
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

vector<int>cnt(26);
int n;

void solve()
{
    DBG(cnt);

    for(int i=0; i<26; i++)
    {
        if(cnt[i]%2==1)
        {
            for(int j=25; j>i; j--)
            {
                if(cnt[j]%2==1)
                {
                    cnt[j]--;
                    cnt[i]++;

                    break;
                }
            }
        }
    }

    DBG(cnt);
}

string construct()
{
    bool odd = n%2;
    char mid;

    string ans = "";

    for(int i=0; i<26; i++)
    {
        if(cnt[i]%2==1) mid = 'a'+i;

        for(int j=0; j<cnt[i]/2; j++) ans += char(i+'a');
    }

    string t = ans;
    reverse(ALL(t));

    if(odd) ans += mid;
    ans += t;

    DBG(ans);
    return ans;
}

int main()
{
    optimizeIO();

    string s;
    cin>>s;

    n = s.size();

    for(auto ch:s) cnt[ch-'a']++;

    solve();
    string ans = construct();
    cout<<ans<<endl;

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
