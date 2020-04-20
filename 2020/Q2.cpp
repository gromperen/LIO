#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<ll> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634, 8208, 9474,54748, 92727, 93084, 548834, 1741725, 4210818, 9800817, 9926315};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool bol = false;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < nums.size(); i++){
		if (nums[i] <= m && nums[i] >= n){
			cout << nums[i] << "\n";
			bol = true;
		}
	}
	if (!bol) cout << "Rien";
	
	return 0;
}