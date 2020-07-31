#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;

int n, m, k, s;
int ok[N][N], is[N], val[N];

bool check() {
    for (int i = 1; i <= n; ++i) {
        if (!val[i]) return (true);
    }
    return (false);
}

int main() {
    srand(time(NULL));
    freopen ("fairnt.inp", "w", stdout);
    n = rand() % 10 + 1;
    m = rand() % n + 1;
    if (m < n / 2) m += (n / 2);
    k = rand() % min(5, n) + 1;
    s = rand() % k + 1;
    if (s == 1) s += k / 2;
    cout << n << " " << m << " " << k << " " << s << endl;
    for (int i = 1; i <= k; i++) is[i] = 0;
    while (check()) {
        int id = rand() % n + 1;
        for (int i = 1; i <= k; ++i) 
            if (!is[i]) is[i] = 1, val[id] = i;
            else val[id] = rand() % k + 1;
    }
    for (int i = 1; i <= n; ++i) cout << val[i] << " "; cout << endl;
    for (int i = 1; i <= n; i++) ok[i][i] = 1;
    for (int i = 1; i <= m; i++) {
        int u, v;
        do {
            u = rand() % n + 1;
            v = rand() % n + 1;
        } while (ok[u][v]);
        ok[u][v] = 1;
        ok[v][u] = 1;
        cout << u << " " << v << endl;
    }
    return (0);
}