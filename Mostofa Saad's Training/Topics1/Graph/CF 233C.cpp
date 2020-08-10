
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

int g[105][105];

int main()
{
    optimizeIO();

    int K;
    cin>>K;

    g[1][2] = g[2][1] = 1;

    int N;

    for(int i=3;i<=100;i++)
    {
        for(int j=1;j<i;j++)
        {
            int cnt = 0;

            for(int k=1;k<j;k++)
            {
                if(g[i][k]==1 && g[k][j])
                    cnt++;
            }

            if(cnt<=K)
            {
                K -= cnt;
                g[i][j] = g[j][i] = 1;
            }

            if(K==0)
            {
                N = i;
                break;
            }

        }

        if(K==0)
            break;
    }

    cout<<N<<endl;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            cout<<g[i][j];
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


