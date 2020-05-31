/*	Task: 
 *	Find how many edges to add for an euler circuit.
 *

Input:
3
3 3
1 2
2 3
1 3
3 1
1 2
4 2
1 2
3 4

 */
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(vector <int> adj[], vector <bool> &vis, vector <int> &odd, vector <int> &deg, int cnt, int cur){
	vis[cur] = true;
	if (deg[cur] % 2 == 1){
		odd[cnt]++;
	}
	for (auto i : adj[cur]){
		if (!vis[i]){
			dfs(adj, vis, odd, deg, cnt, i);
		}
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector <int> adj[n+1];
	vector <int> deg(n+1,0);
	for (int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	/*
	cout << "\nDEBUG\n";
	for (int i = 1; i <= n; ++i){
		cout << i << " is adj to:\n";
		for (auto j : adj[i]){
			cout << j << " ";
		}
		cout << "\n";
	}
	*/
	
	vector <bool> vis(n+1, false);
	
	vector <int> evencmps, oddcmps;

	vector <int> odd (n+1, 0);
	int cnt = 0;
	for (int i = 1; i <= n; ++i){
		if (!vis[i]){
			cnt++;
			dfs(adj, vis, odd, deg, cnt, i);
			
			if (odd[cnt] == 0){
				evencmps.push_back(cnt);
			}
			else {
				oddcmps.push_back(cnt);
			}
		}
	}
	int ans = 0;
	if (evencmps.size() == 1 && oddcmps.size() == 0){
		ans = 0;
		//cout << "\nAlready an euler circuit\n";
	}
	else if (oddcmps.size() == 0) {
		//cout << "\nAll connected components are even\n";
		ans = evencmps.size();
	}
	else {
		if (evencmps.size() != 0) {
			ans = evencmps.size();
			//cout << "\nGraph has at least 1 connected component: " << ans << "\n";
		}
		for (int i : oddcmps){
			ans += odd[i]/2;
		}
	}
	cout << ans << "\n";


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		cout << "Office membre " << i << ":\n";
		solve();
	}

	return 0;
}

