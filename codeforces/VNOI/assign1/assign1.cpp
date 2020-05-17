#include <bits/stdc++.h>

#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

using namespace std;

int n, m;
int graph[N][N];
int minValue, maxValue;

bool BFS(int revGraph[N][N], int source, int sink, int parent[N], int maxCap) {
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
        for (int v = 0; v <= n + 1; v++) {
            if (revGraph[u][v] > 0 and revGraph[u][v] <= maxCap  and color[v] == false) {
                q.push(v);
                color[v] = 1;
                parent[v] = u;
            }
        }
    }
    return (false);
}

int fordFulkerson(int graph[N][N], int source, int sink) {
    int revGraph[N][N];
    for (int u = 0; u <= n + 1; u++) {
        for (int v = 0; v <= n + 1; v++) {
            revGraph[u][v] = graph[u][v];
        }
    }
    int maxFlow = 0;
    int parent[N];
    while (BFS(revGraph, source, sink, parent, 10)) {
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
    fileInput("assign1");
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            minValue = min(minValue, graph[i][j]);
            maxValue = max(maxValue, graph[i][j]);
        }
    }

    int source = 0;
    int sink = n + 1;
    int ans = inf;
    int l = minValue, r = maxValue;
    for (int i = 1; i <= n; i++) {
        graph[0][i] = 1;
        graph[n + 1][i] = 1;
    }
    for (int u = 0; u <= n + 1; u++) {
        for (int v = 0; v <= n + 1; v++) {
            cerr << graph[u][v] << " ";
        }
        cerr << endl;
    }
    cerr << fordFulkerson(graph, 0, n + 1);
    // do {
    //     int mid = (l + r) / 2;
    //     for (int i = 1; i <= n; i++) {
    //         graph[0][i] = mid;
    //         graph[n + 1][i] = mid;
    //     }
    //     int tmp = fordFulkerson(graph, 0, n + 1);
    //     cerr << tmp << endl;
    //     break;
    //     if (tmp) {
    //         ans = min(ans, mid);
    //         r = mid - 1;
    //     } else {
    //         l = mid + 1;
    //     }
    // } while (l <= r);
    
    cout << ans << endl;

    return (0);
}