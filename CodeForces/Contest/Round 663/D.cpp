
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
    int n,m;
    cin>>n>>m;

    int r = n, c = m;

    vector<vector<char>> v(r,vector<char>(c));

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>v[i][j];

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<v[i][j];
        cout<<endl;
    }


    if(n>3 || m>3)
    {
        cout<<-1<<endl;
        return 0;
    }


    int ans = 0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            int one = 0;
            bool ok = false;

            if(v[i][j]=='1')
                one++;
            if(j+1<c && v[i][j+1]=='1')
                one++;
            if(i+1<r && v[i+1][j]=='1')
                one++;
            if(i+1<r && j+1<c && v[i+1][j+1]=='1')
                one++;

            if(i+1<r && j+1<c && one%2==0)
            {
                if(v[i+1][j+1]=='1') v[i+1][j+1] = '0';
                else if(v[i+1][j+1]=='0') v[i+1][j+1] = '1';
                ans++;
            }
        }
    }

    cout<<ans<<endl;


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


