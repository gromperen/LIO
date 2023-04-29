#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define poopoo main

const int MAXT = 7;
const int INF = 1e9+7;

int w[MAXT][MAXT];

// dp[n][n]
int dp[152][152][152*11]; 

int32_t poopoo() {
	int r, t, n; cin >> r >> t >> n;

	for (int i = 1; i <= t; ++i) {
		for (int j = 1; j <= t; ++j) {
			cin >> w[i][j];
		}
	}
	if (r == 1) {
		int prev = 0;
		int ans = 0;
		for (int i = 0; i < n;++i) {
			int x; cin >> x;
			ans += w[prev][x];
			prev = x;
		}
		cout << ans << "\n";
		return 0;
	}


	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int t = 1505; t >= 0; --t) {
				dp[i][j][t] = INF;
			}
		}

	}
	dp[0][0][0] = 0;

	vector<int> a(n+1 , 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (i == 1) {
			dp[0][1][0] = 0;
			dp[1][0][0] = 0;
			continue;
		}
		for (int j = 0; j <= i-2; ++j) {
			for (int t = 1505; t >= 0; --t) {
				dp[i][j][t] = min({dp[i][j][t], 
						w[a[i-1]][a[i]] + dp[i-1][j][t]
						});
				dp[i][i-1][t] = min(dp[i][i-1][t],
						w[a[j]][a[i]] + dp[j][i-1][t]
						);


				if (t-w[a[i-1]][a[i]] >= 0) {
					dp[j][i][t] = min({dp[j][i][t], 
						 dp[j][i-1][t-w[a[i-1]][a[i]]]
						});
				} else {
					dp[j][i][t] = dp[j][i][t];
				}

				if (t-w[a[j]][a[i]] >= 0) {
					dp[i-1][i][t] = min(dp[i-1][i][t],
						dp[i-1][j][t-w[a[j]][a[i]]]
						);
				}
				else {
					dp[i-1][i][t] = dp[i-1][i][t];
				}
				/*
				   dp[j][i] = min({dp[j][i], 
				   w[a[i-1]][a[i]] + dp[j][i-1]
				   });
				   dp[i-1][i] = min(dp[i-1][i],
					w[a[j]][a[i]] + dp[i-1][j]
					);
					*/


			}

		}
	}

	/*
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	int ans = INF;
	for (int j = 0; j <= n; ++j) {
		for (int t = 1505; t >= 0; --t) {
			ans = min(ans, max(dp[n][j][t], t));
			ans = min(ans, max(dp[j][n][t], t));
		}
	}
	cout << ans << "\n";


	return 0;
}
