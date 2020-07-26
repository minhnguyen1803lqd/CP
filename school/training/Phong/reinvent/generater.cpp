#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 7;

int n, m, k;
int edge[N][N];
int inx[N];

int main() {
    srand(time(NULL));
    freopen ("reinvent.inp", "w", stdout);
    memset(edge, 0, sizeof(edge));
    n = rand() % 10 + 5;
    m = rand() % n + 1;
    do {
        k = rand() % n + 1;
    } while (k < 1);
    for (int i = 1; i <= n; i++) edge[i][i] = 1;
    cout << n << " " << m << " " << k << endl;
    for (int i = 1; i <= m; i++) {
        int u, v;
        do {
            u = rand() % n + 1;
            v = rand() % n + 1;
        } while (edge[u][v] == 1 or edge[v][u] == 1);
        edge[u][v] = edge[v][u] = 1;
        cout << u << " " << v << endl;
    }
    memset(inx, 0, sizeof(inx));
    for (int i = 1; i <= k; i++) {
        int x;
        do {
            x = rand() % n + 1;
        } while (inx[x] == 1);
        inx[x] = 1;
        cout << x << " ";
    }
    return (0);
}