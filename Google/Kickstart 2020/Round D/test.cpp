#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define XX              first
#define YY              second
#define PB              push_back
#define MP              make_pair

#define NEWLINE         cerr << "\n";
#define HOISE           cerr << "hoise " << __LINE__ << "\n"
#define PAUSE           system("pause")
#define DEBUG(x)        cerr << #x << " = " << x << "\n"
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long long ll;
typedef pair<int, int > pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 23;
const ll INFL = 2e18 + 23;

inline void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> b;
    for(int i = 1; i < n; i++){
        if(a[i-1] > a[i]) b.PB(0);
        else if(a[i-1] < a[i]) b.PB(1);
    }
    int ans = 0;
    for(int i = 0; i < b.size(); i++){
        int j = i;
        while(j<b.size() and b[j]==b[i]) j++;
        int cnt = j-i;
        ans += cnt/4;
        i = j-1;
    }
    cout << ans << "\n";
}

int32_t main()
{
    FASTIO;

    int tc;
    cin >> tc;
    for(int nc = 1; nc <= tc; nc++){
        cout << "Case #" << nc << ": ";
        solve();
    }

    return 0;
}
