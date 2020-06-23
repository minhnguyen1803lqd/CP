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
const int N = 1e4 + 7;

int n, m;
int a[N][N], f[N][N];

int main() {
    fileInput("qbsquare");
    fast;
    cin >> n >> m;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> a[i][j];
        }
    }
    FOR(i, 1, n) {
        f[i][1] = 1;
    }
    FOR(i, 1, m) {
        f[1][i] = 1;
    }
    FOR(i, 2, n) {
        FOR(j, 2, m) {
            int s = a[i][j] + a[i - 1][j - 1] + a[i][j - 1] + a[i - 1][j];
            if (s == 4 or s == 0) {
                f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
            } else {
                f[i][j] = 1;
            }
        }
    }
    int ans = -inf;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return (0);
}