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

int n, k;
int x[N];
vector < vi > ans;

void Save() {
	vi tmp;
	FOR(i, 1, n) {
		tmp.push_back(x[i]);
	}
	ans.push_back(tmp);
}

void Recur(int id) {
	if (id == n + 1) {
		Save();
	} else {
		FOR(i, 1, k) {
			x[id] = i;
			Recur(id + 1);
		}
	}
}

main()
{
	fast;
	freopen ("KNARY.inp", "r", stdin);
	freopen ("KNARY.out", "w", stdout);

	cin >> k >> n;

	Recur(1);

	cout << ans.size() << endl;
	REP(i, ans.size()) {
		REP(j, ans[i].size()) {
			cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}
