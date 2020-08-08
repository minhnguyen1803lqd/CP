#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define ii pair < int, int >
#define fi first
#define se second

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 5e3 + 7;

int n, m;
ll dis[N], f[N];
vector < ii > adj[N];

ll dijsktra(int S) {
    priority_queue < ii, vector < ii >, greater < ii > > pq;
    pq.push(make_pair(S, 0));
    for (int i = 1; i <= n; ++i) dis[i] = inf, f[i] = 0;
    dis[S] = 0;
    f[S] = 1;

    while (!pq.empty()) {
        int u = pq.top().fi, dis_u = pq.top().se;
        pq.pop();
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].fi, w = adj[u][i].se;
            if (dis[v] == dis_u + w) {
                f[v] += f[u];
            } else  if (dis[v] > dis_u + w) {
                dis[v] = dis[u] + w;
                f[v] = f[u];
                pq.push(make_pair(v, dis[v]));
            }
        }
    }
    return (dis[n]);
}

main() {
    fileInput("qbschool");
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int k, u, v, w;
        cin >> k >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        if (k == 2) adj[v].push_back(make_pair(u, w));
    }
    ll ans = dijsktra(1);
    cout << ans << " " << f[n] << endl;
}