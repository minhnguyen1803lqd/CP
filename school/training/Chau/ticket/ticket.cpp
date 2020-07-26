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

int n, ans = 0;
int a[N], ok[N];

int main() {
    fileInput("ticket");
    fast;
    cin >> n;
    FOR(i, 1, n) {
        int x;
        cin >> a[i];
    }
    SET(ok, 1);
    FOR(i, 1, n - 1) {
        FOR(j, i + 1, n) {
            if (ok[i] and ok[j] and (a[i] % 3 + a[j] % 3) % 3 == 0) {
                ans++;
                ok[i] = ok[j] = 0;
            }
        }
    }
    cout << ans << endl;
    return (0);
}