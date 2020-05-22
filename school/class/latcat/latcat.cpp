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

struct edge {
    int u, v, cap, flow;
    void show() {
        cout << u << " " << v << endl;
        cout << flow << " " << cap << endl;
        return;
    }
};

int n, m, source, sink;
int graph[N][N], revGraph[N][N];
edge edgeList[N];
vector < int > cutSet[N];

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
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            revGraph[u][v] = graph[u][v];
        }
    }

    while (BFS(revGraph, source, sink, parent)) {
        int pathFlow = INT_MAX;
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

void mincutBFS() {
    int color[N];
    memset(color, 0, sizeof(color));
    queue < int > q;
    q.push(source);
    color[source] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++) {
            if (revGraph[v][u] < graph[u][v] and color[v] == 0) {
                color[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cutSet[color[i]].push_back(i);
    }
    return;
}

int main() {
    fileInput("latcat");
    fast;

    cin >> n >> m >> source >> sink;
    for (int i = 1; i <= m; i++) {
        edge newEdge;
        int u, v, c;
        cin >> u >> v >> c;
        newEdge.u = u;
        newEdge.v = v;
        newEdge.cap = c;
        newEdge.flow = 0;
        graph[u][v] = c;
        edgeList[i] = newEdge;
    }
    cout << "graph: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    int res = fordFulkerson(graph, source, sink);
    cout << res << endl;
    cout << "revGraph: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << revGraph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    mincutBFS();
    
    for (int i = 0; i < cutSet[1].size(); i++) {
        for (int j = 0; j < cutSet[0].size(); j++) {
            int u = cutSet[1][i];
            int v = cutSet[0][j];
            if (graph[u][v] > 0) {
                cout << u << " " << v << endl;
            }
        }
    }

    return (0);
}