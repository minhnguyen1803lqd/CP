#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 7;

int n, a[N][10], f[N][10];

main() {
    fileInput("vacation");
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 3; i++) f[1][i] = a[1][i];
    for (int i = 2; i <= n; i++) {
        f[i][1] = max(f[i - 1][2], f[i - 1][3]) + a[i][1];
        f[i][2] = max(f[i - 1][1], f[i - 1][3]) + a[i][2];
        f[i][3] = max(f[i - 1][1], f[i - 1][2]) + a[i][3];
    }
    cout << max(max(f[n][1], f[n][2]), f[n][3]);
}