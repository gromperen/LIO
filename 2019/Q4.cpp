#include <bits/stdc++.h>
using namespace std;

#define ll long long

int part(int a[], int low, int high){
	int p = a[high];
	int r = low - 1;
	for (int i = low; i < high; ++i){
		if (a[i] > p){
			++r;
			swap(a[r], a[i]);
		}
	}
	swap(a[r+1], a[high]);
	return r + 1;
}

void quickSort(int a[], int low, int high){
	if (low < high){
		int p = part(a, low, high);

		quickSort(a, low, p - 1);
		quickSort(a, p+1, high);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	quickSort(a, 0, n-1);
	for (int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}

	return 0;
}

