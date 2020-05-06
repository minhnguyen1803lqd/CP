#include <bits/stdc++.h>

#define fi first
#define se second
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fast ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int N = 1e4 + 10;
const int oo = 1e9 + 7;

string a, b;
int f[N][N];

string Reverse(string x) {
	string res;
	for (int i = 0; i < x.length(); i++) {
		res = x[i] + res;
	}
	return res;
}

int main()
{
	fast;
	freopen ("tao-xau-doi-xung.inp", "r", stdin);
	freopen ("tao-xau-doi-xung.out", "w", stdout);
	cin >> a;
	b = Reverse(a);
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {
				f[i][j] = f[i - 1][j - 1] + 1;
			} else {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	cout << a.length() - f[a.length()][b.length()] << endl;
}
