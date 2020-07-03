
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
#define DBG(x) cout << __LINE__ << " says: " << #x << " = " << (x) << endl
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

//bool cmp(const PII &A,const PII &B)
//{
//
//}

/// sa[i] -> ith smallest suffix of the string (indexed from 1)
/// height[i] -> Longest common substring between Suffix(sa[i]) and Suffix(sa[i-1]), indexed
/// from i=2.
/// rak[i] -> The position of i th index of the main string in suffix array.
/// rak[6]=1 means 6th suffix is in 1st position in sa

const int N = 2e6+5;
int wa[N],wb[N],wv[N],wc[N];
int r[N],sa[N],rak[N], height[N], lg[N];

int cmp(int *r,int a,int b,int l)
{
      return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int *r,int *sa,int n,int m)
{
      int i,j,p,*x=wa,*y=wb,*t;
      for( i=0;i<m;i++) wc[i]=0;
      for( i=0;i<n;i++) wc[x[i]=r[i]] ++;
      for( i=1;i<m;i++) wc[i] += wc[i-1];
      for( i= n-1;i>=0;i--)sa[--wc[x[i]]] = i;
      for( j= 1,p=1;p<n;j*=2,m=p){
            for(p=0,i=n-j;i<n;i++)y[p++] = i;
            for(i=0;i<n;i++)if(sa[i] >= j) y[p++] = sa[i] - j;
            for(i=0;i<n;i++)wv[i] = x[y[i]];
            for(i=0;i<m;i++) wc[i] = 0;
            for(i=0;i<n;i++) wc[wv[i]] ++;
            for(i=1;i<m;i++) wc[i] += wc[i-1];
            for(i=n-1;i>=0;i--) sa[--wc[wv[i]]] = y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]] = 0,i=1;i<n;i++) x[sa[i]]= cmp(y,sa[i-1],sa[i],j) ? p-1:p++;

      }
}

void calheight(int *r,int *sa,int n)
{

      int i,j,k=0;
      for(i=1;i<=n;i++) rak[sa[i]] = i;
      for(i=0;i<n;height[rak[i++]] = k ) {

            for(k?k--:0, j=sa[rak[i]-1] ; r[i+k] == r[j+k] ; k ++) ;
      }

}

int dp[N][22];

void initRMQ(int n)
{
      for(int i= 1;i<=n;i++) dp[i][0] = height[i];
      for(int j= 1; (1<<j) <= n; j ++ ){
            for(int i = 1; i + (1<<j) - 1 <= n ; i ++ ) {
                  dp[i][j] = min(dp[i][j-1] , dp[i + (1<<(j-1))][j-1]);
            }
      }

}

int askRMQ(int L,int R)
{
      int k = lg[R-L+1];
      // int k=0;
      // while((1<<(k+1)) <= R-L+1) k++;
      return min(dp[L][k], dp[R - (1<<k) + 1][k]);
}
/// Precalculate powers of two to answer askRMQ in O(1)
int preclg2()
{
      for(int i=2; i<N; i++)
      {
            lg[i]=lg[i-1];
            if((i&(i-1))==0) lg[i]++;
      }
}

int main()
{
      string s; cin>>s;
      int n=s.size(), cnt=0;

      for(int i=0;i<s.size();i++)
      {
            r[i]=s[i]-'a'+1;
            // prnt(r[i]);
            cnt=max(cnt,r[i]);
      }

      r[n]=0; /// This is very important, if there are testacases!
      da(r,sa,n+1,cnt+1); /// cnt+1 is must, cnt=max of r[i]
      calheight(r,sa,n);

      printf("%d ",n);

      for(int i=1; i<=n; i++)
            printf("%d ",sa[i]);

//      for(int i=2; i<=n; i++)
//            printf("height[%d] = %d\n", i, height[i]);
//
//      for(int i=1; i<=n; i++)
//            printf("rank[%d] = %d\n", sa[i], rak[sa[i]]);
//
//      /// Must call initRMQ(len)
//      /// To find lcp between any two suffix i and j, call askRMQ(L+1,R)
//      /// where L=min(rak[sa[i]],rak[sa[j]]), R=max(rak[sa[i]],rak[sa[j]]).
//
//      /**
//        A Reminder: Sometimes when we concatenate strings, we do that by adding
//      separators. We might need to add same separator or different separators.
//      And it might also need to add a separator at the end of the total strings.
//      */

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


