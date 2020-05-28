#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	bool flag = false;
	int people[7][24];
	for (int i = 0; i < 7; ++i){
		for (int j = 0; j < 24; ++j){
			people[i][j] = 10;
		}
	}
	int m;
	for (int i = 0; i < 10; ++i){
		cin >> m;
		for (int j = 0; j < m; ++j){
			int a, b, c;
			cin >> a >> b >> c;
			if (flag) continue; // optimisation.
			for (int k = b; k < c; ++k){
				--people[a-1][k];
				if (people[a-1][k] < 3) flag = true;
			}
		}
	}
	if (flag == true) cout << "NON\n";
	else cout << "OUI\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; ++i){
		cout << "Groupe # 1 : "; 
		solve();
	}

	return 0;
}

