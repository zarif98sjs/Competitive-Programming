
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

int MEX(const vector<int> &v)
{
    set<int>s;

    for(int x:v) s.insert(x);

    int mex = 0;

    while(s.find(mex)!=s.end())
        mex++;

    return mex;
}

bool ok(const vector<int> &v)
{
    for(int i=1;i<v.size();i++)
        if(v[i]<=v[i-1])
            return false;
    return true;
}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        vector<int>v(n);

        for(int i=0;i<n;i++)
            cin>>v[i];

        vector<int>ans;

        while(1)
        {
            if(ok(v))
                break;

            int mex = MEX(v);

            if(mex==n)
            {
                for(int i=0;i<n;i++)
                {
                    if(v[i]!=i)
                    {
                        v[i] = mex;
                        ans.push_back(i);
                        break;
                    }
                }
            }
            else
            {
                v[mex] = mex;
                ans.push_back(mex);
            }
        }

        cout<<ans.size()<<endl;
        for(int x:ans)
            cout<<x+1<<" ";
        cout<<endl;

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


