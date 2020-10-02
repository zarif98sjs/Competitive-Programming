
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

void solveTC()
{
    int n,m;
    cin>>n>>m;

    vector<PII>rob(n),light(m);

    for(int i=0;i<n;i++) cin>>rob[i].F>>rob[i].S;
    for(int i=0;i<m;i++) cin>>light[i].F>>light[i].S;

    int mx = 1e6 + 10;

    vector<int>up(mx);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int dx = light[j].F - rob[i].F;
            int dy = light[j].S - rob[i].S;

            if(dx>=0) up[dx] = max(up[dx],dy+1);
        }
    }


    int ans = INT_MAX;

    int max_up_must_till_now = 0;

    for(int dx=mx;dx>=0;dx--)
    {
        /// if i want to escape by making a move dx,dy we have to ensure that all the robbers to the right has already escaped
        /// thus this sweep line from left to right
        max_up_must_till_now = max(max_up_must_till_now,up[dx]);
        ans = min(ans,dx+max_up_must_till_now);
    }

    cout<<ans<<endl;
    DBG(ans);

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
