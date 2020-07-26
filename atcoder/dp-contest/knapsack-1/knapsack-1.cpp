#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 7;

int n, w;
int a[N], b[N];
long long f[107][N];

main() {
    fileInput("knapsack-1");
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][0] = 0;
    for (int j = 1; j <= w; j++) f[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i] <= j) f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + b[i]);
            else f[i][j] = f[i - 1][j];
        }
    }
    cout << f[n][w] << endl;
}