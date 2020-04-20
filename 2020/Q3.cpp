// Time Complexity O(n^3) should work as 1 <= n <= 100, -1000 <= xi <= 1000, -1000 <= yi <= 1000

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	vector<pair<int,int>> cords;
	vector<vector<double>> distances(n);
	vector<int> alive;
	
	//input
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		{
			int x, y;
			cin >> x >> y;
			cords.push_back(make_pair(x,y));
			alive.push_back(i);
		}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			double distx = abs(cords[i].first - cords[j].first);
			double disty = abs(cords[i].second - cords[j].second);
			distances[i].push_back(sqrt((distx*distx)+(disty*disty)));	//calculate distance for point i to point j and save at distances[i][j]
		//	cout << distances[i][j] << "\n";
		}
		//cout << "\n-------\n";
	}
	int cnt = 0;
	//calculates rounds and increments cnt after round.
	while(true){
		//cout << "\n ROUND #" << cnt << "\n";
		bool changed = false;
		int flag = 0;
		vector<int> bouttadie;
		for (int i = 0; i<alive.size(); i++){
			double curdist = 5005;
			int distindx;
			for (int j = 0; j < alive.size(); j++){
				if (i == j) continue;
				if (distances[alive[i]][alive[j]] == curdist){
					flag = 1;
					changed = false;
				}
				if (distances[alive[i]][alive[j]] < curdist){
					changed = true;
					curdist = distances[alive[i]][alive[j]];
					distindx = alive[j];
					flag = 0;
				}
			
			}
			if (flag == 0){
				bouttadie.push_back(distindx);
				//cout << "\nA killed B: " << alive[i]<< " " <<distindx << " distance " << curdist;
			}
		}

		for (int i = 0; i < alive.size(); ++i)
		{
			if (find(bouttadie.begin(), bouttadie.end(), alive[i]) != bouttadie.end()){
				alive.erase(alive.begin() + i);
				i--;
			}
		}

		cnt++;
		if (!changed){					// if there hasnt been any changes to last round then exit
			cout << cnt-1 << endl;
			for (int i = 0; i < alive.size(); ++i)
			{
				cout << alive[i]+1 << " ";
			}
			break;
		}
		else if(alive.empty()){				// if noone is alive then exit
			cout << cnt << endl;
			cout << "+";
			break;
		}
		
	}
	
	
	return 0;
}
