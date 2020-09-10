#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXBIT = 60;
const int MOD = 1E9+7;

int f[MAXBIT+2][2][2];

int n;

int dp(int i, int mod, bool ok){
	int& ret = f[i][mod][ok];
	if(ret != -1) return ret;
	if(i == MAXBIT) return ret = (mod == 0 && ok == 0);
	int bitn = (n>>i)&1;
	ret = 0;
	for(int a = 0; a < 2; ++a)
		for(int b = 0; b <=a ; ++b){
			int curbit = (a+b+mod)%2;
			int nmod = (a+b+mod)/2;
			bool nok = ok;
			if(curbit > bitn) nok = 1;
			if(curbit < bitn) nok = 0;
			ret += dp(i+1, nmod, nok);
			ret %= MOD;
 		}
 	return ret;
}

int32_t main() {
	cin >> n;
	memset(f, -1, sizeof f);
	cout << dp(0,0, 0);
	return 0;
}
