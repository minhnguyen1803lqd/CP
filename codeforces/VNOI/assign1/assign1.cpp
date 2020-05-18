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
int graph[N][N], revGraph[N][N];
int w[N][N];

bool BFS(int graph[N][N], int source, int sink, int parent[N], int maxCap) {
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
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] > 0 and w[u][v] > 0 and w[u][v] <= maxCap and !color[v]) {
                q.push(v);
                color[v] = 1;
                parent[v] = u;
            }
        }
    }
    return (false);
}

int fordFulkerson(int graph[N][N], int source, int sink, int maxCap) {
    int maxFlow = 0;
    int parent[N];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            revGraph[i][j] = graph[i][j];
        }
    }
    while (BFS(revGraph, source, sink, parent, maxCap)) {
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
    cout << maxFlow << ' ';
    return (maxFlow == n - 2);
}

int main() {
    fileInput("assign1");
    fast;
    cin >> n;
    int maxCap = -inf, mincap = inf;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
            maxCap = max(maxCap, w[i][j]);
            mincap = min(mincap, w[i][j]);
        }
    }
    source = n + 1;
    sink = n + 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        graph[source][i] = 1;
        graph[i][sink] = 1;
    }

    n += 2;

    int l = mincap, r = maxCap;
    int ans = inf;
    while (l <= r) {
        int mid = (l + r) / 2;
        int res = fordFulkerson(graph, source, sink, mid);
        if (res == 0) {
            l = mid + 1;
        } else {
            ans = min(ans, mid);
            r = mid - 1;
        }
    }

    cout << ans << endl;

    return (0);
}