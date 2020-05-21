#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n, m;
	cin >> n >> m;
	if (n+m >= 100) cout << -1 << "\n";
	else if (n < m) cout << 0 << "\n";
	else if (n % m == 0) cout << 2 << "\n";
	else cout << 1 << "\n";
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--){
		solve();
	}

	return 0;
}

