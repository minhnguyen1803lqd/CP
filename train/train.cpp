#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define ii pair < int, int >
#define fi first
#define se second

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e3 + 7;

int n, m, color[N][N], dis[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
ii startNode, endNode;

void BFS() {
    queue < ii > q;
    q.push(startNode);
    color[startNode.fi][startNode.se] = 1;
    dis[startNode.fi][startNode.se] = 0;
    
    while (!q.empty()) {
        ii u = q.front();   
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int x = dx[k] + u.fi, y = dy[k] + u.se;
            if (1 <= x and x <= n and 1 <= y and y <= m and !color[x][y]) {
                q.push(make_pair(x, y));
                color[x][y] = 1;
                dis[x][y] = dis[u.fi][u.se] + 1;
            }
        }
    }
    cout << dis[endNode.fi][endNode.se] << endl;
}

main() {
    fileInput("train");
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char type;
            cin >> type;
            if (type == 'B') startNode = ii(i, j);
            else if (type == 'C') endNode = ii(i, j);
            else if (type == '*') color[i][j] = 1;
            else color[i][j] = 0;
        }
    }
    BFS();
}