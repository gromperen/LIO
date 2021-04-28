// ?? XOR is function with only 1 value 1 ouput -- maybe useful

// O(n² log n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 5001;
ll a[MAXN];
ll xored[MAXN];
ll n;

//int solve() {
//
//}


int lis() { // O(n log n)
	ll ans = 0;
	ll dp[n];
	ll level[n];
	for (int i = 0; i < n; ++i) {
		int j = lower_bound(dp, dp+ans,xored[i]) - dp;
		level[i] = j;
		dp[j] = xored[i];
		if (j == ans) ++ans;
		/*
		for (int j = 0; j < i; ++j) {
			if (xored[j] < xored[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		*/
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//n = 10;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	//for (int i = n; i >= 0; --i) a[i]=i;

	for (int k = 1; k <= n; ++k) {
		for (int i = 0; i < n; ++i) { // O(n²)
			xored[i] = a[i] ^ k;
			//cout << xored[i] << " ";
		}
		//cout << endl;
		//cout << k << " : " <<lis(k) <<endl;
		if (lis() == k) { // O(n² log n)
			cout << k << "\n";
		}
	}


	return 0;
}
