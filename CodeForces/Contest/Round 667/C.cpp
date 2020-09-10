
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

vector<int> divisors(int num)
{
    vector<int>d;

    for(int i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            d.push_back(i);

            if(i != num/i) d.push_back(num/i);
        }
    }

    sort(ALL(d));

    return d;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,a,b;
        cin>>n>>a>>b;

        vector<int> div = divisors(b-a);

        int mx = INT_MAX;
        PII ans = {-1,-1};

        DBG(div);

        for(int d:div)
        {
            int mid = 1 + (b-a)/d;
            int rem = n - mid;

            if(rem<0) continue;

            int leftmostval,left;
            int rmostval = b ,r;

            leftmostval = a - d*min(rem,(a/d));
            if(leftmostval == 0) leftmostval += d;

            if(rem > 0)
            {
                left = (a - leftmostval)/ d;
                rem -= left;
            }
            if(rem > 0)
            {
                rmostval = b + d*rem;
            }

            DBG(leftmostval);
            DBG(rmostval);

            if(rmostval < mx)
            {
                mx = rmostval;
                ans = {leftmostval,d};
            }
        }


        int el = ans.F;
        for(int i=1;i<=n;i++)
        {
            cout<<el<<" ";
            el += ans.S;
        }

        cout<<endl;
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
