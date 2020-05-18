#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*	Task:
 *	N Students peel
 *	ith Student peels ai potatoes in a minute.
 *	M Students wash
 *	jth Student washes bj potatoes in a minute.
 *	End of each minute all peeled potatoes go to wash (0 time) from Katti
 *	Number of potatoes to cook k
 *	End of each minute progress is checked.
 *	Determine number of minutes after which they are finished.
 *
 * 	Input:
 *  n m k
 *  n lines ai
 *  m lines bi
 *	
 *	Output:
 *	1 integer - the number of minutes before before they are finished.
 *
 *
 *	Examples:
 * 	2 1 10
 * 	5
 * 	5
 * 	1
 *	Out: 11
 *
 *
 * 	3 2 21
 * 	2
 * 	2
 * 	1
 * 	3
 * 	3
 * 	Out: 6
 *
 * 	Time Complexity:
 * 	taking input: 	O(n+m)
 * 	Solution:		O(1)
 */


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i){
		int tmp;
		cin >> tmp;
		a += tmp;
	}
	for (int i = 0; i < m; ++i){
		int tmp;
		cin >> tmp;
		b += tmp;
	}
	a = min(k,a);
	if (a < b) b = a;
	int ans = 1;
	int r = k / a + (k % a != 0);
	int q = k / b + (k % b != 0);
	ans += max(r, q);
	cout << ans << endl;

	return 0;
}

