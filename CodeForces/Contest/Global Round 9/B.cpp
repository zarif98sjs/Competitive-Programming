
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

const int nmax = 1e3+7;

int ara[nmax][nmax];
int ans[nmax][nmax];
int done[nmax][nmax];

vector<int>dx = {-1,0,1,0};
vector<int>dy = {0,1,0,-1};

bool isOk(int i,int j,int r,int c)
{
    if(i>=1 && i<=r && j>=1 && j<=c)
        return true;
    return false;
}

int neigh(int x,int y,int r,int c)
{
    int cnt  = 0;

    for(int i=0; i<4; i++)
    {
        int nx = x+ dx[i];
        int ny = y+ dy[i];

        if(isOk(nx,ny,r,c))
            cnt++;
    }
    return cnt;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int r,c;
        cin>>r>>c;

        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
                cin>>ara[i][j], ans[i][j] = ara[i][j], done[i][j] = ara[i][j];

        bool ok = true;

        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                if(ara[i][j]>neigh(i,j,r,c))
                    ok = false;
            }
        }

        if(!ok)
            cout<<"No"<<endl;
        else
        {
            for(int i=1; i<=r; i++)
            {
                for(int j=1; j<=c; j++)
                {
                    ans[i][j] = neigh(i,j,r,c);
                }
            }
            cout<<"Yes"<<endl;
            for(int i=1; i<=r; i++)
            {
                for(int j=1; j<=c; j++)
                    cout<<ans[i][j]<<" ";
                cout<<endl;
            }

        }

    }

    return 0;
}

/**
3 3
0 1 0
0 3 2
0 0 1
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


