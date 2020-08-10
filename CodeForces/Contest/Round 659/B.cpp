
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

struct Data
{
    int pos,tide;
    bool down;

    Data()
    {
        pos = tide = 0;
        down = false;
    }

    Data(int pos,int tide,bool down)
    {
        this->pos = pos;
        this->tide = tide;
        this->down = down;
    }
};

bool operator < (const Data &A,const Data &B)
{
    if(A.pos==B.pos)
    {
        if(A.tide==B.tide)
            return A.down<B.down;

        return A.tide<B.tide;
    }

    return A.pos < B.pos;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,k,l;
        cin>>n>>k>>l;

        vector<int>d(n+2,-k);

        for(int i=1 ;i<=n; i++)
            cin>>d[i];

        set<Data>s;

        function<bool(int,int,bool)>solve = [&] (int pos,int tide,bool down)
        {
            if(pos>n)
                return true;

            auto t  = Data(pos,tide,down);

            if(s.find(t)!=s.end())
                return false;

            s.insert(t);

            tide += down ? -1 : +1;

            if(tide==k) down = true;
            if(tide==0) down = false;

            if(d[pos]+tide<=l && solve(pos,tide,down)) return true;
            if(d[pos+1]+tide<=l && solve(pos+1,tide,down)) return true;

            return false;
        };

        bool ok = solve(0,0,false);

        if(ok)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
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


