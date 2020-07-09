
/**

p1 p2 ... pn

if there are n values the way we can choose 2 elements is nC2 . nC2 number path occurs some number of times through all n! routes.
Now , fix 2 element . We can do that in n-1 ways and others can be permuted (n-2)! .
So , |ai-aj| * n-1 * (n-2)!

**/

/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

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

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<LL>v(n);

    LL s1 = 0 , s2 = 0;
    for(int i=0;i<n;i++)
        cin>>v[i] , s1+=v[i];

    sort(ALL(v));

    LL t = 0;
    for(int i=0;i<n;i++)
    {
        s2 += (i*v[i] - t);
        t += v[i];
    }

    LL up = s1+2*s2;
    LL down = n;
    LL g = __gcd(up,down);

    up /= g;
    down /= g;

    cout<<up<<" "<<down<<endl;

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


