/**
 * Logic:
 * Create inverted index type stuff wherein all the numbers with similar digits are
 * grouped together.
 * Eg:
 *
 * consider numbers : 3,33,4,42,24,244,44
 * Numbers that will be grouped together are
 * 1 -> 3,33
 * 2 -> 4,44
 * 3 -> 24,42,244
 *
 * Group 2 and group3 will totally contribute 6 pairs
 * Group 1 individually will contribute 1 pair	(1)
 * Group 2 individually will contribute 1 pair	(1)
 * Group 3 individually will contribute 3 pairs (2+1)
 *
 * Total pairs = 6 + 1 + 1 + 3 = 11
 */
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

#define int long long 

int32_t main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<string>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int> mask((1<<10) + 10,0);

    for(string s:v)
    {
        int m = 0;
        for(char ch:s)
        {
            int c = ch - '0';
            m |= (1<<c);
        }

        mask[m]++;
    }

    int ans = 0;

    for(int i=0;i<(1<<10);i++)
    {
        int cnt = mask[i];
        ans += (cnt*(cnt-1))/2;
    }

    for(int i=0;i<(1<<10);i++)
    {
        for(int j=i+1;j<(1<<10);j++)
        {
            if(i&j) ans += mask[i]*mask[j];
        }
    }

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


