#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e4 + 7;

int n, m, source, sink, k;
vector < ii > g[N];
int flow[N][N];
int level[N];

bool BFS(int source, int sink) {
    memset(level, 0, sizeof(level));
    queue < int > q;
    q.push(source);
    level[source] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        REP(i, g[u].size()) {
            int v = g[u][i].fi;
            int cap = g[u][i].se;
            if (!level[v] and flow[u][v] < cap) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return (level[sink]);
}

int DFS(int u, int sink, int maxFlow) {
    if (u == sink) return (maxFlow);
    REP(i, g[u].size()) {
        int v = g[u][i].fi;
        int cap = g[u][i].se;
        if (level[v] == level[u] + 1 and flow[u][v] < cap) {
            int currFlow = min(maxFlow, cap - flow[u][v]);
            int res = DFS(v, sink, currFlow);
            if (res > 0) {
                flow[u][v] += res;
                flow[v][u] -= res;
                return (res);
            }
        }
    }
    return (0);
}

int main() {
    fileInput("mincost");
    fast;
    cin >> n >> m >> k >> source >> sink;
    FOR(i, 1, m) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        g[u].pb(ii(v, c));
        g[v].pb(ii(u, 0));
    }
    int ans = 0;
    while (BFS(source, sink)) {
        while (int incFlow = DFS(source, sink, inf)) {
            ans += incFlow;
        }
    }
    cout << ans << endl;
    return (0);
}