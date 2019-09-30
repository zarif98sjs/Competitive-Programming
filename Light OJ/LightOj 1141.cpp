
/**Which of the favors of your Lord will you deny ?**/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

string to_str(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

const int nmax = 1e3+7;
const LL LINF = 1e17;

LL LIM;
bitset<nmax> bs;   // 10^7 should be enough for most cases
vector<LL> primes;

void bit_sieve(LL upperbound)
{
    LIM = upperbound + 1;
    bs.set();                                                 // set all bits to 1
    bs[0] = bs[1] = 0;
    for (LL i = 2; i <= LIM; i++)
        if (bs[i])
        {
            for (LL j = i * i; j <= LIM; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
}

bool isPrime(LL N)
{
    if (N <= LIM)
        return bs[N];                   // O(1) for small primes

    // note: only work for N <= (last prime in vi "primes")^2
    for (LL x:primes)
        if (N % x == 0)
            return false;
    return true;                    // it takes longer time if N is a large prime!
}

int vis[nmax];

int bfs(int s,int t)
{
    queue<PII>q;
    q.push({s,0});

    while(!q.empty())
    {
        int now = q.front().F;
        int d = q.front().S;
        q.pop();
        vis[now] = true;

        //cout<<"--> "<<now<<" , "<<d<<endl;

        if(now==t)
            return d;

        for(int x:primes)
        {
            if(x<now && now%x==0 && x+now<=t && !vis[now+x])
            {
                q.push({x+now,d+1});
            }
            if(x>=now)
                break;
        }
    }

    return -1;

}

int main()
{
    optimizeIO();

    int tc;
    cin>>tc;

    bit_sieve(1000);

    for(int q=1; q<=tc; q++)
    {
        memset(vis,0,sizeof vis);

        int s,t;
        cin>>s>>t;

        int ans = bfs(s,t);

        cout<<"Case "<<q<<": "<<ans<<endl;
    }

    return 0;
}
