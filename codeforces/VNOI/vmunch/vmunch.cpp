#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define vi vector < int >
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e2 + 7;

int n, m;
int color[N][N], dis[N][N];
ii startNode, endNode;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void BFS(ii startNode, ii endNode) {
    queue < ii > q;
    q.push(startNode);
    color[startNode.fi][startNode.se] = 1;
    dis[startNode.fi][startNode.se] = 0;

    while (!q.empty()) {
        ii u = q.front();
        cerr << u.fi << " " << u.se << endl;
        q.pop();
        REP(k, 4) {
            int x = u.fi + dx[k];
            int y = u.se + dy[k];
            if (1 <= x and x <= n and 1 <= y and y <= m and !color[x][y]) {
                q.push(mp(x, y));
                color[x][y] = 1;
                dis[x][y] = dis[u.fi][u.se] + 1;
            }
        }
    }
    cout << dis[endNode.fi][endNode.se] << endl;
}

int main() {
    fileInput("vmunch");
    fast;
    cin >> n >> m;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            char type;
            cin >> type;
            if (type == 'B') startNode = mp(i, j);
            if (type == 'C') endNode = mp(i, j);
            if (type == '*') color[i][j] = 1;
        }
    }
    BFS(startNode, endNode);
    return (0);
}