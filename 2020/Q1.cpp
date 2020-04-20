#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = -3; i <= 3; ++i)
		{
			if (3*i+n >= 0 && 3*i+n <= 9){
				ans++;
			}
		}	
	cout << ans;
	return 0;
}