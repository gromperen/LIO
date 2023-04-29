#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define poopoo main

const int MAXN = 1e5+5;

vector<int> adj[MAXN];
vector<int> adj_r[MAXN];

vector<int> newadj[MAXN];
vector<int> order;

int vis[MAXN];
int who[MAXN];
int out_deg[MAXN];
int in_deg[MAXN];

void dfs1(int u) {
	vis[u] = 1;
	for (int v : adj[u]) {
		if (vis[v]) continue;
		dfs1(v);
	}
	order.push_back(u);
}

void dfs2(int u, int num) {
	vis[u] = 1;
	who[u] = num;
	
	for (int v : adj_r[u]) {
		if (vis[v]) continue;
		dfs2(v, num);
	}
}

int32_t poopoo() {
	int n, m; cin >> n >> m;
	vector<int> ind(n+1), outd(n+1);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj_r[v].push_back(u);
		ind[v]++;
		outd[u]++;
	}

	if (n == 1) {
		cout << "0\n";
		return 0;
	}

	/*
	int roots = 0, leaves = 0;
	for (int i = 1; i <= n; ++i) {
		assert(ind[i] + outd[i] > 0);
		if (ind[i] == 0) roots++;
		if (outd[i] == 0) leaves++;
	}
	cout << roots + leaves - min(roots , leaves) << "\n";
	*/

	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) dfs1(i);
	}
	reverse(order.begin(), order.end());
	memset(vis, 0, sizeof(vis));

	int components = 0;
	for (int i : order) {
		if (!vis[i]) {
			components++;
			dfs2(i, components);
		}
	}
	if (components == 1) {
		cout << "0\n";
		return 0;
	} 


	for (int i = 1; i <= n; ++i) {
		//cout << who[i] << " ";
		for (int v : adj[i]) {
			if (who[i] == who[v]) continue;
			newadj[who[i]].push_back(who[v]);
			out_deg[who[i]]++;
			in_deg[who[v]]++;
		}
	}

	int incnt = 0, outcnt = 0;
	for (int i = 1; i <= components; ++i) {
		if (in_deg[i] == 0) incnt++;
		if (out_deg[i] == 0) outcnt++;
	}

	cout << incnt + outcnt - min(incnt, outcnt)<< "\n";



	

	return 0;
}
