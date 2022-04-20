#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXP=2010;

bitset<MAXP> dp[2][2];

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
	//vector<vector<vector<int>>> dp(p+1, vector<vector<int>>(2, vector<int>(2, 0)));
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		if (a[i].second == 'f') {
			dp[0][1] |= (dp[0][1] << a[i].first);
			dp[0][1] |= (dp[0][0] << a[i].first);
			dp[1][1] |= (dp[1][1] << a[i].first);
			dp[1][1] |= (dp[1][0] << a[i].first);
		} else {
			dp[1][0] |= (dp[1][0] << a[i].first);
			dp[1][1] |= (dp[1][1] << a[i].first);
			dp[1][0] |= (dp[0][0] << a[i].first);
			dp[1][1] |= (dp[0][1] << a[i].first);
		}
	}

	//cout << dp[1][1] << "\n";
	cout << (dp[drink][1][p]?"possible":"impossible")<<"\n";


	return 0;
}

