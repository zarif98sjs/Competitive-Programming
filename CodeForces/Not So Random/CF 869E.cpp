
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
#define endl "\n"
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

struct Fenwick2D{

    vector<vector<PLL>>BIT; /// adding an extra parameter : hash value , let that be the sum
    int R,C;

    Fenwick2D (int r,int c) : BIT(r+1,vector<PLL>(c+1,{0,0})) , R(r) , C(c) {}

    inline int LSB(int x) {return x&(-x);} /// find the number with first bit set

    /// POINT update : adds {val,hash} to index (x,y)
    void add(int x,int y,PLL inc)
    {
        for(int i = x ; i<=R ; i += LSB(i))
            for(int j = y ; j<=C ; j += LSB(j))
                BIT[i][j].F += inc.F , BIT[i][j].S += inc.S;
    }

    /// prefix sum of [(1,1) , (x,y)] square
    PLL pref(int x,int y)
    {
        PLL sum = {0,0};

        for(int i = x ; i>0 ; i -= LSB(i))
            for(int j = y ; j>0 ; j -= LSB(j))
                sum.F += BIT[i][j].F , sum.S += BIT[i][j].S;

        return sum;
    }

    /// update [(xl,yl) , (xh,yh)] square with {val,hash}
    void update(int xl,int yl,int xh,int yh,PLL inc)
    {
        PLL dec = {-inc.F,-inc.S}; /// reverse operation
        add(xl,yl,inc);
        add(xl,yh+1,dec);
        add(xh+1,yl,dec);
        add(xh+1,yh+1,inc);
    }

    void debug()
    {
        cout<<"Prefix Sum Array :\n";
        for(int i=1; i<=R; i++)
        {
            for(int j=1; j<=C; j++)
                cout<<pref(i,j).F<<" ";
            cout<<endl;
        }
    }
};

map< pair<PII,PII> , PLL > MAP;

int main()
{
    optimizeIO();

    int r,c,q;
    cin>>r>>c>>q;

    srand(20001206);

    Fenwick2D f(r,c);

    PLL block,not_block;

    for(int i=1;i<=q;i++)
    {
        /// f.debug();

        int type;
        cin>>type;

        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        if(type==1)
        {
            block.F = rand() , block.S = rand();

            f.update(x1,y1,x2,y2,block);

            MAP[{ {x1,y1},{x2,y2} }] = block;
        }
        else if(type==2)
        {
            block = MAP[{ {x1,y1},{x2,y2} }];
            not_block = {-block.F,-block.S};

            f.update(x1,y1,x2,y2,not_block);

            MAP[{ {x1,y1},{x2,y2} }] = {0,0};
        }
        else
        {
            PLL pos1 = f.pref(x1,y1);
            PLL pos2 = f.pref(x2,y2);

            if(pos1 != pos2 ) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
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
    for(T i:v)
    {
        os<<i<<" " ;
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
