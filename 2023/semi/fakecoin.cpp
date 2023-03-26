// TERNARY SEARCH ???++?


#include "fakecoin.h"
#include <bits/stdc++.h>
using namespace std;

int guess(int n){
	int l = 1, r = n; 
	while (l < r) {
		int sz = ((r-l + 1)/3);
		sz = max(sz, 1);
		int m1 = l + sz-1;
		int m2 = m1 + 1 + sz - 1;
		assert(l <= m1 && m1 < m2 && m2 <= r);
		vector<int> left, right;
		for (int i = l; i <= m1; ++i) {
			left.push_back(i);
		}
		for (int i = m1+1; i <= m2; ++i) {
			right.push_back(i);
		}
		assert(left.size() == right.size());
		int q = query(left, right);
		if (q == 1) { // LEFT
			r = m1;
		} else if (q == -1) { // RIGHT
			l = m1+1;
			r = m2;
		} else {
			l = m2 + 1;
		}
	}

	return l;
}
