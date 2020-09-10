
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
const int INF = 1e9;

string s;
int n;

int dp[nmax][7][7];

int conv(char ch)
{
    if(ch=='R') return 2;
    if(ch=='L') return 1;
}

int pc(int x)
{
    if(x<0) return (x+n)%n;
    return x%n;
}

int st_c(int id,int who)
{
    int state = 0;

    if(s[pc(id-1)]=='R' ) state = 1;
    if(s[pc(id+1)]=='L' ) state = 2;

    if(who==INT_MAX) return state;

    if(pc(who)==pc(id-1) && state==0) state = 1;
    if(pc(who)==pc(id+1) && state==0) state = 2;

    if(pc(who)==pc(id-1) && state==2) state = 3;
    if(pc(who)==pc(id+1) && state==1) state = 3;

    return state;
}

int solve(int pos,int op,int me)
{
    cout<<pos<<" "<<op<<" "<<me<<endl;

    int &ret = dp[pos][op][me];
    if(~ret) return ret;

    ret = INF;

    if(op==0)
    {
        if(me==1)
        {
            ret = min(ret,1 + solve(pc(pos+1),st_c(pos+1,pos),conv('R')));
            ret = min(ret,solve(pc(pos+1),st_c(pos+1,INT_MAX),conv(s[pos+1])));
        }
        if(me==2)
        {
            ret = min(ret,1 + solve(pc(pos-1),st_c(pos-1,pos),conv(s[pos-1])));
            ret = min(ret,solve(pc(pos-1),st_c(pos-1,INT_MAX),conv(s[pos-1])));
        }
    }
    if(op==1)
    {
        if(me==1) ret = min(ret,solve(pc(pos-1),st_c(pos-1,INT_MAX),conv(s[pos-1])));
        if(me==2) ret = min(ret, 1 + solve(pc(pos-1),st_c(pos-1,pos),conv(s[pos-1])));
    }
    if(op==2)
    {
        if(me==2) ret = min(ret, solve(pc(pos+1),st_c(pos+1,INT_MAX),conv(s[pos+1])));
        if(me==1) ret = min(ret, 1 + solve(pc(pos+1),st_c(pos+1,pos),conv(s[pos+1])));
    }
    if(op==3)
    {
        if(me==1)
        {
            ret = min(ret,solve(pc(pos+1),st_c(pos+1,INT_MAX),conv(s[pos+1])));
            ret = min(ret,1 + solve(pc(pos+1),st_c(pos+1,pos),conv(s[pos+1])));
        }
        if(me==2)
        {
            ret = min(ret,1 + solve(pc(pos-1),st_c(pos-1,pos),conv(s[pos-1])));
            ret = min(ret,solve(pc(pos-1),st_c(pos-1,INT_MAX),conv(s[pos-1])));
        }
    }

    return ret;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>n>>s;

        memset(dp,-1,sizeof dp);
        int ans;
        ans = solve(0,st_c(pc(0),INT_MAX),conv(s[0]));
        DBG(ans);
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


