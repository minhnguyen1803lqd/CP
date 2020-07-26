#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define vi vector < int >
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e2 + 7;

int n, m;
vi a, b;

int __lcm (int a, int b) {
    int tmp = __gcd(a, b);
    return (a * b / tmp);
}

int main() {
    fileInput("between-two-sets");
    fast;
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    REP(i, a.size()) cin >> a[i];
    REP(i, b.size()) cin >> b[i];
    int minA = inf, maxB = -inf;
    REP(i, a.size()) minA = min(minA, a[i]);
    REP(i, b.size()) maxB = max(maxB, b[i]);
    if (minA > maxB) {
        cout << 0 << endl;
        return (0);
    }
    int l = a[0];
    FOR(i, 1, a.size() - 1) {
        l = __lcm(l, a[i]);
    }
    int r = b[0];
    FOR(i, 1, b.size() - 1) {
        r = __gcd(r, b[i]);
    }
    cout << l << " " << r << endl;
    int ans = 0;
    FOR(i, l, r) {
        if (i % l == 0 and r % i == 0) ans++;
    }
    cout << ans << endl;
    return (0);
}