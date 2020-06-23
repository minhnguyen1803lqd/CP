#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e3 + 7;

int n, m;
int a[N][N], f[N][N];
int ans = -inf;

int main() {
    fileInput("qbmax");
    fast;
    cin >> n >> m;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> a[i][j];
        }
    }
    SET(f, 0);
    FOR(i, 1, n) {
        f[i][1] = a[i][1];
    }
    FOR(i, 1, m) {
        f[0][i] = -inf;
        f[n + 1][i] = -inf;
    }
    FOR(j, 2, m) {
        FOR(i, 1, n) {
            f[i][j] = f[i - 1][j - 1] + a[i][j];
            f[i][j] = max(f[i][j], f[i][j - 1] + a[i][j]);
            f[i][j] = max(f[i][j], f[i + 1][j - 1] + a[i][j]);
        }
    }
    FOR(i, 1, n) ans = max(ans, f[i][m]);
    cout << ans << endl;
    return (0);
}