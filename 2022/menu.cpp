#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	string tmp;
	cin >> n >> p >> tmp;
	bool drink = (tmp == "drink");
	vector<pair<int,char>> a(n);
	for (int i =0 ; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	vector<vector<vector<int>>> dp(p+1, vector<vector<int>>(2, vector<int>(2, 0)));
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = p; j>= 0; --j) {
			if (a[i].second == 'f') {
				if (j - a[i].first >= 0) {
					dp[j][0][1] |= dp[j-a[i].first][0][0];
					dp[j][0][1] |= dp[j-a[i].first][0][1];
					dp[j][1][1] |= dp[j-a[i].first][1][0];
					dp[j][1][1] |= dp[j-a[i].first][1][1];
				}
			} else {
				if (j - a[i].first >= 0) {
					dp[j][1][0] |= dp[j-a[i].first][0][0];
					dp[j][1][1] |= dp[j-a[i].first][0][1];
					dp[j][1][0] |= dp[j-a[i].first][1][0];
					dp[j][1][1] |= dp[j-a[i].first][1][1];
				}
			}
		}
	}

	cout << (dp[p][drink][1]?"possible":"impossible")<<"\n";


	return 0;
}

