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

int n, m;
int a[N], b[N];
int s = 0, ans = 0;

void Recur(int id) {
	if (id == n + 1) {
		if (s == m) {
			ans++;
		}
	} else {
		FOR(i, 0, b[id]) {
			s += (i * a[id]);
			if (s <= m) {
				Recur(id + 1);
			}
			s -= (i * a[id]);
		}
	}
}

main()
{
	fast;
	freopen ("DOITIENV3.inp", "r", stdin);
	freopen ("DOITIENV3.out", "w", stdout);

	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	FOR(i, 1, n) {
		cin >> b[i];
	}

	Recur(1);

	cout << ans << endl;

	return 0;
}
