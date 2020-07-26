#include <bits/stdc++.h>

#define ll long long
#define vi vector < int >

using namespace std;

const int N = 1e5 + 7;

int n, m, k;
int x[N];
vi g[N];

void BFS() {
    queue < int > q;
    for (int i = 1; i <= k; i++) q.push(x[i]), color[x[i]] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!color[v]) {
                q.push(v);
                color[v] = 1;
            }
        }
    }
    
}

int main() {
    freopen("reinvent.inp", "r", stdin);
    freopen("reinvent.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
    }
    return (0);
}