
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

int dpLCS[505][505];

int LCS(int i,int j,vector<int>&a,vector<int>&b)
{
    int n1 = a.size() , n2 = b.size();

    if(i==n1 || j==n2) return 0;

    int &ret = dpLCS[i][j];
    if(~ret) return ret;

    if(a[i]==b[j]) ret = 1 + LCS(i+1,j+1,a,b);
    else ret = max(LCS(i,j+1,a,b),LCS(i+1,j,a,b));

    return ret;
}

void solveLCS(int i,int j,vector<int>&a,vector<int>&b,vector<int>&vLCS)
{
    int n1 = a.size() , n2 = b.size();

    if(i==n1 || j==n2) return;

    if(a[i]==b[j])
    {
        vLCS.push_back(a[i]);
        return solveLCS(i+1,j+1,a,b,vLCS);
    }
    else
    {
        int way1 = LCS(i+1,j,a,b) , way2 = LCS(i,j+1,a,b);

        if(way1 > way2) return solveLCS(i+1,j,a,b,vLCS);
        else return solveLCS(i,j+1,a,b,vLCS);
    }
}

vector<int> solveLIS(vector<int>&v)
{
    int n = v.size();

    vector<int>LIS(n,1); /** length of longest increasing sequence ending at i **/
    vector<vector<int>>SEQ(n);  /** longest increasing sequence ending at i **/

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j])
            {
                if(LIS[j]+1 > LIS[i])
                {
                    LIS[i] = LIS[j]+1;
                    SEQ[i] = SEQ[j];
                }
            }
        }
        SEQ[i].push_back(v[i]);
    }

    int lis_len = *max_element(ALL(LIS));

    int mx = 0;
    vector<int>MX;

    for(int i=0; i<n; i++)
    {
        if(LIS[i]>mx)
        {
            mx = LIS[i];
            MX = SEQ[i];
        }
    }

    return MX;
}

void solve(vector<int>&v1,vector<int>&v2)
{
    vector<int>LIS1 = solveLIS(v1);
    vector<int>LIS2 = solveLIS(v2);

    DBG(LIS1);
    DBG(LIS2);

    memset(dpLCS,-1,sizeof dpLCS);
    LCS(0,0,LIS1,LIS2);
    vector<int>LCIS;
    solveLCS(0,0,LIS1,LIS2,LCIS);

    cout<<LCIS.size()<<endl;
    for(int x:LCIS) cout<<x<<" ";
    cout<<endl;
}


int main()
{
    optimizeIO();
    int n1,n2;
    vector<int>v1,v2;

    cin>>n1;
    v1 = vector<int>(n1);
    for(int i=0;i<n1;i++)
        cin>>v1[i];

    cin>>n2;
    v2 = vector<int>(n2);
    for(int i=0;i<n2;i++)
        cin>>v2[i];

    solve(v1,v2);


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


