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

const int N = 1e4 + 10;
const int oo = 1e9 + 7;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n;
ii Start, End;
int color[N][N];

void Recur(int X, int Y) {	
	if (X == End.fi && Y == End.se) {
		cout << "YES\n";
		exit(0);
	}
	color[X][Y] = 1;
	REP(i, 4) {
		int x = dx[i] + X;
		int y = dy[i] + Y;
		if (1 <= x && 1 <= y && x <= n &&  y <= n) {
			if (!color[x][y]) {
				Recur(x, y);
			}
		}
	}
}

main()
{
	fast;
	freopen ("LINE.inp", "r", stdin);
	freopen ("LINE.out", "w", stdout);

	cin >> n >> Start.fi >> Start.se >> End.fi >> End.se;
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			cin >> color[i][j];
		}
	}
	
	Recur(Start.fi, Start.se);

	cout << "NO\n";


	return 0;
}
