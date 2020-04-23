#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<int, vector<pair<int, int>>> m;
	unordered_set<int> teachers;
	vector<pair<int, int>> a;
	int counter = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int p, s, f;
		cin >> p >> s >> f;
		m[p].push_back(make_pair(s, f));
		teachers.insert(p);
	}
	for (auto& elem : teachers){
		if (m[elem].size() == 1){
			a.push_back(m[elem][0]);
		}
		else {
			sort(m[elem].begin(), m[elem].end());
			int flag = 0;
			int save_index;
			for (int i = 0; i < m[elem].size(); ++i){
				if (m[elem][i+1].first - m[elem][i].second <= 10){	
					if (flag == 0){
						m[elem][i].second = m[elem][i+1].second;
						flag = 1;
						save_index = i;
					}
					else{
						m[elem][save_index].second = m[elem][i+1].second;
					}
					i++;
					if (i >= m[elem].size() - 2){
						a.push_back(m[elem][save_index]);
					}
				}
				else{
					a.push_back(m[elem][i]);
					if (flag == 1){
						a.push_back(m[elem][save_index]);
					}
					flag = 0;
				}
			}
		}
	}
	sort(a.begin(), a.end());

	while(!a.empty()){
		int x = a[0].second;
		a.erase(a.begin());
		counter++;
		for (int j = 0; j < a.size(); j++){
			if (a[j].first >= x){
				x = a[j].second;
				a.erase(a.begin() + j);
			}
		}
		
	}

	cout << counter;

	return 0;
}