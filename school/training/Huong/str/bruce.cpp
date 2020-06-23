#include <bits/stdc++.h>
using namespace std;
string s, t;
int f[109][109];
int main() {
	freopen("str.inp", "r", stdin);
	freopen("str.ans", "w", stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s >> t;
	s = ' ' + s; t = ' ' + t;
	f[0][0] = 0;
	for (int i = 1; i <= 100; i++) f[i][0] = i, f[0][i] = i;
	for (int i = 1; i < s.length(); i++) {
		for (int j = 1; j < t.length(); j++) {
			if (s[i] == t[j]) f[i][j] = f[i - 1][j - 1];
			else f[i][j] = min(f[i - 1][j], min(f[i - 1][j - 1], f[i][j - 1])) + 1;
		}
	}
	cout << f[s.length() - 1][t.length() - 1];
	return 0;
}
//	Code supported by Võ Trường Trung Hiếu