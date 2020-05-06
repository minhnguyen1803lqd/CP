#include <bits/stdc++.h>

#define ii pair < int, int >

using namespace std;

const int N = 1e2;
const int oo = 1e9 + 7;
const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

ii s;
int n;

void Setup() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("knight-with-chess.inp", "r", stdin);
	freopen ("knight-with-chess.out", "w", stdout);
}

bool Inside(int x, int y) {
	return (1 <= x && x <= 10 && 1 <= y && y <= 10);
}

void BFS(ii S, int limit) {
	queue < ii > q;
	int depth[N][N];
	int color[N][N];

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			color[i][j] = 0;
			depth[i][j] = 0;
		}
	}

	q.push(s);
	color[s.first][s.second] = 1;
	depth[s.first][s.second] = 0;
	
	while (q.empty() == false) {
		ii CurNode = q.front();
		q.pop();
		
		if (depth[CurNode.first][CurNode.second] == limit) {
			continue;
		} else {
			for (int i = 0; i < 8; i++) {
				int x = CurNode.first + dx[i];
				int y = CurNode.second + dy[i];
				if (!(depth[x][y] > limit) && color[x][y] == 0 && Inside(x, y)) {
					q.push(make_pair(x, y));
					color[x][y] == 1;
					depth[x][y] = depth[CurNode.first][CurNode.second] + 1;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (depth[i][j] == limit) {
				cnt++;
			}
		}
	}
	if (limit % 2 == 0) {
		cnt += 1;
	}
	cout << cnt << endl;

}

int main() {
	Setup();
	cin >> s.first >> s.second >> n;
	BFS(s, n);
}
