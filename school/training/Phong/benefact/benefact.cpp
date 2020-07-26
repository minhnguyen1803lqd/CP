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
const int N = 5e4 + 7;

int query, n;
vector < ii > g[N];
int color[N], weight[N];

void BFS(int source, int &sink) {
    SET(color, 0);
    SET(weight, 0);
    queue < int > q;
    q.push(source);
    color[source] = 1;
    weight[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        REP(i, g[u].size()) {
            int v = g[u][i].fi;
            int w = g[u][i].se;
            if (!color[v]) {
                color[v] = 1;
                weight[v] = weight[u] + w;
                q.push(v);
            }
        }
    }
    sink = 0;
    weight[0] = 0;
    FOR(i, 1, n) {
        if (weight[i] > weight[sink]) {
            sink = i;
        }
    }
}

int main() {
    fileInput("benefact");
    fast;
    cin >> query;
    FOR(qq, 1, query) {
        cin >> n;
        FOR(i, 1, n - 1) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].pb(mp(v, w));
            g[v].pb(mp(u, w));
        }
        int source = 0, sink = 0;
        BFS(1, source);
        BFS(source, sink);
        cout << "source, sink: " << source << " " << sink << endl;
        int ans = 0;
        FOR(i, 1, n) {
            cout << i << " " << weight[i] << endl;
        }
        FOR(i, 1, n) {
            ans = max(ans, weight[i]);
        }
        cout << ans << endl;
        FOR(i, 1, n) {
            g[i].clear();
        }
    }
    return (0);
}