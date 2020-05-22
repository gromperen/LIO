#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, A;
	cin >> N >> A;
	vector <int> v(A+1, 0);

	for (int i = 0; i < N; i++){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		v[tmp1] = tmp2;
		
	}
	cout << endl;
	for (int i = 0; i <= A; ++i) cout << v[i] << " ";
	cout << endl;
	

	vector <int> steps(A+2);
	//	initialize steps as not taking any jetpacks.
	for (int i = 0; i <= A; ++i){
		steps[i] = i;
		cout << steps[i] << " ";
	}
	cout << endl;
	
	for (int i = 0; i <= A; ++i){
		if (i != 0)
			steps[i] = min(steps[i], steps[i-1] + 1);
		steps[i + v[i] ] = min(steps[i + v[i] ], steps[i]);
	}

	cout << steps[A] << endl;


	return 0;
}

