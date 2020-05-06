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

int n, m, maxVal = 0, s = 0;
ii a[N];
int x[N];
vi ans;

void Save() {
	int weight = 0, val = 0;
	FOR(i, 1, n) {
		weight += (x[i] * a[i].fi);
		val += (x[i] * a[i].se);
	}
	if (weight <= m && val > maxVal) {
		maxVal = val;
		ans.clear();
		FOR(i, 1, n) {
			if (x[i]) {
				ans.push_back(i);
			}
		}
	}
}

void Recur(int id) {
	if (id == n + 1) {
		if (s <= m) {
			Save();
		}
	} else {
		REP(i, 2) {
			x[id] = i;
			if (x[id] == 1) {
				s += a[id].fi;
			}
			if (s <= m) {
				Recur(id + 1);
			}
			if (x[id] == 1) {
				s -= a[id].fi;
			}
		}
	}
}

main()
{
	fast;
	freopen ("CATU.inp", "r", stdin);
	freopen ("CATU.out", "w", stdout);

	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a[i].fi >> a[i].se;
	}

	Recur(1);

	cout << maxVal << endl;
	REP(i, ans.size()) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}
