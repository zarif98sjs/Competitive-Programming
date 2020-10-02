    #pragma GCC optimize("O3")
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC optimize("no-stack-protector")
    #pragma GCC optimize("fast-math")
    #pragma GCC optimize("trapv")
    #pragma GCC target("sse4")

    #include <bits/stdc++.h>
    using namespace std;

    #define deb(x) cout << #x << " is " << x << "\n"
    #define int long long
    #define mod 1000000007
    #define PI acos(-1)

    void solve() {
    	int n, k;
    	cin >> n >> k;
    	int arr[n];
    	for(int i = 0; i < n; i++)
    		cin >> arr[i];
    	int ans = 0;
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
            if (arr[i] > k or arr[i] < -1 * k)
                ans++;
        }
        if (arr[0] > k || arr[0] < -1 * k)
            ans++;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            int id = (upper_bound(arr, arr + n, arr[i] + k) - arr);
            cout<<id<<endl;
            ans += n - id;
        }

        cout << ans << "\n";
    }

    int32_t main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(nullptr);
    	int tc = 1;
    	cin >> tc;
    	while(tc--) {
    	    solve();
    	}
    	return 0;
    }
