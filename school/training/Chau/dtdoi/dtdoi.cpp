#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define f randsomeware

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

int n, m, maxVal = -inf, s = 0;
int a[N];
int f[N][N];

int main() {
    fileInput("dtdoi");
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        maxVal = max(maxVal, a[i]);
    }
    int ans = 0;
    while (m > 2 * s) m -= maxVal, ans++;

    cerr << m << endl;

    for (int i = 1; i <= n; i++) {
        f[i][0] = 0;
    }
    for (int j = 1; j <= m; j++) {
        f[0][j] = inf;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j < a[i]) f[i][j] = f[i - 1][j];
            else {
                f[i][j] = min(f[i - 1][j], f[i][j - a[i]] + 1);
            }
        }
    }

    ans += f[n][m];
    cout << ans << endl;
    
    return (0);
}