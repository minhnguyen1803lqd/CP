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

int n, m, curX, curY;
int color[N][N];
int steps = 0;

void Recur(int X, int Y) {
	steps++;
	color[X][Y] = 1;
	REP(i, 4) {
		int x = X + dx[i];
		int y = Y + dy[i];
		if (1 <= x && 1 <= y && x <= n && y <= m) {
			if (!color[x][y]) {
				color[x][y] = 1;
				Recur(x, y);
			}
		}
	}
}

main()
{
	fast;
	freopen ("OCSE.inp", "r", stdin);
	freopen ("OCSE.out", "w", stdout);

	cin >> n >> m >> curX >> curY;
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			cin >> color[i][j];
		}
	}

	Recur(curX, curY);

	cout << steps << endl;

	return 0;
}
