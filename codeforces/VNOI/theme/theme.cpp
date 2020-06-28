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

int n;
vector < int > a;

int main() {
    fileInput("theme");
    fast;
    cin >> n;
    a.resize(n + 2);
    FOR(i, 1, n) cin >> a[i];
    int ans = 0;
    FOR(i, 5, n - 5) {
        int len = 1;
        REV(j, n, i - 1) {
            if (a[j - i] - a[j - i - 1] == a[j] - a[j - 1]) {
                len++;
                if (len > ans) ans = len;
                if (len == i) break;
            } else {
                len = 1;
            }
        }
    }
    if (ans < 5) cout << 0 << endl;
    else cout << ans << endl;
    return (0);
}