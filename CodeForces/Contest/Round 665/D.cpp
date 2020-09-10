
/** Which of the favors of your Lord will you deny ? **/

#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define F first
#define S second

#define ALL(x) (x).begin(), (x).end()
#define READ freopen("alu.txt", "r", stdin)
#define WRITE freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x) cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

template <class T1, class T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p);
template <class T>
ostream &operator<<(ostream &os, vector<T> &v);
template <class T>
ostream &operator<<(ostream &os, set<T> &v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

#define int long long

const int nmax = 2e5 + 7;
const int mod = 1e9 + 7;

int n;
vector<vector<int>> adj;
vector<int> dp;

void dfs(int u, int p = -1)
{
    dp[u] = 1;

    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);

            dp[u] += dp[v];
        }
    }
}

void INIT(int len)
{
    adj = vector<vector<int>>(len);
    dp = vector<int>(len);
}

int32_t main()
{
    optimizeIO();

    int tc;
    cin >> tc;

    while (tc--)
    {

        cin >> n;

        INIT(n + 1);

        for (int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int cnt;
        cin >> cnt;

        vector<int> pf(cnt);

        for (int i = 0; i < cnt; i++)
            cin >> pf[i];

        sort(ALL(pf));

        dfs(1);

        for (int i = 1; i <= n; i++)
            dp[i] *= (n - dp[i]);

        sort(ALL(dp));
        DBG(dp);

        int ans = 0;

        if (cnt > n - 1)
        {
            int notun = 1;
            for (int i = n - 2; i < cnt; i++)
                notun = (notun * pf[i]) % mod;

            pf[n - 2] = notun;

            DBG(pf);

            for (int i = 0; i < n - 1; i++)
                ans = (ans + (dp[i + 2] * pf[i]) % mod) % mod;
        }
        else
        {
            reverse(ALL(pf));
            while ((int)pf.size() < n - 1)
            {
                pf.push_back(1);
            }

            reverse(ALL(dp));

            DBG(pf);

            for (int i = 0; i < n - 1; i++)
                ans = (ans + (dp[i] * pf[i]) % mod) % mod;
        }

        cout << ans << endl;

        DBG(ans);
    }

    return 0;
}

/**
4
1 2
2 3
3 4
5
2 2 3 3 3

16

5 10

16 1

14 1

7 5

13 2

16 11

1 7

1 4

3 14

8 16

1 6

4 9

4 12

5 13

1 15

18

45893 9901 51229 15511 46559 28433 4231 30241 29837 34421 12953 6577 12143 52711 40493 89 34819 28571

**/

template <class T1, class T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p)
{
    os << "{" << p.first << ", " << p.second << "} ";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> &v)
{
    os << "[ ";
    for (T i : v)
    {
        os << i << " ";
    }
    os << " ]";
    return os;
}

template <class T>
ostream &operator<<(ostream &os, set<T> &v)
{
    os << "[ ";
    for (T i : v)
    {
        os << i << " ";
    }
    os << " ]";
    return os;
}
