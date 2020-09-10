#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef tree<int,null_type,less<int >,rb_tree_tag,tree_order_statistics_node_update>indexed_set;
template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);
template <class T1, class T2>
ostream &operator <<(ostream &os, map<T1,T2>&v);
#ifdef APURBA
#define HERE cout<<"here - "<<__LINE__<<"\n";
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it)
{
    cout<<endl;
}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << " ";
    err(++it, args...);
}
#else
#define HERE
#define debug(args...)
#endif
//const ll mod = 1e9+7 ;
const int N = 2e5+5;
typedef pair<int,int> pii;

int mul(int a, int b, int mod)
{
    return a*1ll*b %mod;
}

int solve(int idx,int now,int koto, vector<int>&a , int &mod)
{
    if(idx==a.size()){
        if(koto==0)
        {
            return 0;
        }
        return now;
    }
    int x = solve(idx+1 , mul(now, a[idx] , mod),koto+1 , a , mod);
    int y = solve(idx+1 ,now,koto,a,mod);
    return max(x,y);
}
void TEST_CASES(int cas)
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int>a(n),b(n),c(m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&c[i]);
    }
    vector<vector<int> >groups(m);
    for(int i=0;i<n;i++)
    {
        groups[a[i]].push_back(b[i]);
    }
    //debug(groups);
    for(int i=0;i<m;i++)
    {
        printf("%d ",solve(0,1,0,groups[i],c[i]));
    }
    printf("\n");
}


/*

*/

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        TEST_CASES(++cas);
    }
    return 0;
}



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
template <class T1, class T2>
ostream &operator <<(ostream &os, map<T1,T2>&v)
{
    for(auto i:v)
    {
        os<<"Key : "<<i.first<<" , Value : "<<i.second<<endl;
    }
    return os;
}

