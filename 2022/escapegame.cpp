#include "escapegame.h"

#include <bits/stdc++.h>

using namespace std;

int guess(int N, vector<int> u, vector<int> v){
	vector<vector<int>> adj(N+1);
	for (int i = 0; i < u.size(); ++i) {
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}
	int ans = 0;
	int sz = (N+1) / 2;
	int orig = 1;
	vector<int> maybe(N+1, 1);
	int cnt = 0;
	//cout << "OK" <<endl;
	while (sz > 0) {
		vector<bool> intree(N+1);
		queue<int> q;
		vector<int> rooms;
		q.push(orig);
		intree[orig] = 1;
		rooms.push_back(orig);
		cnt = 1;


		while(!q.empty() && cnt < sz) {
			int cur = q.front();
			q.pop();
			for (int next : adj[cur]) {
				if (intree[next]) continue;
				if (maybe[next]) cnt++;
				intree[next] = 1;
				q.push(next);
				rooms.push_back(next);
				if (cnt == sz) break;
			}
		}

		//for (int i = 1; i<= N; ++i) {
			//if (intree[i]) rooms.push_back(i);
		//}

		int maybecnt = 0;
		//cout << "roomsisze = " << rooms.size() << endl;
		//for (auto i: rooms) cout << i << " ";
		//cout << endl;
		if (query(rooms)) {
			//sz = (sz+1)/2;
			for (int i = 1; i <= N; ++i) {
				if (!intree[i]) maybe[i] = 0;
				if (maybe[i]) maybecnt++;
			}
		} else {
			//sz = (sz+1)/2;
			for (int i = 1; i <= N; ++i) {
				if (intree[i]) maybe[i] = 0;
				if (maybe[i]) orig = i;
				if (maybe[i]) maybecnt++;
			}
		}
		//cout << "MAYBE ";
		//cout << maybecnt<<endl;
		//for (int i = 1; i <= N; ++i) if (maybe[i]) cout << i << " ";
		//cout << endl;
		if (maybecnt == 1) {
			//cout << "FOUND " << orig << endl;
			break;
		}
		sz = (maybecnt+1) / 2;
		//assert((maybecnt+1)/2 < sz);
	}
	for (int i = 1; i <= N; ++i) if (maybe[i]) ans = i;
	//cout << "ANS IS " << ans << endl;
	return ans;
}

/*

5 2
1 3
1 2
4 5
2 4
 */
