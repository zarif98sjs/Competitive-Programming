
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

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,k,z;
        cin>>n>>k>>z;

        int l = z;
        int r = k;

        vector<int>v(n);

        for(int i=0;i<n;i++)
            cin>>v[i];

        int mx_sum = 0;

        for(int i=0;i<=r;i++)
            mx_sum += v[i];

        DBG(mx_sum);

        int mx = 0 , mx_id = -1;

        for(int i=0;i<r;i++)
        {
            if(v[i]+v[i+1] > mx)
            {
                mx = v[i] + v[i+1];
                mx_id = i;
            }
        }

        int s = 0;
        int al_r = mx_id + 1;

        int go = r - 2*l;

        for(int i=0;i<=go;i++)
        {
            s += v[i];
        }

        DBG(s);
        DBG(mx_id);

        int rem = k - al_r;

        int rem_l

        int one = v[mx_id];
        int other = v[mx_id+1];

        DBG(one);
        DBG(other);

        for(int i=0;i<rem;i++)
        {
            if(i%2==0) s += one;
            else s += other;
        }

        DBG(s);

        mx_sum = max(mx_sum,s);

        cout<<mx_sum<<endl;
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


