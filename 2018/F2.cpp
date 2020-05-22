#include <bits/stdc++.h>
using namespace std;

#define ll long long

map <int, int> depth;

void search(int cur, vector <int> adj[]){
	for (int i = 0; i < adj[cur].size(); ++i){
		depth[adj[cur][i]] = max(depth[adj[cur][i]], depth[cur] + 1);
		search(adj[cur][i], adj);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	set <char> characters;
	vector <string> a;
	vector <pair<char, char>> pairs;
	while (true) {
		string tmp;
		cin >> tmp;
		if (tmp == "#") break;
		a.push_back(tmp);
	}
	for (int i = 0; i < a.size(); ++i){
		for (char c : a[i]){
			characters.insert(c);
		}
	}
	for (int i = 0; i < a.size() - 1; ++i){
		int j = 0;
		while (a[i][j] == a[i+1][j] && j < a[i].size() && j < a[i+1].size() ){
			j++;
		}
		if (j != a[i].size() || j != a[i+1].size()){
			pairs.push_back(make_pair(a[i][j], a[i+1][j]));
			//cout << "made pair " << a[i][j] << " " << a[i+1][j] << endl;
		}
	}
	map <char, int> m;
	map <int, char> m2;
	int iter = 0;
	for (auto i : characters){
		m[i] = iter;
		m2[iter] = i;
		iter++;
	}
	//for (auto i : m) {
		//cout << i.first << " " << i.second << endl;
	//}
	vector <int> adj[iter];
	vector <int> incoming[iter];
	for (int i = 0; i < pairs.size(); ++i){
		adj[m[pairs[i].first]].push_back(m[pairs[i].second]);
		incoming[m[pairs[i].second]].push_back(m[pairs[i].first]);
	}
	/*
	//debug
	for (int i = 0; i < iter; ++i){
		cout << i << ": ";
		for (auto j : adj[i]){
			cout << j << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < iter; ++i){
		cout << i << ": ";
		for (auto j : incoming[i]){
			cout << j << " ";
		}
		cout << endl;
	}
	//debug
	*/
	
	int starti = -1;
	for (int i = 0; i < iter; ++i){
		if (incoming[i].size() == 0){
			starti = i;
			break;
		}
	}
	depth[starti] = 0;
	search(starti, adj);

	char s[iter];
	for (auto i : depth){
		s[i.second] = m2[i.first];
		//cout << m2[i.first] << " " <<  i.second << endl; 
	}
	cout << s << endl;



	return 0;
}

