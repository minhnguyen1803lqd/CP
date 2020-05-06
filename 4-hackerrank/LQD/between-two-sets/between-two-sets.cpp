#include <bits/stdc++.h>

#define fi first
#define se second
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fast ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int N = 1e3 + 10;
const int oo = 1e9 + 7;

int n, m;
int a[N], b[N];
int res = 0;

main()
{
	fast;
	freopen ("between-two-sets.inp", "r", stdin);
	freopen ("between-two-sets.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= 100; i++) {
		int flag1 = 0, flag2 = 0;
		for (int k = 1; k <= n; k++) {
			if (i % a[k] != 0) {
				flag1 = 1;
				break;
			}
		}
		for (int h = 1; h <= m; h++) {
			if (b[h] % i != 0) {
				flag2 = 1;
				break;
			}
		}
		if (flag1 == 0 && flag2 == 0) {
			res++;
		}
	}
	cout << res << endl;

}
