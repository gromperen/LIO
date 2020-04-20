#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int,int>> cords;
	vector<vector<double>> distances(n);
	vector<int> alive;
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
			distances[i].push_back(sqrt((distx*distx)+(disty*disty)));
		//	cout << distances[i][j] << "\n";
		}
		//cout << "\n-------\n";
	}
	int cnt = 0;

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
		if (!changed){
			cout << cnt-1 << endl;
			for (int i = 0; i < alive.size(); ++i)
			{
				cout << alive[i]+1 << " ";
			}
			break;
		}
		else if(alive.empty()){
			cout << cnt << endl;
			cout << "+";
			break;
		}
		
	}
	
	
	return 0;
}