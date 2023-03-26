// SELF LOOPS? 
// DOUBLE BRIDGES?? 
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long

const int MAXN = 10005;
const int INF = 1e15+7;

vector<int> adj[MAXN];

int cnt = 0;

int vis[MAXN];
int dp[MAXN];

int dfs(int u) {
	if (adj[u].size() <= 1) return 1;
	if (vis[u] == 1) return dp[u] = INF;
	if (dp[u] != 0) return dp[u];
	vis[u] = 1;
	vector<int> nxt;
	for (int v: adj[u]) {
		nxt.push_back(dfs(v));
		vis[v] = 0;
	}
	sort(nxt.begin(), nxt.end());
	reverse(nxt.begin(), nxt.end());
	return dp[u] = 1 + nxt[1];

}


int32_t main() {
	int n, m, s; cin >> n >> m >> s;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	int ans = dfs(s);
	if (ans >= INF) cout << "0\n";
	else cout << ans << "\n";


	

	return 0;
}
