#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
1:
	Perform dijksta with weight as combination of do i have to pay and time. ?? IDK SEAMS KINDY SKETCHY
2:
	Perform dijkstra 0 -> l times check if its possible under the time.
		If yes -> WIN
		If no -> continue with 1 more pay thing allowed.

	Have l+1 queues for using 0 -> l peage thingies.
		dijkstra those queeues

*/


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, l, t;
	cin >> n >> m>>l>>t;

			//(id, time, pay? )
	vector <tuple<int,int, bool>> nb[n+1];

	for (int i = 0; i < m;++i) {
		int a, b, w;
		cin >> a >> b >> w;
		nb[a].push_back(make_tuple(b, w, 0));
		nb[b].push_back(make_tuple(a, w, 0));
	}
	for (int i = 0; i < l;++i) {
		int a, b, w;
		cin >> a >> b >> w;
		nb[a].push_back(make_tuple(b, w, 1));
		nb[b].push_back(make_tuple(a, w, 1));
	}

				// (dist, vertex)
	vector<priority_queue<tuple<int, int>>> top_q(l+1);
	int dist[l+1][n+1] = {};

	for (int i = 0; i <= l; ++i) {
		dist[i][0] = 0;
		for (int j = 0; j <= n; ++j) {
			dist[i][j] = INT_MAX;
		}
	}
	top_q[0].push(make_tuple(0, 1));

	for (int i = 0; i <= l; ++i) {
		while(!top_q[i].empty()) {
			int d, cur;
			tie(d, cur) = top_q[i].top(); top_q[i].pop();
			if (d >= dist[i][cur]) {
				continue;
			}

			dist[i][cur] = d;

			if (cur == n) {
				continue;
			}

			for (int j = 0; j < nb[cur].size(); ++j) {
				if (get<2>(nb[cur][j])) { // if i have to pay
					if (i == l) continue;
					top_q[i+1].push(make_tuple(d + get<1>(nb[cur][j]), get<0>(nb[cur][j])));
				} else {
					top_q[i].push(make_tuple(d + get<1>(nb[cur][j]), get<0>(nb[cur][j])));
				}
			}
		}
		if (dist[i][n] <= t) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
