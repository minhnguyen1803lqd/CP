#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 7;

int n, m, ans = -inf;
int dis[N], color[N];
vector < int > g[N];

void DFS(int u) {
    color[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (!color[v]) {
            dis[v] = dis[u] + 1;
            DFS(v);
        }
    }
}

main() {
    fileInput("longest-path");
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) color[j] = 0, dis[j] = 0;
        DFS(i);
        int res = -inf;
        for (int j = 1; j <= n; ++j) res = max(res, dis[j]);
        ans = max(ans, res);
        cout << "log: " << i << " " << res << endl;
    }
    cout << ans << endl;
}