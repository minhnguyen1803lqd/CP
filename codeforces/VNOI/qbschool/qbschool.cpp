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
const int N = 1e4 + 7;

int n, m;
vector < ii > g[N];
ll dis[N], f[N];

void dijks(int startNode) {
    priority_queue < ii, vector < ii >, greater < ii > > pq;
    pq.push(make_pair(startNode, 0));
    SET(dis, inf);
    SET(f, 0);
    dis[startNode] = 0;
    f[startNode] = 1;

    while (!pq.empty()) {
        int u = pq.top().fi;
        int dis_u = pq.top().se;
        pq.pop();
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].fi;
            int w = g[u][i].se;
            if (dis[v] == dis_u + w) {
                f[v] += f[u];
            } else if (dis[v] > dis_u + w) {
                dis[v] = dis_u + w;
                f[v] = f[u];
                pq.push(mp(v, dis[v]));
            }
        }
    }
    cout << dis[n] << " " << f[n] << endl;
}

int main() {
    fileInput("qbschool");
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int k, u, v, w;
        cin >> k >> u >> v >> w;
        if (k == 1) g[u].push_back(make_pair(v, w));
        else {
            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));
        }
    }

    dijks(1);

    return (0);
}