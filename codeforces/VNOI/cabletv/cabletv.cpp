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

const int inf = 1e5 + 7;
const int esf = 1e-9;
const int N = 1e3 + 7;

struct Graph {
    int n, m;
    int graph[N][N], revGraph[N][N];

    ii inpProcess(string s) {
        return (ii(int(s[1]) - int('0'), int(s[3]) - int('0')));
    }

    void init() {
        cin >> n >> m;
        memset(graph, 0, sizeof(graph));
        FOR(i, 1, m) {
            string s;
            cin >> s;
            ii tmp = inpProcess(s);
            graph[2 * tmp.fi + 1][2 * tmp.se] = inf;
            graph[2 * tmp.se + 1][2 * tmp.fi] = inf;
        }
        REP(i, n) {
            graph[2 * i][2 * i + 1] = 1;
        }
    }

    bool BFS(int graph[N][N], int source, int sink, int parent[N]) {
        int color[N];
        memset(color, 0, sizeof(color));
        queue < int > q;
        q.push(source);
        parent[source] = -1;
        color[source] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == sink) return (true);
            REP(v, 2 * n) {
                if (graph[u][v] and !color[v]) {
                    q.push(v);
                    parent[v] = u;
                    color[v] = 1;
                }
            }
        }
        return (false);
    }

    int FordFulkerson(int graph[N][N], int source, int sink) {
        REP(i, 2 * n) {
            REP(j, 2 * n) {
                revGraph[i][j] = graph[i][j];
            }
        }
        int parent[N];
        int maxFlow = 0;
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

    void process() {
        cout << "n, m: " << n << " " << m << endl;
        int ans = 0;
        REP(i, 2 * n) {
            REP(j, 2 * n) {
                if (i != j and i + 1 != j and i != j + 1) {
                    cout << "source, sink: " << i << " " << j << endl;
                    int res = FordFulkerson(graph, i, j);
                    cout << "maxFlow: " << res << endl;
                    ans = max(ans, res);
                }
            }
        }
        cout << ans << endl;
    }
};

int query;

int main() {
    fileInput("cabletv");
    fast;
    cin >> query;
    FOR(qq, 1, query) {
        Graph newG;
        newG.init();
        newG.process();
    }
    return (0);
}