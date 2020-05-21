#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << n / 200 << " x 200\n";
	n -= (n / 200)*200;
	cout << n / 100 << " x 100\n";
	n -= (n / 100)*100;
	cout << n / 50 << " x 50\n";
	n -= (n / 50)*50;
	cout << n / 20 << " x 20\n";
	n -= (n / 20)*20;
	cout << n / 10 << " x 10\n";
	n -= (n / 10)*10;
	cout << n / 5 << " x 5\n";
	n -= (n / 5)*5;

	return 0;
}

