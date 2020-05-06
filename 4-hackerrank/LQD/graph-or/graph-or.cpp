#include <bits/stdc++.h>

#define fi first
#define se second
#define ii pair < int, int >
#define vii vector < ii >

using namespace std;

const int N = 3e3 + 10;
const int oo = 1e9 + 7;

int n, StartNode, EndNode, m;
int f[N][N];
vii G[N];

void Setup() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("graph-or.inp", "r", stdin);
	freopen ("graph-or.out", "w", stdout);
}

void BFS(int S, int E) {
	queue < ii > q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 1024; j++) {
			f[i][j] = -1;
		}
	}
	q.push(make_pair(S, 0));
	f[S][0] = 1;

	while (q.empty() == false) {
		ii CurNode = q.front();
		q.pop();
		int u = CurNode.first;
		int du = CurNode.second;
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].first;
			int w = (G[u][i].second | du);
			if (f[v][w] == -1) {
				q.push(make_pair(v, w));
				f[v][w] = 1;
			}
		}
	}
	for (int i = 1; i <= 1024; i++) {
		if (f[E][i] != -1) {
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
	return;
}

int main() {
	Setup();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	}
	cin >> StartNode >> EndNode;
	BFS(StartNode, EndNode);
}
