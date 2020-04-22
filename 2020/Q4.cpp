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
	int cumulative[n][m] = {};
	for (int i = 0; i < k; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;
		grid[x-1][y-1] = w;
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i== 0 && j==0)
				cumulative[i][j] = grid[i][j];
			else if (i == 0)
				cumulative[i][j] = grid[i][j] + cumulative[i][j-1];
			else if (j == 0)
				cumulative[i][j] = grid[i][j] + cumulative[i-1][j];
			else
				cumulative[i][j] = grid[i][j] + cumulative[i-1][j] + cumulative[i][j-1] - cumulative[i-1][j-1];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)	
		{
			int i2 = i + l -1;
			int j2 = j + h -1;
			int tmp;
			if (i2 >= n || j2 >= m) continue;

			if (i == 0 && j == 0){
				tmp = cumulative[i2][j2];
			}
			else if (i == 0){
				tmp = cumulative[i2][j2] - cumulative[i2][j-1];
			}
			else if (j == 0){
				tmp = cumulative[i2][j2] - cumulative[i-1][j2];
			}
			else {
				tmp = cumulative[i2][j2] - cumulative[i-1][j2] - cumulative[i2][j-1] + cumulative[i-1][j-1];
			}
			ans = max(ans, tmp);
		}
	}
	cout << ans;

	
	return 0;
}