#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 5e5 + 7;

int n, k, ans = inf;
vector < ii > g[N];
int color[N], parent[N];
int infected[N];

void DFS(int u) {
    color[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].fi;
        if (!color[v]) {
            parent[v] = u;
            DFS(v);
        }
    }
}

int main() {
    fileInput("kamp01");
    fast;
    cin >> n >> k;
    for (int i =1 ; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    for (int i = 1; i <= k; i++) {
        cin >> infected[i];
    }

    for (int source = 1; source <= n; source++) {
        memset(color, 0, sizeof(color));
        memset(parent, 0, sizeof(parent));
        parent[source] = -1;
        DFS(source);
        int tmp = 0;
        for (int h = 1; h <= k; h++) {
            int v = infected[h];
            while (v != source) {
                int u = parent[v];
                for (int i = 0; i < g[u].size(); i++) {
                    if (g[u][i].fi == v) {
                        tmp += g[u][i].se;
                    }
                }
                v = parent[v];
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;

    return (0);
}