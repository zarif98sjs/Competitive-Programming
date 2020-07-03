
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

const int nmax = 1e3+7;
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

string ara[nmax];
string nara[nmax];
vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,1,0,-1};

bool isOk(int i,int j,int r,int c)
{
    if(i>=0 && i<r && j>=0 && j<c)
        return true;
    return false;
}

int main()
{
    optimizeIO();

    int r,c,q;
    cin>>r>>c>>q;

    for(int i=0;i<r;i++)
        cin>>ara[i];

    while(1)
    {
        int x;
        cin>>x;

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                bool ok = false;

                for(int k=0;k<4;k++)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(isOk(ni,nj,r,c))
                    {
                        if(ara[ni][nj]==ara[i][j])
                            ok = true;
                    }
                }

                if(ok)
                {
                    if(ara[i][j]=='1') nara[i][j] = '0';
                    if(ara[i][j]=='0') nara[i][j] = '1';
                }
                else nara[i][j] = ara[i][j];
            }
        }

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout<<nara[i][j];
            cout<<endl;
        }

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                ara[i][j] = nara[i][j];

    }


    return 0;
}

/**

4 4 10
0101
0101
0101
0101

4 4 10
0101
1010
1010
0101

5 5 10
10101
11111
10101
11101
10101

5 5 3
01011
10110
01101
11010
10101

4 4 10
1010
0101
1010
0101

5 5 10
00000
01000
00000
00010
00000

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


