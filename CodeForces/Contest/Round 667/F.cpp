
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
Power
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

int solve(int pos,int mv,int chr,string built)
{
    if(pos==(int)st.size())
    {
        DBG(built);
        if(mv<=k) return count_substr(built,tr);
        return INT_MIN;
    }

    int &ret = dp[pos][mv][chr];
    if(ret != -1) return ret;

//    cout<<pos<<" "<<mv<<endl;

    ret = INT_MIN;
    for(int i=0; i<26; i++)
    {
        char ch = 'a' + i;

        if(ch == st[pos]) ret = max(ret, solve(pos+1,mv,i,built+ch));
        else ret = max(ret, solve(pos+1,mv+1,i,built+ch));
    }

    return ret;
}





int main()
{
    optimizeIO();

    cin>>n>>k;
    cin>>st>>tr;

    memset(dp,-1,sizeof dp);
    int ans = solve(0,0,0,"");
    cout<<ans<<endl;
    DBG(ans);

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
