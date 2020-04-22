#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, mx = 0, mn = 0, cur = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		cur += tmp;
		if (cur - mn > mx){
			mx = cur - mn;
		}
		if (cur < mn){
			mn = cur;
		}
	}
	cout << mx;
	
	return 0;
}