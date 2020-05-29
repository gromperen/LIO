#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector <int> adj[n+1];
	map <int, int> count;
	vector <int> vis(n+1);
	for (int i = 1; i <= n; ++i){
		vis.push_back(i); 
	}
	for (int i = 0; i < m; ++i){
		int tmpa, tmpb;
		cin >> tmpa >> tmpb;

		adj[tmpa].push_back(tmpb);
		adj[tmpb].push_back(tmpa);

		count[tmpa]++;
		count[tmpb]++;
	}


	vector <int> ans;
	while (true){
		pair <int, int> mn = {-1, INT_MAX};
		for (auto i : count){
			if (vis[i.first]) continue;
			if (i.second < mn.second){
				mn = i;
			}
		}
		if (mn.first == -1){
			break;
		}

		
		vis[mn.first] = true; 
		ans.push_back(mn.first);
		for (int i = 0; i < adj[mn.first].size(); ++i){
			vis[adj[mn.first][i]] = true;
		}
	}

	cout << ans.size() << "\n";
	for (auto i : ans){
		cout << i << " ";
	}
	


	return 0;
}

