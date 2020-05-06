#include <bits/stdc++.h>

#define fi first
#define se second
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)

using namespace std;

const int N = 1e5 + 10;
const int oo = 1e9 + 7;

int n, k, ans = 0;
ii a[N];

ii Lower_bound(int L, int R, int val) {
	int l = L, r = R, res = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (val <= a[mid].fi) {
			if (val == a[mid].fi) {
				res = mid;
			}
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return a[res];
}
ii Upper_bound(int L, int R, int val) {
	int l = L, r = R, res = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (val >= a[mid].fi) {
			if (val == a[mid].fi) {
				res = mid;
			}
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return a[res];
}

main()
{
	fast;
	freopen ("LUCKY.inp", "r", stdin);
	freopen ("LUCKY.out", "w", stdout);

	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i].fi;
		a[i].se = i;
	}

	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; i++) {
		cout << a[i].fi << " " << a[i].se << endl;
	}
	cout << "----\n";

	for (int i = 1; i <= n; i++) {
		ii low = Lower_bound(1, n, abs(k - a[i].fi));
		ii up = Upper_bound(1, n, abs(k - a[i].fi));
		
	}


	return 0;
}
