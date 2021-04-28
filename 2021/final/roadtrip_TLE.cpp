#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int INF = 1e9;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, Q;
	cin >> n >> m >> Q;
	vector<pair<int, int>> adj[n+1];
	for (int i = 0; i < m; ++i) {
		int a, b, l;
		cin >> a >> b >> l;
		adj[a].emplace_back(b, l);
		adj[b].emplace_back(a, l);
	}
	//vector<vector<ll>> dist(n+1, vector<ll> (n+1, INF)); // dist[i][j] min "battery size" from i to j i.e. from j to i

	//for (int i = 1; i <= n; ++i) {
	//}


	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for (int q = 0; q < Q; ++q) {
		vector<ll> dist(n+1, INF);
		int s, t; cin >> s >> t;
		dist[s] = 0;
		pq.emplace(0, s);
		while (!pq.empty()) {
			int d = pq.top().first;
			int u = pq.top().second;
			pq.pop();
			if (d > dist[u]) {
				continue;
			}
			for (int next = 0; next < adj[u].size(); ++next) {
				if (max(d, adj[u][next].second) >= dist[adj[u][next].first]) continue;
				else {
					dist[adj[u][next].first] = max(d, adj[u][next].second);
					pq.emplace(max(d, adj[u][next].second), adj[u][next].first);
				}
			}
		}
		cout << dist[t] << endl;
	}



	return 0;
}
