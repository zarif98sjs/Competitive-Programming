
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

const int nmax = 80+7;

int main()
{
    optimizeIO();

    int tc = 1 ;

    while(tc--)
    {
        int n;
        cin>>n;

        vector<LL>v(n+10);

        for(int i=1; i<=n; i++)
            cin>>v[i];

        v[n+1] = INT_MIN;

        int p1 = -1, p2 = 1;
        LL cur  = 1000;

        while(1)
        {
            if(p1>=n || p2>=n)
                break;

            bool hoise = false;

            for(int i=p2+1; i<=n; i++)
                if(v[i]>v[i-1])
                {
                    p1 = i-1;
                    hoise = true;
                    break;
                }

            if(!hoise)
                break;

            for(int i=p1+1; i<=n+1; i++)
                if(v[i]<v[i-1])
                {
                    p2 = i-1;
                    break;
                }

            LL buy = cur/v[p1];

            LL gain = (v[p2]-v[p1]) * buy;

            cur += gain;

            DBG(p1);
            DBG(p2);
            DBG(cur);

        }

        cout<<cur<<endl;



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


