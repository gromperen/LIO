#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, l, h, k;
	cin >> n >> m >> l >> h;
	cin >> k;
	int grid[n][m] = {} ;
	int sumgrid[n][m] = {};
	for (int i = 0; i < k; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;
		grid[x-1][y-1] = w;
		cout << "\nINSERTED " << grid[x-1][y-1];
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	cout << grid[0][2];


	
	return 0;
}