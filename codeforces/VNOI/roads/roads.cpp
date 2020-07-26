#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

struct node {
    int v, w, c;
    node(int _v, int _w, int _c) {
        v = _v;
        c = _c;
        w = _w;
    }
};

int query, n, m, k;
vector < node > adj[N];
int d[N];

bool operator > (node a, node b) {
    return (a.c > b.c);
}

int dijkstra() {
    priority_queue < node, vector < node >, greater < node > > pq;
    pq.push(node(1, 0, 0));
    for (int i = 1; i <= n; i++) d[i] = inf;

    while (!pq.empty()) {
        int u = pq.top().v, l = pq.top().w, cost = pq.top().c;
        pq.pop();
        if (l >= d[u]) continue;
        d[u] = l;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v, w = adj[u][i].w, c = adj[u][i].c;
            if (cost + c > k) continue;
            pq.push(node(v, l + w, cost + c));
        }
    }
    if (d[n] == inf) return (-1);
    return (d[n]);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen ("roads.inp", "r", stdin);
    freopen ("roads.out", "w", stdout);
    
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> k >> n >> m;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v, w, c;
            cin >> u >> v >> w >> c;
            adj[u].push_back(node(v, w, c));
        }
        int res = dijkstra();
        cout << res << endl;
    }
}