
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TIn>using indexed_set = tree<TIn, null_type, less<TIn>,rb_tree_tag, tree_order_statistics_node_update>;

/**

PBDS
-------------------------------------------------
1) insert(value)
2) erase(value)
3) order_of_key(value) // 0 based indexing
4) *find_by_order(position) // 0 based indexing

**/

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
const LL LINF = 1e17;

template <class T>
string to_str(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

//bool cmp(const PII &A,const PII &B)
//{
//
//}

vector<int>dx = {-1,0,1,0};
vector<int>dy = {0,1,0,-1};

bool isOk(int i,int j,int r,int c)
{
    if(i>=0 && i<r && j>=0 && j<c)
        return true;
    return false;
}

//string ara[55];
char ara[55][55];

bool vis[55][55];

void dfs(int i,int j,int r,int c)
{
    vis[i][j] = true;

    for(int k=0; k<4; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(isOk(ni,nj,r,c))
        {
            if(vis[ni][nj])
                continue;

            if(ara[ni][nj]!='#')
                dfs(ni,nj,r,c);
        }
    }
}

int main()
{
    //freopen("out.txt","w",stdout);

    //optimizeIO();

    int tc;
    scanf("%d",&tc);

    while(tc--)
    {
        int r, c;
        scanf("%d %d",&r,&c);

        for(int i=0; i<r; i++)
            for(int j=0;j<c;j++)
                scanf(" %c",&ara[i][j]);

        vector<PII>vg,vb;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(ara[i][j]=='B')
                {
                    vb.push_back({i,j});

                    for(int k=0; k<4; k++)
                    {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if(isOk(ni,nj,r,c))
                        {
                            if(ara[ni][nj]!='G' && ara[ni][nj]!='B')
                                ara[ni][nj] = '#';
                        }
                    }
                }

                if(ara[i][j]=='G')
                    vg.push_back({i,j});
            }
        }

        memset(vis,0,sizeof vis);
        dfs(r-1,c-1,r,c);

        bool ok = true;

        for(auto x:vg)
        {
            if(vis[x.F][x.S]==false)
            {
                ok = false;
                cout<<"asdas"<<endl;
                break;
            }
        }

        for(auto x:vb)
        {
            if(vis[x.F][x.S]==true)
            {
                ok = false;
                 cout<<"asd"<<endl;
                break;
            }
        }

        if(ok)
            printf("Yes\n");
        else
           printf("No\n");
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
