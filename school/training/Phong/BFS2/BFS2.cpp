#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e5 + 7;

int n, m;
vector < int > g[N];
int parent[N], dis[N];

void BFS(int source, int &sink) {
    SET(parent, 0);
    SET(dis, 0);

    parent[source] = -1;
    dis[source] = 1;
    queue < int > q;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        REP(i, g[u].size()) {
            int v = g[u][i];
            if (!parent[v]) {
                parent[v] = u;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    int maxDis = -inf, u;
    FOR(i, 1, n) {
        if (dis[i] > maxDis) {
            maxDis = dis[i];
            u = i;
        }
    }
    sink = u;
}

int main() {
    fileInput("BFS2");
    fast;
    cin >> n;
    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int source, sink;
    BFS(1, source);
    BFS(source, sink);

    int radious = 0;
    FOR(i, 1, n) radious = max(radious, dis[i]);
    cout << radious << endl;
    vector < int > ans;
    if (radious % 2 == 0) {
        for (int u = sink; u != -1; u = parent[u]) {
            if (dis[u] == radious / 2 or dis[u] == radious / 2 + 1) {
                ans.pb(u);
            }
        }
    } else {
        for (int u = sink; u != -1; u = parent[u]) {
            if (dis[u] == radious / 2 + 1) {
                ans.pb(u);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    return (0);
}