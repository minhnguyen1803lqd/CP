#include <bits/stdc++.h>

#define fi first
#define se second
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fast ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int N = 2010;
const int oo = 1e9 + 7;

int n;
int a[N], b[N];
int f[N][N];

int main()
{
	fast;
	freopen ("noi-diem.inp", "r", stdin);
	freopen ("noi-diem.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		b[i] = i;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[1] == b[i]) f[1][i] = max(f[1][i - 1], 1);
		else f[1][i] = f[1][i - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) {
				f[i][j] = f[i - 1][j - 1] + 1;
			} else {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	cout << f[n][n] << endl;
}
