/*	There are many students who want to go on trip. Students want to be with their classes. Minimize number of buses needed for the trip. Each coach has capacity 50.
 *
 *	Input:
 *	number of classes N
 *	next N lines contain number of students in class.
 *
 *	Output:
 *	Number of buses needed.
 *
 *	Example:
 *	
 *	In:
 *	7
 *	20
 *	9
 *	23
 *	20
 *	12
 *	10
 *	1
 *	Out:
 *	2
 *
 *	Constraints:
 *	1 <= N <= 50
 *	number of students per class k. 1 <= k <= 29
 *	Bus capacity = 50
 *
 *
 *	Note:
 *	This is a bin packing problem. NP-Hard
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int firstFit(vector <int> a, int n){ // First fit decreasing order. Approx guarantee of (11/9) * OPT + (6/9).
									//	Can be improved using self balancing binary tree but considering max N is 50 not really necessary.
	int ans = 0; // count of bins
	int bins[n];
	for (int i = 0; i < n; ++i){
		int j;
		for (j = 0; j < ans; ++j){
			if (bins[j] >= a[i]){
				bins[j] -= a[i];
				break;
			}
		}
		if (j == ans){
			bins[ans] = 50 - a[i];
			++ans;
		}
	}
	return ans;
}

worstFit(vector <int> a, int n){
	int sum = 0;
	for (int i = 0; i < n; ++i){
		sum += a[i];
	}
	int minbins = sum / 50 + (sum%50 != 0);
	vector <int> bins;
	for (int i = 0; i < minbins; ++i){
		bins.push_back(50);
	}

	int cnt = minbins; // count of bins

	for (int i = 0; i < n; ++i){
		int j;
		int cur = -1, wi = 0; // current worst space left and worst index 
		for (j = 0; j < cnt; ++j){
			if (bins[j] >= a[i] && bins[j] - a[i] > cur) {
				wi = j;
				cur = bins[j] - a[i];
			} 
		}
		if (cur == -1){
			bins[cnt] = 50 - a[i];
			cnt++;
		}
		else {
			bins[wi] -= a[i];
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int res;

	sort(a.begin(), a.end(), greater <>());
	res = firstFit(a,n);

	res = min(res, worstFit(a, n));
	cout << res << endl;
	return 0;
}

