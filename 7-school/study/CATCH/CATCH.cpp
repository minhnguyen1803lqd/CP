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

const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};

ii catPos;
vector < ii > mousePos;
string dir;

bool InZone(ii cor) {
	if (cor.fi == catPos.fi && cor.se == catPos.se) return true;
	int x = catPos.fi, y = catPos.se;
	REP(i, 8) {
		if (cor.fi == x + dx[i] && cor.se == y + dy[i]) {
			return true;
		}
	}
	return false;
}

main()
{
	fast;
	freopen ("CATCH.inp", "r", stdin);
	freopen ("CATCH.out", "w", stdout);

	cin >> catPos.fi >> catPos.se;
	cin >> dir;


	mousePos.push_back(make_pair(0, 0));
	int x = 0, y = 0;
	REP(i, dir.length()) {
		if (dir[i] == 'U') {
			x = x;
			y += 1;
		} else if (dir[i] == 'D') {
			x = x;
			y -= 1;
		} else if (dir[i] == 'L') {
			x -= 1;
			y = y;
		} else {
			x += 1;
			y = y;
		}
		mousePos.push_back(make_pair(x, y));
	}
	int flag = 0;
	REP(i, mousePos.size()) {
		if (InZone(mousePos[i])) {
			cout << i << "\n";
			flag = 1;
		}
	}

	if (flag) return 0;
	else {
		cout << -1 << endl;
	}

	return 0;
}
