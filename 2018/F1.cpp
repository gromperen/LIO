#include <bits/stdc++.h>
using namespace std;

#define ll long long


const int INF = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a; cin >> n >> a;

	vector<pair<int,int>> v(n+1);
	vector<int> dp(n+1, INF);

	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	v[n].first = a;
	sort(v.begin(), v.end());

	dp[0] = v[0].first;
	for (int i = 0; i <= n; ++i) {
		if (i > 0) {
			dp[i] = min(dp[i], dp[i-1] + v[i].first - v[i-1].first);
		}
		int k = lower_bound(v.begin(), v.end(), make_pair(v[i].first + v[i].second,-1)) - v.begin();
		dp[k] = min(dp[k], dp[i] + v[k].first - (v[i].first + v[i].second));
	}

	cout << dp[n] << "\n";

	return 0;
}

