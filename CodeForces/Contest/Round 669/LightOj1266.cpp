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

    vector<vector<LL>>BIT;
    int R,C;

    Fenwick2D (int r,int c) : BIT(r+1,vector<LL>(c+1,0)) , R(r) , C(c) {}
    ~Fenwick2D()
    {
        BIT.clear();
    }

    inline int LSB(int x) {return x&(-x);} /// find the number with first bit set

    /// POINT update : adds val to index (x,y)
    void add(int x,int y,LL val)
    {
        for(int i = x ; i<=R ; i += LSB(i))
            for(int j = y ; j<=C ; j += LSB(j))
                BIT[i][j] += val;
    }

    /// prefix sum of [(1,1) , (x,y)] square
    LL pref(int x,int y)
    {
        LL sum = 0;

        for(int i = x ; i>0 ; i -= LSB(i))
            for(int j = y ; j>0 ; j -= LSB(j))
            sum += BIT[i][j];

        return sum;
    }

    /// sum of [(xl,yl) , (xh,yh)] square
    LL sum(int xl,int yl,int xh,int yh)
    {
        LL v1 = pref(xh, yh);
        LL v2 = pref(xh, yl-1);
        LL v3 = pref(xl-1, yh);
        LL v4 = pref(xl-1, yl-1);
        return v1 - v2 - v3 + v4;
    }

    void debug()
    {
        cout<<"Prefix Sum Array :\n";
        for(int i=1; i<=R; i++)
        {
            for(int j=1; j<=C; j++)
                cout<<pref(i,j)<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
};

int main()
{
    // optimizeIO();

//    READ;
//    WRITE;

    int tc;
    scanf("%d",&tc);

    int cs = 0;

    while(tc--)
    {
        printf("Case %d:\n", ++cs);

        int n = 1005;
        vector<vector<int>>v(n,vector<int>(n));
        Fenwick2D f(n,n);

        int q;
        scanf("%d",&q);

        while(q--)
        {
            int type;
            scanf("%d",&type);

            if(type==0)
            {
                int x,y;
                scanf("%d %d",&x,&y);

                x++,y++;

                if(v[x][y]==0)
                {
                    v[x][y] = 1;
                    f.add(x,y,1);
                }
            }
            else
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

                x1++,y1++,x2++,y2++;

                int ans = f.sum(x1,y1,x2,y2);
                printf("%d\n", ans);
                // DBG(ans);
            }
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
