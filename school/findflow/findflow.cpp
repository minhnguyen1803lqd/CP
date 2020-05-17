#include <bits/stdc++.h>

#define ii pair<int, int>
#define fi first
#define se second
#define fileInput(problemName) freopen((string(problemName) + ".inp").c_str(), "r", stdin); freopen((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL);

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

using namespace std;

int n, m, source, sink;
int graph[N][N], revGraph[N][N];

bool BFS(int revGraph[N][N], int source, int sink, int parent[N])
{
    int color[N];
    memset(color, 0, sizeof(color));
    parent[source] = -1;
    queue<int> q;
    q.push(source);
    color[source] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == sink) {
            return (true);
        }
        for (int v = 1; v <= n; v++) {
            if (revGraph[u][v] > 0 and !color[v]) {
                q.push(v);
                color[v] = 1;
                parent[v] = u;
            }
        }
    }
    return (false);
}

int fordFulkerson(int graph[N][N], int source, int sink) {
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            revGraph[u][v] = graph[u][v];
        }
    }
    int parent[N];
    int maxFlow = 0;
    while (BFS(revGraph, source, sink, parent)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, revGraph[u][v]);
        }
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            revGraph[u][v] -= pathFlow;
            revGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return (maxFlow);
}

int main()
{
    fileInput("findflow");
    fast;

    memset(graph, 0, sizeof(graph));
    memset(revGraph, 0, sizeof(revGraph));
    n = 90;
    cin >> m;
    source = int('S');
    sink = int('T');
    for (int i = 1; i <= m; i++) {
        char u, v;
        int c;
        cin >> u >> v >> c;
        graph[int(u)][int(v)] = c;
    }

    int ans = fordFulkerson(graph, source, sink);
    cout << ans << endl;

    return (0);
}