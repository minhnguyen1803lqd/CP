#include <bits/stdc++.h>

#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, l, r) for (int i = l; i >= r; i--)
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define fr front
#define mp make_pair
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define graph vector < ii > g;

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

using namespace std;

int n, m, source, sink;
graph g[N];
int f[N][N];

void input(int &n, int &m, int &source, int &sink, graph g[N]) {
    cin >> n >> m >> source >> sink;
    FOR(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(mp(v, c));
    }
}

bool BFS(int startNode, int endNode, graph g[N]) {
    int color[N];
    memset(color, 0, sizeof(color));
    queue < int > q;
    q.push(startNode);
    color[startNode] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == endNode) {
            return (true);
        }
        REP(i, g[u].size()) {
            v = g[u][i].fi;
            if (!color[v]) {
                color[v] = 1;
                q.push(v);
            }
        }
    }
    return (false);
}

void fordFulkerson(int v, int source, int sink, graph g[N]) {
    FOR(u, 1, n) {
        FOR(v, 1, n) {
            f[u][v] = 0;
        }
    }
    while (BFS(source, sink, g)) {
        
    }
}

void solve() {
    int res = fordFulkerson(n, source, sink, graph);
    cout << res << endl;
}

int main() {
    fileInput("nkflow");
    fast;

    input(n, m, source, sink, g);
    solve();    

    return(0);
}