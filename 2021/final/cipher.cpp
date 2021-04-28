// ?? XOR is function with only 1 value 1 ouput -- maybe useful


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


int lis(int k) {
	ll ans = 0;
	ll dp[n];
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (xored[j] < xored[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(dp[i], ans);
		if (ans > k) return -1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	n = 100;
	//cin >> n;
	//for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) a[i]=i;

	for (int k = 1; k <= n; ++k) {
		for (int i = 0; i < n; ++i) {
			xored[i] = a[i] ^ k;
		}
		cout << k << " : " <<lis(k) <<endl;
		//if (lis(k) == k) {
			//cout << k << "\n";
		//}
	}


	return 0;
}
