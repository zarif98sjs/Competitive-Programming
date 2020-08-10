
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

const int nmax = 1e5+7;
const int INF = 1e8;

vector<int>v;
int n,k,z;

int dp[nmax][10][10];

int solve(int pos,int mv,int l,bool wasLeft)
{
//    if(l<0) return 0;
    if(mv>k) return 0;

    int &ret = dp[mv][l][wasLeft];

    if(ret!=-1) return ret;

    ret = solve(pos+1,mv+1,l,false) + v[pos+1];

    if(pos>1 && wasLeft==false && l>0) ret = max(ret,solve(pos-1,mv+1,l-1,true) + v[pos-1]);

    return ret;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>n>>k>>z;

        int l = z;
        int r = k;

        for(int i=0; i<=r; i++)
            for(int j=0; j<=l; j++)
                for(int k=0; k<=2; k++)
                    dp[i][j][k] = -1;

        v = vector<int>(n+1);

        for(int i=1; i<=n; i++)
            cin>>v[i];

        cout<<solve(0,0,l,false)<<endl;

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


