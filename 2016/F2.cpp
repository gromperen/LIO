/*
 * 1 <= n, c1, c2 <= 400
4 10 10
7 6
5 3
5 9
3 2

20
 */


#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c1, c2;
	cin >> n >> c1 >> c2;
	int q[n];
	int w[n];
	for (int i = 0; i < n; ++i){
		cin >> w[i] >> q[i];
	}
	/*
	 * For subtask 1 and 2:
	 *
	int K[n+1][c1+1];
	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= c1; ++j){
			if (i == 0 || j == 0){
				K[i][j] = 0;
			}
			else if (w[i-1] <= j){
				K[i][j] = max(q[i-1] + K[i-1][j - w[i-1]],
						K[i-1][j]);
			}
			else {
				K[i][j] = K[i-1][j];
			}
		}
	}
	cout << K[n][c1] << "\n";
	*/
//	subtask 3:
	int K[n+1][c1+1][c2+1];
	for (int i = 0; i <= n; ++i){
		for (int w1 = 0; w1 <= c1; ++w1){
			for (int w2 = 0; w2 <= c2; ++w2){
				if (i == 0){
					K[i][w1][w2] = 0;
				}
				else {
					K[i][w1][w2] = K[i-1][w1][w2];
					if (w[i-1] <= w1){
						int tmp1 = q[i-1] + K[i - 1][w1 - w[i-1]][w2];
						K[i][w1][w2] = max(K[i][w1][w2], tmp1);
					}
					if (w[i-1] <= w2){
						int tmp2 = q[i-1] + K[i - 1][w1][w2 - w[i-1]];	
						K[i][w1][w2] = max(K[i][w1][w2], tmp2);
					}
				}
			}
		}
	}
	/*
	for (int I = 0; I <= n; ++I){
		for (int i = 0; i <= c1; ++i){
			for (int j = 0; j <= c2; ++j){
				cout << K[I][i][j] << " ";
			}
			cout << "\n";
		}
	}
	*/
	cout << "\n\n";
	cout << K[n][c1][c2] << endl;
	

	return 0;
}

