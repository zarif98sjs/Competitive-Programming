#include<bits/stdc++.h>
using namespace std;
signed main(){
	int t, n, k, i, j, ans;
	string s;
	cin >> t;
	while( t-- ){
		cin >> n >> k;
		cin >> s;
		vector<int> pre(n+1,0); // prefix array
		for( i = 1 ; i <= n ; i++ )
			pre[i] = pre[i-1] + (s[i-1]=='1');

		// dp[i] = minimum cost up to indx 'i' such that lamp
		//	   at index 'i' is last turned on lamp
		vector<int> dp(n+1,0);
		ans = pre[n];
		for( i = 1 ; i <= n ; i++ ){
			if( i-k >= 1 ){
				// dp[i] = min( all Turned off upto i-k , last turned on is 'i-k'th lamp )
				//         + (cost to turn off lamp between i and i-k )
				//	   + ( cost to turn on ith lamp (single) )
				dp[i] = min( pre[i-k], dp[i-k] )
					+  ( pre[i-1]-pre[i-k] )
					+   (s[i-1] != '1') ;	// note : dp array is 1 based indx
			}else{
				dp[i] = pre[i-1] + (s[i-1] != '1');
			}

			cout<<i<<" : "<<dp[i]<<endl;
			cout<<" Pre : "<<pre[n]-pre[i]<<endl;

			ans = min( ans, dp[i] + (pre[n]-pre[i]) );
		}
		cout << ans << endl;
	}
	return 0;
}
