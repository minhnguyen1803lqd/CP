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

void BFS(int source) {
    int color[N], dis[N];
    SET(color, 0);
    SET(dis, -1);

    queue < int > q;
    q.push(source);
    color[source] = 1;
    dis[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        REP(i, g[u].size()) {
            int v = g[u][i];
            if (!color[v]) {
                color[v] = 1;
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
    FOR(i, 1, n) {
        cout << dis[i] << endl;
    }
}

int main() {
    fileInput("BFS1");
    fast;
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    BFS(1);

    return (0);
}