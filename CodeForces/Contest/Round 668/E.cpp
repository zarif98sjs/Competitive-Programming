
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

const int nmax = 3e5+7;

/** BIT / FENWICK TREE **/
/*** 1 based indexing ***/

LL BIT[nmax];
void update(int index,LL val,int len) /** POINT update , adds to the current value **/
{
    while(index<=len)
    {
        BIT[index] += val;
        index += index&(-index);
    }
}

LL query(int index) /** RANGE query **/
{
    LL sum=0;
    while(index>0)
    {
        sum += BIT[index];
        index -= index&(-index);
    }
    return sum;
}


int upperBound_BIT(int lo,int hi,int key) /** O( (logN)^2 ) **/
{
    while(lo!=hi)
    {
        int mid = lo + (hi-lo)/2;

        if(query(mid)<=key) lo = mid + 1;
        else hi = mid;
    }

    return lo-1;
}

vector<PII>queryV[nmax];

int main()
{
    optimizeIO();

    int n,q;
    cin>>n>>q;

    vector<int>v(n+1),ans(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i] , v[i] = i-v[i];

    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;

        int l = x+1;
        int r = n-y;

        queryV[r].emplace_back(l,i);
    }

    for(int r=1;r<=n;r++)
    {
        int target = v[r];

        int idx = upperBound_BIT(1,n,target);

        if(target>=0 && idx>=0)
        {
            update(1,1,n);
            update(idx+1,-1,n);
        }

        for(auto el:queryV[r]) ans[el.S] = query(el.F);
    }

    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    for(int i=1;i<=q;i++) DBG(ans[i]);

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
