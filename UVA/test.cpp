 #include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>

using namespace std;

#define clr( x , y ) memset(x,y,sizeof(x))
#define cls( x ) memset(x,0,sizeof(x))
#define mp make_pair
#define pb push_back
typedef long long lint;
typedef long long ll;
typedef long long LL;
const int maxn = 1e8 + 5 ;
const int pnum = 5761460 ;
bitset<maxn>noprime ;
unsigned int mul[pnum] ;
int p[pnum] , len ;
int sieve(){
    noprime.reset() ;
    for( int i = 2 ; i * i <= maxn ; i++ ){
        if( !noprime[i] ){
            for( int j = i * i ; j <= maxn ; j += i ){
                noprime[j] = 1 ;
            }
        }
    }
    int k = 0 ;
    for( int i = 2 ; i <= maxn ; i++ )
        if( !noprime[i] ) p[k++] = i ;
    return k ;
}

void init_lcm(){
    len = sieve() ;
    mul[0] = p[0] ;
    for( int i = 1 ; i < len ; i++ )
    {
        mul[i] = mul[i-1] * p[i] ;
        cout<<mul[i]<<endl;
    }

}

void solve( int n ){
    int pos = lower_bound( p , p + len , n ) - p ;
    if( p[pos] != n ) pos-- ;
    unsigned int ans = mul[pos] ;
    for( int i = 0 ; p[i] * p[i] <= n ; i++ )
    {
        int tmp = p[i] ;
        int tmp2 = p[i] * p[i] ;
        while( tmp2 / tmp == p[i] && tmp2 <= n )
        {
            tmp = tmp * p[i] ;
            tmp2 = tmp2 * p[i] ;
        }
        ans = ans * ( tmp / p[i] ) ;
    }
    cout << ans << endl ;
}
int main(){
// freopen("input.txt","r",stdin);
    int t ; cin >> t ; int kase = 1 ;
    init_lcm() ;
    while( t-- ){
        int n ;
        cin >> n ;
        printf( "Case %d: " , kase++ ) ;
        solve( n ) ;
    }
    return 0;
}
