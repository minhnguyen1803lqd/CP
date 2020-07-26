#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define vi vector < int >
#define ii pair < int, int >
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const ll inf = 1e18 + 7;
const int esf = 1e-9;
const int N = 1e2 + 7;

int p, q;
int x[N];

int Pow(int a, int b) {
    if (b == 0) return (1);
    if (b == 1) return (a);
    int tmp = Pow(a, b / 2);
    if (b % 2 == 0) return (tmp * tmp);
    return (tmp * tmp * a);
}

int main() {
    fileInput("BENUMBER");
    fast;
    cin >> p >> q;
    ll ans = inf;
    FOR(a1, 1, 9) {
        FOR(n, 1, 9) {
            if (p * Pow(10, n - 1) > LLONG_MAX / p) continue;
            ll tu = a1 * (p * Pow(10, n - 1) - q);
            ll mau = q * 10 - p;
            if (tu % mau == 0) {
                ll t = tu / mau;
                //cout << n << endl;
                //cout << a1 << " " << t << endl;
                ans = min(ans, a1 * Pow(10, n - 1) + t);
            }
        }
    }
    if (ans != inf) cout << ans << endl;
    else cout << -1 << endl;

    return (0);
}