#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int esf = 1e-9;
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

vector < int > g[N];
int flow[N][N], cap[N][N];
int level[N];
double query, t, p, s, c;
int cnt = 0, source, sink;
point person[N], taxi[N];

int manhattanDistance(point a, point b) {
    return ((abs(a.x - b.x) + abs(a.y - b.y)) * 200);
}

void makeGraph() {
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= t; j++) {
            int tmp = manhattanDistance(person[i], taxi[j]);
            if (ceilf(tmp / s) <= c) {
                int u = person[i].id;
                int v = taxi[j].id;
                g[u].push_back(v);
                g[v].push_back(u);
                cap[u][v] = 1;
            }
        }
    }
    source = cnt + 1;
    sink = cnt + 2;
    for (int i = 1; i <= p; i++) {
        int v = person[i].id;
        g[source].push_back(v);
        g[v].push_back(source);
        cap[source][v] = 1;
    }
    for (int i = 1; i <= t; i++) {
        int v = taxi[i].id;
        g[v].push_back(sink);
        g[sink].push_back(v);
        cap[v][sink] = 1;
    }
    cnt += 2;
    return;
}

void deleteGraph() {
    for (int i = 1; i <= cnt; i++) {
        g[i].clear();
    }
    memset(flow, 0, sizeof(flow));
    memset(cap, 0, sizeof(cap));
}

bool BFS() {
    memset(level, 0, sizeof(level));
    queue < int > q;
    q.push(source);
    level[source] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (level[v] == 0 and flow[u][v] < cap[u][v]) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return (level[sink]);
}

int DFS(int u, int minFlow) {
    if (u == sink) return (minFlow);
    for (int i = 0; i < g[source].size(); i++) {
        int v = g[u][i];
        if (level[v] == level[u] + 1 and flow[u][v] < cap[u][i]) {
            int f = DFS(v, min(minFlow, cap[u][v] - flow[u][v]));
            if (f > 0) {
                flow[u][v] += f;
                flow[v][u] -= f;
                return (f);
            }
        }
    }
    return (0);
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
        deleteGraph();
        makeGraph();
        for (int i = 1; i <= cnt; i++) {
            for (int j = 1; j <= cnt; j++) {
                cerr << cap[i][j] << " ";
            }
            cerr << endl;
        }
        cerr << source << " " << sink << endl;
        int ans = 0;
        while (BFS()) {
            while (int incFlow = DFS(source, inf)) ans += incFlow;
        }

        cout << ans << endl;
    }

    return (0);
}