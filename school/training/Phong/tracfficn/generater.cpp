#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;

int n, m, k, source, sink;
int g[N][N], f[N][N];

int main() {
    srand(time(NULL));
    freopen ("tracfficn.inp", "w", stdout);
    
    n = 1000;
    m = rand() % 1000 + 1;
    k = rand () % n + 1;
    source = rand() % n + 1;
    do {
        sink = rand() % n + 1;
    } while (source == sink);
    cout << n << " " << m << " " << k << " " << source << " " << sink << endl;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        do {
            u = rand() % n + 1;
            v = rand() % n + 1;
        } while (g[u][v]);
        g[u][v] = 1;
        cout << u << " " << v << " " << rand() % 1000 + 1 << endl;
    }
    for (int i = 1; i <= k; ++i) {
        int u, v, w;
        do {
            u = rand() % n + 1;
            v = rand() % n + 1;
        } while (f[u][v]);
        f[u][v] = f[v][u] = 1;
        w = rand() % 1000 + 1;
        cout << u << " " << v << " " << w << endl;
    }


    return (0);
}