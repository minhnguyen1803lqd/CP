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

int a[N], n, sum;
int f[N];

bool Valid (int s) {
	for (int i = 1; i <= s; i++) {
		f[i] = 0;
	}
	f[0] = 1;
	f[s] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = s; j >= a[i]; j--) {
			if (f[j] == 0 && f[j - a[i]] == 1) {
				f[j] = 1;
			}
		}
	}
	return f[s];
}

main()
{
	fast;
	freopen ("CHIAKEO1.inp", "r", stdin);
	freopen ("CHIAKEO1.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int res = oo;
	for (int i = 1; i <= sum; i++) {
		if (Valid(i)) {
			res = min(res, abs(i - (sum - i)));
		}
	}
	cout << res << endl;
}
