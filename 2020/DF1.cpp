#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int r = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		char c;
		cin >> c;
		if (c == 'r'){
			r++;
		}
		else {
			r--;
			if (r < 0){
				ans++;
				r++;
			}
		}
	}
	cout << ans+r;
	
	return 0;
}