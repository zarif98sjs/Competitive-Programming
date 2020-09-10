
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

string g[10];

int main()
{
    optimizeIO();

    int r,c,k;
    cin>>r>>c>>k;

    for(int i=0;i<r;i++)
        cin>>g[i];

    int ans = 0;

    for(int i=0;i<(1<<r);i++)
    {
        for(int j=0;j<(1<<c);j++)
        {

            char gg[10][10];

            for(int ii=0;ii<r;ii++)
                for(int jj=0;jj<c;jj++)
                    gg[ii][jj] = g[ii][jj];

            for(int ii=0;ii<r;ii++)
            {
                for(int jj=0;jj<c;jj++)
                {
                    if(i&(1<<ii))
                        gg[ii][jj] = '.';
                    if(j&(1<<jj))
                        gg[ii][jj] = '.';
                }
            }

            int cnt = 0;

            for(int ii=0;ii<r;ii++)
                for(int jj=0;jj<c;jj++)
                    if(gg[ii][jj]=='#')
                        cnt++;

            if(cnt==k)
                ans++;
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


