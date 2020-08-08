#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".ans").c_str(), "w", stdout);
#define ll long long
#define ii pair < int, int >
#define iii pair < ii, int >
#define fi first
#define se second
#define ignore somethingshit

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e3 + 7;

int n, m, k, source, sink;
vector < ii > adj[N];
int dis[N];
int ignore[N][N];

int dijsktra(int source, int sink, vector < ii > adj[N]) {
    for (int i = 1; i <= n; ++i) dis[i] = inf;
    priority_queue < ii, vector < ii >, greater < ii > > pq;
    pq.push(make_pair(source, 0));
    dis[source] = 0;

    while (!pq.empty()) {   
        int u = pq.top().fi, dis_u = pq.top().se;
        pq.pop();
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].fi, w = adj[u][i].se;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push(make_pair(v, dis[v]));
            }
        }
    }
    return (dis[sink]);
}

main() {
    fileInput("tracfficn");
    cin >> n >> m >> k >> source >> sink;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, inf));
    }
    int ans = dijsktra(source, sink, adj);
    if (ans == inf) {
        cout << -1 << endl;
        exit(0);
    }
    for (int qq = 1; qq <= k; ++qq) {
        int u, v, w;
        cin >> u >> v >> w;
        int tmp1 = 0, tmp2 = 0;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
        int res = dijsktra(source, sink, adj);
        //cout << "bug res: " << res << endl;
        ans = min(ans, res);
        adj[u].pop_back();
        adj[v].pop_back(); 
        
    }
    cout << ans << endl; 
}
