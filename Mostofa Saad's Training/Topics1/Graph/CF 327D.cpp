
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second
#define endl "\n"

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

const int nmax = 505+7;

string g[nmax];
bool vis[nmax][nmax];

vector<int>dx = {-1,0,1,0};
vector<int>dy = {0,1,0,-1};

int r,c;

bool ok(int x,int y)
{
    if(x>=0 && x<r && y>=0 && y<c && g[x][y]=='.')
        return true;
    return false;
}

struct Data
{
    string type;
    int x,y;

    Data() {}
    Data(string type,int x,int y) : type(type) , x(x) ,y(y) {}
};

vector<Data>v;

void dfs(int x,int y)
{
    vis[x][y] = true;

    v.push_back({"B",x,y});

    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(ok(nx,ny) && !vis[nx][ny])
            dfs(nx,ny);
    }

    v.push_back({"D",x,y});
    v.push_back({"R",x,y});
}

int main()
{
    optimizeIO();

    cin>>r>>c;

    for(int i=0;i<r;i++)
        cin>>g[i];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(ok(i,j) && !vis[i][j])
            {
                dfs(i,j);
                v.pop_back();
                v.pop_back();
            }
        }
    }

    cout<<v.size()<<endl;
    for(auto d:v)
        cout<<d.type<<" "<<d.x+1<<" "<<d.y+1<<endl;

    return 0;
}

/**
3 3
...
...
...
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


