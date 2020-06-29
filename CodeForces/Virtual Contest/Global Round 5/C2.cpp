
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second

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

class Point
{
public:
    LL x,y,z,id;

    Point()
    {
        x = y = z = id = 0;
    }

    Point(LL x,LL y,LL z,LL id)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->id = id;
    }
};

bool cmp(const Point &A,const Point &B)
{
    if(A.z==B.z)
    {
        if(A.y==B.y)
            return A.x<B.x;

        return A.y<B.y;
    }

    return A.z<B.z;
}

map< LL,vector<Point> >mpz;

vector<PII>ans;

Point solve_1d(vector<Point>&v)
{
    sort(ALL(v),cmp);

    for(int i=0;i<(int)v.size()-1;i+=2)
        ans.push_back({v[i].id,v[i+1].id});

//    cout<<"Ans: "<<ans<<endl;

    if(v.size()%2==1)
        return v[v.size()-1];

    return Point(0,0,0,-1);
}

Point solve_2d(const vector<Point>&v)
{
    map< LL,vector<Point> >mpy;

    for(auto p:v)
        mpy[p.y].push_back(p);

    vector<Point> vp;

    for(auto y:mpy)
    {
//        DBG(y.F);
        Point temp = solve_1d(y.S);

        if(temp.id!=-1)
            vp.push_back(temp);
    }

//    DBG(vp.size());

    for(int i=0;i<(int)vp.size()-1;i+=2)
    {
        ans.push_back({vp[i].id,vp[i+1].id});
    }


    if(vp.size()%2==1)
        return vp[vp.size()-1];

    return Point(0,0,0,-1);
}

void solve_3d()
{
    vector<Point> vp;

    for(auto z:mpz)
    {
//        DBG(z.F);
        Point temp = solve_2d(z.S);

        if(temp.id!=-1)
            vp.push_back(temp);
    }

    for(int i=0;i<vp.size();i+=2)
        ans.push_back({vp[i].id,vp[i+1].id});

    for(auto x:ans)
        cout<<x.F<<" "<<x.S<<endl;
}

int main()
{
    optimizeIO();

    int n;
    cin>>n;

    vector<Point>v;

    for(int i=0; i<n; i++)
    {
        LL a,b,c;
        cin>>a>>b>>c;

        v.push_back({a,b,c,i+1});
        mpz[c].push_back(v[i]);
    }

    solve_3d();


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


