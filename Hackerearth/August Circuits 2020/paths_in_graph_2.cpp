
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

#define endl "\n"

template <class T>
T po(T b, T p) /// Faster than recursive one
{
    T res = 1, x = b;
    while ( p )
    {
        if ( p & 1 )
            res = ( res * x );
        x = ( x * x );
        p >>= 1;
    }
    return res;
}

int cur = 2;
vector<PII>edges;
vector<int>last;

void generate(int layer,int num)
{
    if(layer==0)
    {
        edges.push_back({1,cur});
        last.push_back(cur);
        cur++;
        return;
    }

    int upd = 0;

    for(int j=0; j<num; j++)
        edges.push_back({1,cur+j}), upd = max(upd,cur+j);

    if(layer==1)
    {
        for(int j=0; j<num; j++)
            last.push_back(cur+j);
    }

    for(int i=2; i<=layer; i++)
    {
        int next = cur + num;
        DBG(next);

        for(int j=0; j<num; j++)
        {
            edges.push_back({cur+j,next});
        }

        cur = next;
        upd = max(upd,cur);

        for(int j=1; j<=num; j++)
        {
            edges.push_back({cur,cur+j});
            upd = max(upd,cur+j);
        }

        if(i==layer)
        {
            for(int j=1; j<=num; j++)
                last.push_back(cur+j);
        }

        cur++;
    }

    DBG(cur);
    cur = upd+1;
}

void convert10tob(int N, int b)
{
    if (N == 0)
        return;

    int x = N % b;

    N /= b;

    if (x < 0)
        N += 1;

    convert10tob(N, b);

    cout<< (x<0 ? x + (b * -1) : x);
    return;

}

int main()
{
    LL k;
    cin>>k;

    bitset<40>mask(k);

    for(int i=0; i<=40; i++)
    {
        if(mask[i]==1)
        {
            generate(i,2);
        }
    }

    int nth = cur;

    for(int x:last)
        edges.push_back({x,nth});

    cout<<nth<<" "<<edges.size()<<endl;

    for(auto p :edges)
        cout<<p.F<<" "<<p.S<<endl;

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


