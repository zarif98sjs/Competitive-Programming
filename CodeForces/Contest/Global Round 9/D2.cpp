
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
        vector<int>pos(n+1);

        for(int i=0;i<n;i++)
            cin>>v[i] , pos[v[i]] = i;

        int cur = 0;

        vector<int>ans;

        int mex = 0;

        for(int cur=0;cur<n;cur++)
        {
            set<int>s;

            for(int x:v) s.insert(x);


            mex = 0;
            while(s.find(mex)!=s.end())
                mex++;

//            DBG(mex);

            if(mex==n)
                break;

            v[mex] = mex;
            ans.push_back(mex);
//            DBG(v);

        }

        for(int i=0;i<n;i++)
            pos[v[i]] = i;

        for(int cur=0;cur<n;cur++)
        {
            mex = 0;
            set<int>s;

            for(int x:v) s.insert(x);
            while(s.find(mex)!=s.end())
                mex++;

            v[pos[cur]] = mex;
            ans.push_back(pos[cur]);
            v[cur] = cur;
            ans.push_back(cur);
        }

        cout<<ans.size()<<endl;

        for(int x:ans)
            cout<<x+1<<" ";
        cout<<endl;
//        cout<<endl;

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



