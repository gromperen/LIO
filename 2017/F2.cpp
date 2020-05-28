#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(vector <bool> &vis, vector <int> adj[], int low[], set <pair <int, int >> &ans, int prevv, int curv, int curr){
	vis[curv] = true;
	low[curv] = curr;
	for (auto i : adj[curv]){
		if (i == prevv) continue;
		if (!vis[i]){
			dfs(vis, adj, low, ans, curv, i, curr+1);
		}
		low[curv] = min(low[curv], low[i]);
		if (low[i] > curr){
			ans.insert(make_pair(curv, i));
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	vector <int> adj[t];
	for (int i = 0; i < t; ++i){
		int id;
		cin >> id;
		int n;
		char tmp;
		cin >> tmp >> n >> tmp;
		for (int j = 0; j < n; ++j){
			int CUR;
			cin >> CUR;
			adj[id].push_back(CUR);
		}
	}
	
	int low[t];
	for (int i = 0; i < t; ++i){
		low[i] = i;
	}
	vector <bool> vis(t);
	set <pair<int, int> > ans;
	int prevv = -1; // prev vertex
	int curr = 0; // current rank
	for (int i = 0; i < t; ++i){
		if (!vis[i])
			dfs(vis, adj, low, ans, prevv, i, curr);
	}
	
	cout << ans.size() << " troncons sensibles\n";
	for (auto i : ans){
		cout << i.first << " - " << i.second << "\n";
	}

	return 0;
}

