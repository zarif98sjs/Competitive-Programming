
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

#define double long double

void solveTC()
{
    int n,l;
    cin>>n>>l;

    vector<int>v(n+2);
    v[0] = 0;
    for(int i=1;i<=n;i++) cin>>v[i];
    v[n+1] = l;

    vector<double>ts(n+2,0),te(n+2,0);
    vector<double>speeds(n+2,1),speede(n+2,1);

    double cur = 1;
    for(int i=1;i<=n+1;i++)
    {
        ts[i] = ts[i-1] + (v[i]-v[i-1])/cur;
        cur+=1;
        speeds[i] = cur;
    }

    cur = 1;
    for(int i=n;i>=0;i--)
    {
        te[i] = te[i+1] + (v[i+1]-v[i])/cur;
        cur+=1;
        speede[i] = cur;
    }

    vector<int>who(n+2);

    for(int i=0;i<=n+1;i++)
    {
        if(ts[i]<te[i]) who[i] = 1;
        else who[i] = 2;
    }

    int mid = -1;

    for(int i=0;i<=n;i++)
    {
        if(who[i]!=who[i+1])
            mid = i;
    }

    DBG(who);
    DBG(mid);

    DBG(ts);
    DBG(te);

    double ans = 0;

    double st = 0;
    double et = 0;

    for(int i=0;i<=n+1;i++)
    {
        if(who[i]==1) st = max(st,ts[i]);
        if(who[i]==2) et = max(et,te[i]);
    }

    DBG(st);
    DBG(et);

    ans = max(st,et);

    double adv = 0;

    DBG(speeds);
    DBG(speede);

    double td = ts[mid] - te[mid+1];
    DBG(td);
    if(td>0) adv = speede[mid+1] * td;
    else adv = speeds[mid] * td * -1.0;

    double left = v[mid] , right = v[mid+1];

    if(td>0) right -= adv;
    else left += adv;

    DBG(right);
    DBG(left);

    double midt = (right-left)/(speede[mid+1]+speeds[mid]);
//    DBG(v[mid+1]);
//    DBG(speeds);
//    DBG(speede);
//    DBG(speede[mid+1]);
//    DBG(speeds[mid]);
    DBG(midt);

    ans += midt;

    cout<<setprecision(10)<<ans<<endl;
    DBG(ans);

}

int32_t main()
{
    optimizeIO();

    int tc;
    cin>>tc;

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
