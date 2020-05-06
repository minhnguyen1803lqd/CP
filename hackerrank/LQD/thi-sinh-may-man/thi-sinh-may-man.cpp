#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define ii pair < ll, ll >
#define vi vector < ll >
#define vii vector < ii >
#define fast ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int N = 1e5 + 10;
const int oo = 1e9 + 7;

ll n, k;
ii a[N];

ll Lower_Bound(ll l, ll r, ll val) {
	ll res = oo;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (a[mid].fi >= val) {
			if (a[mid].fi == val) {
				res = min(res, mid);
			}
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return res;
}

ll Upper_Bound(ll l, ll r, ll val) {
	ll res = -oo;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (val >= a[mid].fi) {
			if (val == a[mid].fi) {
				res = max(res, mid);
			}
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return res;
}

int main()
{
	fast;
	freopen ("thi-sinh-may-man.inp", "r", stdin);
	freopen ("thi-sinh-may-man.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + 1 + n);
	// for (int i = 1; i <= n; i++) {
	// 	cout << a[i].fi << " ";
	// }
	// cout << endl;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		ll l1 = Lower_Bound(i + 1, n, k - a[i].fi);
		ll r1 = Upper_Bound(i + 1, n, k - a[i].fi);
		ll l2 = Lower_Bound(i + 1, n, -k - a[i].fi);
		ll r2 = Upper_Bound(i + 1, n, -k - a[i].fi);
		// cout << "a[i]: " << a[i].fi << endl;
		// cout << "l1, r1: " << l1 << " " << r1 << endl;
		// cout << "l2, r2: " << l2 << " " << r2 << endl;
		if (l1 <= r1) {
			res += (r1 - l1 + 1);
		}
		if (l2 <= r2 && l1 != l2 && r1 != r2) {
			res += (r2 - l2 + 1);
		}
		// cout << "res: " << res << endl;
	}
	cout << res << endl;
}
