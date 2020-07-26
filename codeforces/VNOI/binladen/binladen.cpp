#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define vi vector < int >
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
vector < ii > g[N];
ll dis[N];

int dijks(int startNode) {
    SET(dis, inf);
    priority_queue < ii, vector < ii >, greater < ii > > pq;
    pq.push(mp(startNode, 0));
    dis[startNode] = 0;
    while (!pq.empty()) {
        int u = pq.top().fi;
        int dis_u = pq.top().se;
        pq.pop();
        REP(i, g[u].size()) {
            int v = g[u][i].fi;
            int w = g[u][i].se;
            if (dis[v] > dis_u + w) {
                dis[v] = dis_u + w;
                pq.push(mp(v, dis[v]));
            }
        }
    }
    return (dis[(m + 1) * n]);
}

int main() {
    fileInput("binladen");
    fast;
    cin >> m >> n;
    int u = n + 1;
    int u1 = n + 1;
    FOR(k, 1, 2 * m) {
        if (k % 2) {
            FOR(i, 1, n) {
                int w;
                cin >> w;
                int v = u - n;
                g[u].pb(mp(v, w));
                g[v].pb(mp(u, w));
                u++;
            }
        } else {
            FOR(i, 1, n - 1) {
                int v1 = u1 + 1;
                int w;
                cin >> w;
                g[u1].pb(mp(v1, w));
                g[v1].pb(mp(u1, w));
                u1++;
            }
            u1++;
        }
    }
    int ans = inf;
    FOR(i, 1, n) {
        int res = dijks(i);
        ans = min(ans, res);
    }
    cout << ans << endl;

    return (0);
}