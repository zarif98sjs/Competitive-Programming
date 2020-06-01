/*
    Author : RAJON BARDHAN
    AUST CSE 27th Batch
    All my programming success are dedicated to my mom , dad , little sister madhobi , teachers , friends and love TANIA SULTANA RIMY

    Problem Name : 1064 - Throwing Dice ( LightOJ )
    ALGORITHM : Probability + Dynamic Programming
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846

typedef long long ll ;
typedef unsigned long long ull ;

/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

int n , x ;
ll power[30] , dp[30][200] ;

void pre_process()
{
    power[0] = 1 ;
    for(int i=1;i<=25;i++) power[i] = power[i-1]*(ll)6 ;
}

ll solve(int pos,int sum)
{
    if(pos>n)
    {
        if(sum>=x) return 1 ;
        else return 0 ;
    }
    ll &ret = dp[pos][sum] ;
    if(ret!=-1) return ret ;
    ret = 0 ;
    for(int i=1;i<=6;i++) ret+=solve(pos+1,sum+i);
    return ret ;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    pre_process();

    int T ;
    scanf("%d",&T);

    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&x);
        memo(dp,-1);
        ll u = solve(1,0);
        cout<<"U : "<<u<<endl;
        ll v = power[n];

        ll gcd = __gcd(u,v);
        u/=gcd ;
        v/=gcd ;

        cout << "Case " << cas << ": " << u ;
        if(v!=1&&u!=0) cout << '/' << v ;
        cout << endl ;
    }
    return 0;
}
