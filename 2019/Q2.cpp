#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int ans = 0;
	getline(cin, s);
	map<char, bool> m;
	for (char c : s){
		if (!isalpha(c) || c == ' ') continue;
		char tmp = tolower(c);
		if (m[tmp] == false){
			ans++;
			m[tmp] = true;
		}
	}
	if (ans < 26) cout << "NOK\n";
	else cout << "OK\n";
	

	return 0;
}

