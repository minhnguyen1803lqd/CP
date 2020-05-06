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


const int N = 1e3 + 10;
const int oo = 1e9 + 7;

int n, amount = 0;
int x[N], cnt[N];
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
		FOR(i, 1, n) {
			if (cnt[i]) {
				x[id] = i;
				cnt[i]--;
				Recur(id + 1);
				cnt[i]++;

			} else {
				continue;
			}
		}
	}
}

main()
{
	fast;
	freopen ("PERMS.inp", "r", stdin);
	freopen ("PERMS.out", "w", stdout);

	cin >> n;

	FOR(i, 1, n) {
		cnt[i] = 1;
	}

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
