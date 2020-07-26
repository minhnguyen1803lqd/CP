//  TODO: solve this problem
#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define int long long
#define ii pair < int, int >
#define fi first
#define se second

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 3e4 + 7;

int n, m;
vector < ii > adj[N];
int d[N], parent[N];

void dijkstra(int startNode) {
    priority_queue < ii, vector < ii >, greater < ii > > pq;
    pq.push(make_pair(startNode, 0));
    memset(d, inf, sizeof(d));
    d[startNode] = 0;
    parent[startNode] = -1;

    while (!pq.empty()) {
        int u = pq.top().fi, l = pq.top().se;
        pq.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].fi, w = adj[u][i].se;
            if (d[v] > l + w) {
                d[v] = l + w;
                parent[v] = u;
                pq.push(make_pair(v, d[v]));
            }
        }
    }
    deque < int > path;
    int inPath[N];
    vector < int > ans;
    memset(inPath, 0, sizeof(inPath));
    int u = n;
    while (u != -1) {
        inPath[u] = 1;
        path.push_front(u);
        u = parent[u];
    }
    for (int i = 1; i <= n; i++) {
        if (!inPath[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}

main() {
    fileInput("centre28");
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    dijkstra(1);
}