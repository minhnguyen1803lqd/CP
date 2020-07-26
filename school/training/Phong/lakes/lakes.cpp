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

int n, m, k;
char a[N][N];
int color[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int BFS(ii node) {
    queue < ii > q;
    q.push(node);
    color[node.fi][node.se] = 1;
    int cnt = 0, flag = 1;

    while (!q.empty()) {
        cnt++;
        ii u = q.front();
        q.pop();
        if (u.fi == 1 or u.fi == n or u.se == 1 or u.se == m) {
            flag = 0;
        }
        for (int k = 0; k < 4; k++) {
            int x = u.fi + dx[k], y = u.se + dy[k];
            if (a[x][y] == '.' and !color[x][y]) {
                q.push(ii(x, y));
                color[x][y] = 1;
            }
        }
    }
    return (cnt * flag);
}

main() {
    fileInput("lakes");
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    memset(color, 0, sizeof(color));
    vector < ll > ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.' and !color[i][j]) {
                ll res = BFS(ii(i, j));
                ans.push_back(res);
            }
        }
    }
    sort(ans.begin(), ans.end());
    ll s = 0;
    for (int i = 0; i < ans.size() - k; i++) {
        s += ans[i];
    }
    cout << s << endl;
}