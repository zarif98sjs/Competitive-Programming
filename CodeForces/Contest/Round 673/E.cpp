
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

//const int nmax = 2e5+7;

struct Trie
{
    vector<vector<int>>next;
    vector<vector<int>>ind;
    vector<vector<LL>>dp;
    int node_num = 0;

    Trie(int num_of_nodes)
    {
        next = vector<vector<int>>(num_of_nodes,vector<int>(2,-1)); /// 0,1
        ind = vector<vector<int>>(num_of_nodes); /// indices
        dp = vector<vector<LL>>(33,vector<LL>(2,0));
    }

    void insert(int x,int pos)
    {
        int cur = 0;

        for(int i=30;i>=0;i--)
        {
            int bit = ( (x>>i) & 1 );

            if(next[cur][bit]==-1) next[cur][bit] = ++node_num;

            cur = next[cur][bit];
            ind[cur].push_back(pos);
        }
    }

    void go(int u,int bit = 30)
    {
        int l = next[u][0] , r = next[u][1];

        if(l != -1) go(l,bit-1);
        if(r != -1) go(r,bit-1);

        if(l==-1 || r==-1) return;

        LL inv_xor_0 = 0;
        int ptr = 0;

        for(auto idx:ind[l])
        {
            while(ptr < (int)ind[r].size() && ind[r][ptr] < idx) ptr++;
            inv_xor_0 += ptr;
        }

        LL inv_xor_1 = 0;
        ptr = 0;

        for(auto idx:ind[r])
        {
            while(ptr < (int)ind[l].size() && ind[l][ptr] < idx) ptr++;
            inv_xor_1 += ptr;
        }

        dp[bit][0] += inv_xor_0;
        dp[bit][1] += inv_xor_1;
    }

    void solve()
    {
        int XOR = 0;
        LL inv = 0;

        for(int i=0;i<=30;i++)
        {
            inv += min(dp[i][0],dp[i][1]);

            if(dp[i][1] < dp[i][0])
                XOR |= (1<<i);
        }

        cout<<inv<<" "<<XOR<<endl;
    }
};

void solveTC()
{
    int n;
    cin>>n;

//    int mx = 3e5+7;
    Trie t(33*n);

    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i] , t.insert(v[i],i);

    t.go(0);
    t.solve();

}

int32_t main()
{
    optimizeIO();

    int tc = 1;
//    cin>>tc;

    while(tc--)
    {
        solveTC();
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
