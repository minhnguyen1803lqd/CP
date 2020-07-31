#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e3 + 7;

int n, a[N][N];
int kt[N], mem[N], pick[N];

int ketqua(int s, int d) {
    if (d == n) return (1);
    if (kt[s]) return (mem[s]);
    int ret = inf;
    kt[s] = 1;
    for (int c = 0; c < n; c++) {
        if (c == d) continue;
        if ((s & (1 << c)) == 0) {
            kt[s] = 1;
            int tich = a[d][c] * ketqua((s | (1 << c)), d + 1);
            if (tich < 0) continue;
            if (tich < ret) {
                pick[s] = a[d][c];
                ret = tich;
            }
        }
    }
    mem[s] = ret;
    return (ret);
}

main() {
    fileInput("bond");
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    memset(kt, 0, sizeof(kt));
    memset(mem, inf, sizeof(mem));
    int ans = ketqua(0, 0);
    for (int i = 0; i <= pow(2, 6); i++) {
        cout << pick[i] << "\n";
    }
    cout << "--\n";
    cout << ans << endl;
}