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

int n, m, s, t, ans1 = 0, ans2 = 0, a, b;

int main() {
    fileInput("apple-and-orange");
    fast;
    cin >> s >> t;
    cin >> a >> b;
    cin >> n >> m;
    FOR(i, 1, n) {
        int x;
        cin >> x;
        if (x + a >= s and x + a <= t) ans1++;
    }
    FOR(i, 1, m) {
        int x;
        cin >> x;
        if (x + b >= s and x + b <= t) ans2++;
    }
    cout << ans1 << endl << ans2 << endl;
    return (0);
}