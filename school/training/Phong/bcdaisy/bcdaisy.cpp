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
const int N = 1e4 + 7;

int n, m;
vector < int > g[N];
int color[N];

void DFS(int u) {
    color[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!color[v]) {
            DFS(v);
        }
    }
}

int main() {
    fileInput("bcdaisy");
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(color, 0, sizeof(color));
    DFS(1);
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) cout << i << "\n", flag = 1;
    }
    if (!flag) cout << 0 << endl;
    return (0);
}