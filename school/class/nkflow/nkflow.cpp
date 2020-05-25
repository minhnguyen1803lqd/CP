#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

int n, m, source, sink;
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
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].fi;
            if (level[v] == 0 and flow[u][v] < g[u][i].se) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return (level[sink]);
}

int DFS(int source, int sink, int Flow) {
    if (source == sink) return (Flow);
    for (int i = 0; i < g[source].size(); i++) {
        int v = g[source][i].fi;
        if (level[v] == level[source] + 1 and flow[source][v] < g[source][i].se) {
            int currFlow = min(Flow, g[source][i].se - flow[source][v]);
            int tmpFlow = DFS(v, sink, currFlow);
            if (tmpFlow > 0) {
                flow[source][v] += tmpFlow;
                flow[v][source] -= tmpFlow;
                return (tmpFlow);
            }
        }
    }
    return (0);
}

int main() {
    fileInput("nkflow");
    fast;
    cin >> n >> m >> source >> sink;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(make_pair(v, c));
        g[v].push_back(make_pair(u, 0));
    }

    int ans = 0;
    while (BFS(source, sink)) {
        while (int incFlow = DFS(source, sink, inf)) ans += incFlow;
    }

    cout << ans << endl;
    return (0);
}