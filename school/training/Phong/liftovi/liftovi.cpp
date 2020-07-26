#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define ii pair < int, int >
#define fi first
#define se second

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e4 + 7;

int n, m;
int dist[N];
vector < ii > adj[N];
int t = 0;

void show() {
    cout << "curr time:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " " << dist[i] << endl;
    }
    cout << "--\n";
    return;
}

void dijkstra(int node) {
    priority_queue < ii, vector < ii >, greater < ii > > pq;
    pq.push(make_pair(node, 0));
    for (int i = 1; i <= n; i++) dist[i] = inf;
    dist[node] = 0;

    while (!pq.empty()) {
        int u = pq.top().fi, dist_u = pq.top().se;
        pq.pop();
        cout << "u, dist[u]: " << u << " " << dist[u] << endl;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].fi, w = adj[u][i].se;
            cout << "v, w(u, v): " << v << " " << w << endl;
            if (dist[v] > dist_u + w) {
                dist[v] = dist_u + w;
                pq.push(make_pair(v, dist[v]));
            }
        }
        show();
    }
}

main() {
    fileInput("liftovi");
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(make_pair(v, v - u));
        adj[v].push_back(make_pair(u, v - u));
    }
    dijkstra(1);
    
}