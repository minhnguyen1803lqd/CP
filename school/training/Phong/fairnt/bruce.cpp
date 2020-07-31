#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".ans").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 7;

int n, m, k, s, ans[N], ok[N], color[N], val[N], dis[N];
vector < int > adj[N];

int BFS(int u, int &cnt) {
    for (int i = 1; i <= n; i++) color[i] = 0, dis[i] = 0;
    queue < int > q;
    q.push(u);
    color[u] = 1;
    dis[u] = 0;
    int res = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!color[v]) {
                q.push(v);
                color[v] = 1;
                dis[v] = dis[u] + 1;
                if (ok[val[v]] == 0) {
                    ok[val[v]] = 1;
                    cnt++;
                    res += dis[v];
                }
                if (cnt == s) return (res);
            }
        }
    }
    return (res);
}

main() {
    fileInput("fairnt");
    cin >> n >> m >> k >> s;
    if (s == 1) {
        for (int i = 1; i <= n; i++) cout << 0 << " ";
        exit(0);
    }
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) {
        for (int i = 1; i <= 100; i++) ok[i] = 0;
        int cnt = 1;
        ok[val[u]] = 1;
        int res = BFS(u, cnt);
        ans[u] = res;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}