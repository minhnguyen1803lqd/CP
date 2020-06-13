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

int n, m, source, sink;
int graph[N][N], revGraph[N][N];

bool BFS(int graph[N][N], int source, int sink, int parent[N]) {
    int color[N];
    memset(color, 0, sizeof(color));
    queue < int > q;
    q.push(source);
    color[source] = 1;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == sink) return (true);
        FOR(v, 1, n) {
            if (graph[u][v] > 0 and !color[v]) {
                color[v] = 1;
                q.push(v);
                parent[v] = u;
            }
        }
    }
    return (false);
}

int fordFulkerson(int graph[N][N], int source, int sink) {
    int maxFlow = 0;
    int parent[N];

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            revGraph[i][j] = graph[i][j];
        }
    }

    while (BFS(revGraph, source, sink, parent)) {
        int pathFlow = inf;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, revGraph[u][v]);
        }
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            revGraph[u][v] -= pathFlow;
            revGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return (maxFlow);
}

int main() {
    fileInput("FordFulkerson");
    fast;
    cin >> n >> m >> source >> sink;
    FOR(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u][v] = c;
    }
    int ans = fordFulkerson(graph, source, sink);
    cout << ans << endl;
    return (0);
}