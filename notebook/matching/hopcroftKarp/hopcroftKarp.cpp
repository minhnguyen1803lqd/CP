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

int n1, n2, m, NIL;
int dis[N];
int mX[N], mY[N];
vector < int > g[N];

bool BFS() {
    queue < int > q;
    FOR(u, 1, n1) {
        if (mX[u] == NIL) {
            dis[u] = 0;
            q.push(u);
        } else {
            dis[u] = inf;
        }
    }
    dis[NIL] = inf;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        REP(i, g[u].size()) {
            int v = g[u][i];
            if (dis[mY[v]] == inf) {
                dis[mY[v]] = dis[u] + 1;
                q.push(mY[v]);
            }
        }
    }
    return (dis[NIL] != inf);
}

bool DFS(int u) {
    if (u != NIL) {
        REP(i, g[u].size()) {
            int v = g[u][i];
            if (dis[mY[v]] == dis[u] + 1) {
                if (DFS(mY[v])) {
                    mY[v] = u;
                    mX[u] = v;
                    return (true);
                }
            }
        }
        dis[u] = inf;
        return (false);
    }
    return (true);
}

int hopcroftKarp() {
    SET(mX, NIL);
    SET(mY, NIL);
    int matching = 0;
    while (BFS()) {
        FOR(u, 1, n1) {
            if (mX[u] == NIL) {
                if (DFS(u)) {
                    matching += 1;
                }
            }
        }
    }
    return (matching);
}

int main() {
    fileInput("hopcroftKarp");
    fast;
    cin >> n1 >> n2 >> m;
    NIL = 0;
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }   
    int ans = hopcroftKarp();
    cout << ans << endl;
    return (0);
}