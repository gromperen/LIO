#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 205;
const int MOD = 1e9+7;

ll dp[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l; cin >> n >> l;

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= l; ++j) {
			dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD; 
			if (i - 2 >= 0 && j - 1 >= 0)
				dp[i][j] = (dp[i][j] + 4 * dp[i-2][j-1]) % MOD; 
			if (i - 3 >= 0 && j - 2 >= 0)
				dp[i][j] = (dp[i][j] + 2 * dp[i-3][j-2]) % MOD; 
		}
	}
	ll ans = 0;
	for (int i = 0; i <= l; ++i) {
		ans = (ans + dp[n][i]) % MOD;
	}
	cout << ans<< "\n";

	return 0;
}

