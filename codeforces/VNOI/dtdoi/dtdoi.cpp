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

int n, s;
int a[N], f[N][N];

int main() {
    fileInput("dtdoi");
    fast;
    cin >> n >> s;
    FOR(i, 1, n) {
        cin >> a[i];
    }
    int maxVal = -inf, sum = 0, ans = 0;
    FOR(i, 1, n) maxVal = max(maxVal, a[i]), sum += a[i];
    while (s >= 2 * sum) s -= maxVal, ans ++;
    sort(a + 1, a + 1 + n);
    FOR(i, 1, s) {
        f[1][i] = i;
    }
    FOR(i, 2, n) {
        FOR(j, 1, s) {
            if (a[i] > j) {
                f[i][j] = f[i - 1][j];
            } else {
                f[i][j] = min(f[i - 1][j], f[i][j - a[i]] + 1);
            }
        }
    }
    cout << f[n][s] + ans << endl;
    return (0);
}