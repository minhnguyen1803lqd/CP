#include <bits/stdc++.h>

#define ii pair < int, int >
#define fi first
#define se second
#define int long long
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)

using namespace std;

const int N = 1e6 + 10;
const int oo = 1e9 + 7;

int n, k, cnt = 0;
int x[N];

void Recur(int id);
bool Check();

main()
{
	fast;
	freopen ("TAMPHAN.inp", "r", stdin);
	freopen ("TAMPHAN.out", "w", stdout);

	cin >> n >> k;
	x[0] = -1;
	Recur(1);

	return 0;
}

void Recur(int id) {
	if (id == n + 1) {
		if (cnt + 1 < k) {
			FOR(i, 1, n) {
				cout << x[i];
			}
			cout << endl;
		}
	}
	else {
		if (id == 1) {
			FOR(i, 0, 2) {
				x[id] = i;
				Recur(id + 1);
			}
		}
		else {
			FOR(i, 0, 2) {
				x[id] = i;
				if (x[id] == x[id - 1]) cnt++;
				Recur(id + 1);
				if (x[id] == x[id - 1]) cnt--;
			}
		}
	}
}