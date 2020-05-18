/*	Problem Statement:
 *	Mouse wants all cheese in cave of height h and length l
 *	Use minimum amount of dynamite to break through destructable walls to get all cheese.
 *	Mouse can only go horizontal or vertical (no diag).
 *	
 *	Input:
 *	int h (height), int l (length), vector <string> lab (cave layout)
 *	3 <= h, l <= 20, every cave is surrounded by indestructible walls and has exactly 1 entrance. 
 *	No destructable walls directly adjacent to other destructible walls.
 *
 *	Output:
 *	Minimum number of dynamite to get all the cheese.
 *
 * 	# indestructible
 * 	- Destructable
 *	. Empty
 *	F Cheese
 *	E Entry Point
 *
 *
 *	Note: Solution is very messy. Will maybe clean up later.
 *	
 *	Explainaition uses doors instead of destructable. 
 *	
 *	Solution Idea:
 *	1. 	Go through all squares and merge all freely reachable squares into nodes, doors are also nodes.
 *	2. 	Go through all doors and add adjacent nodes to adjacency list (representation for graph).
 *	3. 	Go through all nodes with cheese and check the shortest path from that node to the entry point using bfs.
 *		NOTE: Shortest path always is the one with least doors, as doors and open nodes are always alternating.
 *		Iterate over all shortest paths to entry point (one node can have multiple shortest paths) and keep frequency of nodes being in a shortest path.
 *	4.	Iterate over all reachable nodes with cheese and choose node which is 1. already opened or  2. with highest frequency (from last step). Keep all doors which then get opened in seperate array / set.
 *	5.	Return number of doors which get opened.
 *
 *	Time Complexity: O( (h*l)^2 )
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

set <int> reachable;
pair <int, int> entry;
set <pair <int, int> > doors;
map <int, int> cheeses;
map <int, int> fdoors;
int doorstart;
int cnt = 1;

void dfs(int i,int  j,int x,vector<string> lab, vector <vector<int>> (&v)){
	if (lab[i][j] == '#' || v[i][j] != 0) return;
	if (lab[i][j] == 'E') entry = make_pair(i,j);
	else if (lab[i][j] == '-'){
		v[i][j] = -1;
		doors.insert(make_pair(i,j));
		return;
	}
	if (lab[i][j] == 'F' && v[i][j] == 0){
		cheeses[x]++;
		//cout << "\nfound cheese ";
	}
	v[i][j] = x;
	// check all adjacent squares
	dfs(i+1,j,x,lab,v);
	dfs(i-1,j,x,lab,v);
	dfs(i,j+1,x,lab,v);
	dfs(i,j-1,x,lab,v);
	return;
}

void addEdge(vector <int> adj[],int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

int getDist(vector <int> adj[], int cur, int dest){ // suboptimal bfs function which gets all reachable nodes and get frequency of all nodes in shortest paths.
	// dont really need ans here. might remove later.
	int ans = -1;
	bool flag = false;
	queue <pair<pair<int, int>, vector<int>>> q;
	vector <bool> visited(cnt, false);
	vector <int> tmpv;
	tmpv.push_back(cur);
	q.push(make_pair(make_pair(cur, 0), tmpv));
	visited[cur] = true;
	while(!q.empty()){
		pair <pair<int,int>, vector <int>> f = q.front();
		q.pop();
		int res = f.first.second;
		int u = f.first.first;
		vector <int> cv = f.second;
		if (u == dest){
			flag = true;
			for (int i = 0; i < cv.size(); ++i){
				if (i != 0)	fdoors[cv[i]]++;
				if (cv[i] < doorstart)	reachable.insert(cv[i]);
			}
			ans = res;
		}
		if (u >= doorstart) { // increment res if node is a door.
			res++;
		}
		visited[u] = true;
		if (!flag){
			if (adj[u].size() == 0){ // if node is unreachable
				return 0;
			}
			for (int i = 0; i < adj[u].size(); ++i){ // iterate over all adjacent nodes
				if (!visited[adj[u][i]]){
					vector <int> tmpcv = cv;
					tmpcv.push_back(adj[u][i]);
					q.push(make_pair(make_pair(adj[u][i], res), tmpcv));
				}
			}
		}
	}
	return ans;
}

void search(vector <int> adj[], int src){
	int dist[cnt];
	for (auto& i : cheeses){
		dist[i.first] = getDist(adj, i.first, src);
	}

	return;
}

int walk(vector <int> adj[],int start, int dest, vector <bool> &seen){
	int cur = start;
	int ans = 0;
	set <int> tobedeleted;
	while (cur != dest){
		pair <int, int> candidate = {-1,-1};
		for (int i = 0; i < adj[cur].size(); ++i){
			if (fdoors[adj[cur][i]] > candidate.second){
				candidate = make_pair(adj[cur][i], fdoors[adj[cur][i]]);
			}
			if (seen[candidate.first]){
				return ans;
			}
		}
		if (candidate.first >= doorstart) {
			ans++;
		}
		for (int i = 0; i < adj[candidate.first].size(); ++i){
			tobedeleted.insert(adj[candidate.first][i]);
		}
		cur = candidate.first;	
	}
	for (auto &i : tobedeleted){
		seen[i] = true;
	}
	return ans;
}

int chasse(int h, int l, vector <string> lab){
//	Clear global variables.
	reachable.clear();
	doors.clear();
	cheeses.clear();
	fdoors.clear();
	doorstart = 0;
	cnt = 1;

//	Iterate over all squares in cave.
	vector <vector<int>> v(h, vector<int>(l,0)); 
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < l; ++j){
			if (v[i][j] == 0 && lab[i][j] != '-' && lab[i][j] != '#'){ // Check if square is already assigned to node.
				dfs(i,j,cnt, lab, v);	// Look through all freely available nodes and assign them to node with val cnt.
				cnt++;	
			}
		}
	}
	//cout << "\n-----doors------\n";
	//cout << "start from " << cnt << "\n";
	doorstart = cnt;
	vector <int> adj[h*l];
	for (auto& i : doors){
		 //cout << i.first << " " << i.second << ", ";
		 if (i.first+1 < h && lab[i.first+1][i.second] != '#') addEdge(adj, cnt, v[i.first+1][i.second]);
		 if (i.first-1 >= 0 && lab[i.first-1][i.second] != '#') addEdge(adj, cnt, v[i.first-1][i.second]);
		 if (i.first+1 < l && lab[i.first][i.second+1] != '#') addEdge(adj, cnt, v[i.first][i.second+1]);
		 if (i.second-1 >= 0 && lab[i.first][i.second+1] != '#') addEdge(adj, cnt, v[i.first][i.second-1]);
		 cnt++;
	}

	int entryset = v[entry.first][entry.second]; // helper variable to get the set in which the entry point is included.

	search(adj, entryset);

	vector <bool> seen (cnt, false);
	int ans = 0;
	for (auto &i : reachable){
		if (!seen[i])
			ans += walk(adj, i, entryset, seen);
	}
	//cout << "\n\n --------finalans--------\n\n" << ans << endl;

	
	return ans;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector <string> lab = {	"######",
		"#...F#",
		"#E...#",
		"######"
	};
	cout << chasse(4,6,lab) << endl;
	vector <string> lab2 = {

			"#########",
			"#E.....F#",
			"##-#.#-##",
			"#.F.-..F#",
			"#########"
	};
	cout << chasse(5,9,lab2) << endl;
	vector <string> lab3 = {
			"############",
			"#E.....F-.F#",
			"##-#.#-#####",
			"#.F.-..F#F##",
			"############"
	};
	cout << chasse(5,12,lab3) << endl;
	vector <string> lab4 = {
		"#########",
		"#E...-.F#",
		"#####.###",
		"#.F.#-.F#",
		"#########"
	};

	cout << chasse(5,9,lab4) << endl;

	vector <string> lab5 = {
		"#########",
		"#E.F.-.F#",
		"#########"
	};
	cout << chasse(3,9,lab5) << endl;

	return 0;
}

