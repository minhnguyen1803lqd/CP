#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define ii pair < int, int >
#define fi first
#define se second

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e2 + 7;

int n, m;
char a[N][N];
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int color[N][N];

void BFS(ii startNode) {
    queue < ii > q;
    q.push(startNode);
    color[startNode.fi][startNode.se] = 1;
    
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        for (int k = 0; k < 8; k++) {
            int x = u.fi + dx[k], y = u.se + dy[k];
            if (!color[x][y] and a[x][y] == 'W') {
                q.push(make_pair(x, y));
                color[x][y] = 1;
            }
        }
    }
}

main() {
    fileInput("bclkcoun");
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            color[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'W' and !color[i][j]) {
                BFS(make_pair(i, j));
                ans++;
            }
        }
    }
    cout << ans << endl;
}