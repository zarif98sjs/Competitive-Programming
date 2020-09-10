
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

string st,tr;
int n,k;
int dp[205][205][30];

int count_substr(string str,string t)
{
    int len = str.size();
    str = "#" + str;
    char f = t[0];
    char s = t[1];

    vector<int>pfx(len+1,0);

    for(int i=1; i<=n; i++) pfx[i] = pfx[i-1] + (str[i]==s);

    int ans = 0;
    for(int i=1; i<=len; i++)
    {
        if(str[i]==f)
        {
            ans += (pfx[len]-pfx[i]);
        }
    }

    return ans;
}
int cnt = 0;
void gen(int pos,string built)
{
    if(pos==(int)st.size())
    {
        //DBG(built);
        cnt++;
        return;
    }

    for(int i=0;i<26;i++)
    {
        gen(pos+1,built+char(i+'a'));
    }
}

int main()
{
    optimizeIO();

    cin>>n>>k;
    cin>>st>>tr;

    gen(0,"");
    cout<<cnt<<endl;

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
