
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

struct Node
{
    int F,S;

    Node(int F,int S)
    {
        this->F = F;
        this->S = S;
    }
};

bool operator<(const Node &A,const Node &B)
{
    if(A.F==B.F)
        return A.S<B.S;

    return A.F>B.F;
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<int>v(n+1);

    for(int i=0;i<n;i++)
        cin>>v[i];
    v[n] = INT_MAX;

    vector<PII>ara;

    int len = 1;
    for(int i=1;i<=n;i++)
    {
        if(v[i]!=v[i-1])
        {
            ara.push_back({v[i-1],len});
            len = 1;
        }
        else
            len++;
    }

    n = ara.size();

    vector<int>l(n+1),r(n+1);

    for(int i=0;i<=n;i++) l[i] = i-1;
    for(int i=0;i<n;i++) r[i] = i+1;

    set<Node>s;

    for(int i=0;i<n;i++)
        s.insert({ara[i].S,i}); /// {size,id}

    int ans = 0;

    while(!s.empty())
    {
        ans++;

        auto p = *s.begin();
//        DBG(p);
        s.erase(p);

        if(s.empty())
            break;

        int id = p.S;

        int l_id, l_v  = INT_MIN, r_id, r_v = INT_MAX, l_sz  = -1, r_sz = -1;

        l_id = l[id];
        if(l_id != -1) l_v = ara[l_id].F, l_sz = ara[l_id].S;
        r_id = r[id];
        if(r_id != n) r_v = ara[r_id].F , r_sz = ara[r_id].S;

        if(l_v==r_v)
        {
            s.erase({l_sz,l_id});
            s.erase({r_sz,r_id});

            r[l_id] = r[r_id];
            l[r[r_id]] = l_id;

            l_sz += r_sz;
            ara[l_id].S = l_sz;

            s.insert({l_sz,l_id});

//            for(auto x:s)
//                cout<<x<<" ";
//            cout<<endl;
        }
        else
        {
            r[l_id] = r_id;
            l[r_id] = l_id;
        }
    }


    cout<<ans<<endl;

    return 0;
}

/**

{4, 0}  {3, 12}  {3, 11}  {2, 15}  {2, 2}  {1, 10}  {1, 9}  {1, 8}  {1, 7}  {1, 6}  {1, 5}  {1, 4}  {1, 3}  {1, 1}
{5, 11}  {2, 2}  {1, 10}  {1, 9}  {1, 8}  {1, 7}  {1, 6}  {1, 5}  {1, 4}  {1, 3}  {1, 1}
{2, 1}  {1, 10}  {1, 9}  {1, 8}  {1, 7}  {1, 6}  {1, 5}  {1, 4}


{-4, 0}  {-3, 11}  {-3, 12}  {-2, 2}  {-2, 15}  {-1, 1}  {-1, 3}  {-1, 4}  {-1, 5}  {-1, 6}  {-1, 7}  {-1, 8}  {-1, 9}  {-1, 10}
{-4, 10}  {-2, 2}  {-2, 15}  {-1, 1}  {-1, 3}  {-1, 4}  {-1, 5}  {-1, 6}  {-1, 7}  {-1, 8}  {-1, 9}
{-3, 9}  {-2, 2}  {-1, 1}  {-1, 3}  {-1, 4}  {-1, 5}  {-1, 6}  {-1, 7}  {-1, 8}
{-2, 1}  {-1, 4}  {-1, 5}  {-1, 6}  {-1, 7}  {-1, 8}

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
