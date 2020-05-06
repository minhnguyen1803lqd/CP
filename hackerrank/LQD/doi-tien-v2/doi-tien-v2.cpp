#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
const int oo = 1e9 + 7;

int n, m;
int a[N];
int f[N][N];

void Setup() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("doi-tien-v2.inp", "r", stdin);
	freopen ("doi-tien-v2.out", "w", stdout);
}

int main() {
	Setup();
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; i++) {
		f[0][i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = f[i][j - 1];
			if (i >= a[j]) {
				f[i][j] = f[i][j] + f[i - a[j]][j];
			}
		}
	}
	cout << f[m][n] << endl;
}