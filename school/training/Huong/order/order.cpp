#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

int n, k;
int f[N][N], g[N][N];

int main() {
    fileInput("order");
    fast;
    cin >> n >> k;
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= n; i++) f[i][0] = 1, g[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j <= i) {
                f[i][j] = g[i - 1][j];
                g[i][j] = g[i][j - 1] + f[i][j];
            } else {
                f[i][j] = g[i - 1][j] - g[i][j - i - 1];
                g[i][j] = f[i][j] + g[i][j - 1];
            }
        }
    }
    cout << f[n][k];
    return (0);
}