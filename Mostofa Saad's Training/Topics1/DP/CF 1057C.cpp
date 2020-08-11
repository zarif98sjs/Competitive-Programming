
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

int n;
vector<int>num;
vector<int>col;
string c;

int dp[55][5][55][2005];

const int INF = 1e9;

int solve(int pos,int prev_c,int prev_num,int k)
{
    if(k<=0)
        return 0;

    if(pos<0 || pos==n)
        return INF;

    cout<<"->"<<pos<<" "<<prev_c<<" "<<prev_num<<" "<<k<<endl;

    int &ret = dp[pos][prev_c][prev_num][k];
    if(ret != -1) return ret;

    cout<<pos<<" "<<prev_c<<" "<<prev_num<<" "<<k<<endl;

    ret = INF;

    if(col[pos] != prev_c && num[pos]>prev_num)
    {
        ret = min(ret,1 + solve(pos+1,col[pos],num[pos],k-num[pos]));
        ret = min(ret,1 + solve(pos-1,col[pos],num[pos],k-num[pos]));
    }

    ret = min(ret,1 + solve(pos+1,prev_c,prev_num,k));
    ret = min(ret,1 + solve(pos-1,prev_c,prev_num,k));

    return ret;
}

int main()
{
    optimizeIO();

    int st,k;
    cin>>n>>st>>k;

    num = vector<int>(n);

    for(int i=0; i<n; i++)
        cin>>num[i];

    cin>>c;

    for(char ch:c)
    {
        if(ch=='R') col.push_back(0);
        if(ch=='G') col.push_back(1);
        if(ch=='B') col.push_back(2);
    }

    memset(dp,-1,sizeof dp);
    int ans = solve(st-1,3,0,k);

    if(ans>=INF) cout<<-1<<endl;
    else cout<<ans-1<<endl;

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


