#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int INF = 1e9;
const int MAXN = 5005;

vector<vector<int>> lookup(MAXN, vector<int> (MAXN, 0));
int parent[MAXN+1];
ll size[MAXN+1];

int find(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = find(parent[v]);
}

void make (int v) {
	parent[v] = v;
	size[v] = 1;
}

void unite(int v, int w, int mn){
	v = find(v);
	w = find(w);

	if (v != w) {
		if (size[v] < size[w]) {
			swap(v,w);
		}
		parent[w] = v;
		size[v] += size[w];
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, Q;
	cin >> n >> m >> Q;
	vector<tuple<int, int, int>> el(m);
	for (int i = 0; i < m; ++i) {
		int a, b, l;
		cin >> a >> b >> l;
		el[i] = make_tuple(l, a, b);
	}
	vector<pair<int,int>> queries(Q);
	vector <int> ans(Q, -1);
	for (int i = 0; i < Q; ++i) {
		int a, b;
		cin >> a >> b;
		queries[i] = make_pair(a, b);
	}
	sort(el.begin(), el.end());

	for (int i = 1; i <= n; ++i) {
		make(i);
	}

	int mn = 0;
	for (int i = 0; i < m; ++i) {
		int w = get<0> (el[i]);
		int a = get<1> (el[i]);
		int b = get<2> (el[i]);
		if (find(a) != find(b)) {
			mn = max(w, mn);
			unite(a,b, mn);
		}
		for (int q = 0; q < Q; ++q) {
			if (ans[q] == -1) {
				if (find(queries[q].first) == find(queries[q].second)) {
					ans[q] = mn;
				}
			}
		}
	}

	for (int i = 0; i < Q; ++i) {
		cout << ans[i] << "\n";
	}

	return 0;
}
