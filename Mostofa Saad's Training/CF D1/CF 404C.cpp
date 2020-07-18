
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

vector<int>d[nmax];

int main()
{
    optimizeIO();

    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;

        d[x].push_back(i);
    }

    if(d[0].size()>1)
    {
        cout<<-1<<endl;
        return 0;
    }

    vector<PII>edge;

    for(int i=0;i<n;i++)
    {
        int cur = 0;

        for(int x:d[i])
        {
            int cnt;

            if(i==0) cnt = k;
            else cnt = k-1;

            for(int j=0;j<cnt && cur<d[i+1].size();j++)
            {
                PII p = {x,d[i+1][cur]};
                edge.push_back(p) , cur++;
//                DBG(p);
            }
        }

        if(cur!=(int)d[i+1].size())
        {
            cout<<-1<<endl;
            return 0;
        }
    }

    cout<<(int)edge.size()<<endl;

    for(auto x:edge)
        cout<<x.F<<" "<<x.S<<endl;

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


