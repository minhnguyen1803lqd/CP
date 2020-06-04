#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 607;

struct point {
    double x, y;
    int id;
    void init(double _x, double _y) {
        x = _x;
        y = _y;
    }
    void show() {
        cout << "point(" << x << "; " << y << ")\n";
    }
};

double query, t, p, s, c;
int cnt = 0, source, sink;
point person[N], taxi[N];
int graph[N][N], revGraph[N][N];

int manhattanDistance(point a, point b) {
    return ((abs(a.x - b.x) + abs(a.y - b.y)) * 200);
}

void makeGraph() {
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= t; j++) {
            int tmp = manhattanDistance(person[i], taxi[j]);
            if (ceilf(tmp / s) <= c) {
                graph[person[i].id][taxi[j].id] = 1;
                graph[taxi[j].id][person[i].id] = 1;
            }
        }
    }
    source = cnt + 1;
    sink = cnt + 2;
    for (int i = 1; i <= p; i++) {
        graph[source][person[i].id] = 1;
    }
    for (int i = 1; i <= t; i++) {
        graph[taxi[i].id][sink] = 1;
    }
    cnt += 2;
    return;
}

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
        for (int v = 1; v <= cnt; v++) {
            if (graph[u][v] > 0 and color[v] == 0) {
                q.push(v);
                color[v] = 1;
                parent[v] = u;
            }
        }
    }
    return (false);
}

int fordFulkerson(int graph[N][N], int source, int sink) {
    int maxFlow = 0;
    int parent[N];
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= cnt; j++) {
            revGraph[i][j] = graph[i][j];
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

int main() {
    fileInput("taxi");
    fast;
    
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cnt = 0;
        cin >> p >> t >> s >> c;
        for (int i = 1; i <= p; i++) {
            int x, y;
            cin >> x >> y;
            person[i].id = ++cnt;
            person[i].init(x, y);
        }
        for (int i = 1; i <= t; i++) {
            int x, y;
            cin >> x >> y;
            taxi[i].id = ++cnt;
            taxi[i].init(x, y);
        }
        makeGraph();
        int ans = fordFulkerson(graph, source, sink);
        cout << ans << endl;
    }

    return (0);
}