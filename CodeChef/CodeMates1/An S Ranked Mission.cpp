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
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
//const ll mod = 1e9+7 ;
const int N = 5e5+5;
typedef pair<int,int> pii;

vector<long long> primes;
ll l,r;
ll cnt[N];
vector<ll>factors[N];
void sieve()
{
    long long lim = 1e6;
    vector<bool> mark(lim + 1, false);
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
}
void trial_division(long long n,vector<ll>&v) {
    if(v.size()==0)
    {
        if(n==1)
        {
            cnt[n-l]=1;
        }
        else{
        cnt[n-l] =2;
        }
        return;
    }
    ll idx = n - l;
    cnt[idx]=1;
    for (long long d : v) {
        if (d * d > n)
            break;
        ll now =0;
        while (n % d == 0) {
            now++;
            n /= d;
        }
        cnt[idx]*=(now+1);
    }
    if (n > 1){
        cnt[idx]*=2;
    }

}
void segmentedSieve(long long L, long long R) {
    long long lim = sqrt(R);
    ll bal[lim+5]={0};
    /// 1st Step : we will identify all the prime factors of Numbers in the range [l,r] . But we will not know the powers . That we will do later .
    for(ll p:primes)
    {
        if(p>lim+1)
            break;
        ll x = l/p;
        while(p*x < l)
            x++;
        bal[p] = p*x; /// first number which this prime factor divides in the range [l,r]
//        DBG(p);
//        DBG(bal[p]);
        for(ll j=bal[p]-l ;j<=r-l;j+=p ) /// iterate over the range [l,r] and identify numbers which has this prime factor
        {
            factors[j].push_back(p);
        }
    }

    /// 2nd Step : Find the powers
    for(ll i=l ; i<=r;i++)
    {
        trial_division(i,factors[i-l]);
        //debug(factors[i-l],i,cnt[i-l]);
    }

}

void TEST_CASES(int cas)
{
    scanf("%lld %lld",&l,&r);
    for(ll i=l;i<=r;i++)
    {
        cnt[i-l] =0 ;
        factors[i-l].clear();
    }
    segmentedSieve(l,r);
//    ll mini = 1e18 , maxi = -1;
//    ll sum = 0;
//    ll scmin =0 , scmax = 0, scsum =0;
//    for(ll i=0;i<r-l+1;i++)
//    {
//        mini = min(mini , cnt[i]);
//        maxi = max(maxi , cnt[i]);
//    }
//    for(ll i=0;i<r-l+1;i++)
//    {
//        if(cnt[i]==mini)
//        {
//            scmin+= i+l;
//        }
//        if(cnt[i]== maxi)
//        {
//            scmax+= i+l;
//        }
//        if(cnt[i]!=mini && cnt[i]!=maxi)
//        {
//            scsum+= i+l;
//            sum+= cnt[i];
//        }
//    }
//    ll idx1 = mini%26;
//    ll idx2 = sum%26;
//    ll idx3 = maxi%26;
//    string s="";
//    if(idx1%2==0)
//    {
//        s+= ('A'+ idx1);
//    }
//    else{
//        s+= ('a'+idx1);
//    }
//    s+= to_string(scmin);
//    if(idx2%2==0)
//    {
//        s+= ('A'+ idx2);
//    }
//    else{
//        s+= ('a'+idx2);
//    }
//    s+= to_string(scmax);
//    if(idx3%2==0)
//    {
//        s+= ('A'+ idx3);
//    }
//    else{
//        s+= ('a'+idx3);
//    }
//    if(scsum%2)
//    {
//        reverse(s.begin(),s.end());
//    }
//    cout<<s<<"\n";

}


/*

*/

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    sieve();
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

