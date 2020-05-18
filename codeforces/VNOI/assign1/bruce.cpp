#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".ans").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

int n, source, sink;
int graph[N][N], revGraph[N][N], w[N][N];

bool BFS(int graph[N][N], int source, int sink, int parent[N], int time) {
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
            if (graph[u][v] > 0 and w[u][v] <= time and color[v] == 0) {
                color[v] = 1;
                q.push(v);
                parent[v] = u;
            }
        }
    }
    return (false);
}

int fordFulkerson(int graph[N][N], int source, int sink, int time) {
    int parent[N];
    int maxFlow = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            revGraph[i][j] = graph[i][j];
        }
    }

    while (BFS(revGraph, source, sink, parent, time)) {
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
    return (maxFlow == (n - 2));
}

int main() {
    fileInput("assign1");
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
            graph[i][j] = 1;
        }
    }
    source = n + 1;
    sink = n + 2;
    for (int i = 1; i <= n; i++) {
        graph[source][i] = 1;
        w[source][i] = 0;
        graph[i][sink] = 1;
        w[i][sink] = 0;
    }
    n += 2;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << w[i][j] << " ";
        }
        cout << endl;
    }

    int res = fordFulkerson(graph, source, sink, 1);
    cout << res << endl;

    return(0);
}