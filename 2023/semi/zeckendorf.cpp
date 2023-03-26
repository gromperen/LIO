#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 1e8;

ll fib[50];

void solve() {
	int n; cin >> n;
	bool ok = false;
	for (int i = 40; i >= 0; --i) {
		if (fib[i] > n && !ok) continue; 
		if (fib[i] <= n) {
			ok = true;
			n-=fib[i];
			cout << "1";
		} else {
			cout << "0";
		}
	}
	cout << "\n";

}

int main() {
	fib[0]=1;
	fib[1]=2;
	for (int i = 2; i <= (int)40; ++i) {
		fib[i] = fib[i-1] + fib[i-2];
	}
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
