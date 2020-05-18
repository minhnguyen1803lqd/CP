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

int n, source, sink;
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
        if (u == sink) return(true);
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] > 0 and color[v] == 0) {
                color[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return (false);
}

int fordFulkerson(int graph[N][N], int source, int sink) {
    int maxFlow = 0;
    int parent[N];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
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
    fileInput("pothole");
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            graph[i][x] += 1;
        }
    }
    source = 1;
    sink = n;

    int res = fordFulkerson(graph, source, sink);
    cout << res << endl;
    return (0);
}