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
#ifndef ONLINE_JUDGE
#define debug(a) cout<<#a<<" --> "<<(a)<<"\n";
#define debug2(a) cout<<#a<<" --> "<<(a)<<" ";
#define HERE cout<<"here - "<<__LINE__<<"\n";
#else
#define debug(a)
#define debug2(a)
#define HERE
#endif
const ll mod = 1e9+7;
const int N = 1e5+5;

bool solve(int k,vector<int>&dp, vector<int>&a, int mini)
{
    assert(k>=0);
    if(k<mini)
        return false;
    if(dp[k]!=-1)
        return dp[k];
    bool ans= false;
    for(int j:a)
    {
        if(j>k)
        {
            break;
        }
        if(solve(k-j,dp,a,mini)==0)
        {
            ans = true;
            break;
        }
    }
    return dp[k]= ans;
}
void TEST_CASES(int cas)
{
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int>a(n),dp(k+1, -1);
    for(int &i:a)
    {
        scanf("%d",&i);
    }
    int mini = a[0];

    if(solve(k,dp,a,mini))
    {
        printf("First\n");
    }
    else{
        printf("Second\n");
    }


}


/*

*/

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1,cas=0;
    //scanf("%d",&t);
    while(t--)
    {
        TEST_CASES(++cas);
    }

    return 0;
}



//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order()

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
