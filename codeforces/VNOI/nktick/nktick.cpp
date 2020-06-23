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
const int N = 6e4 + 7;

int n;
int t[N], r[N], f[N];

int main() {
    fileInput("nktick");
    fast;
    cin >> n;
    FOR(i, 1, n) {
        cin >> t[i];
    }
    FOR(i, 1, n - 1) {
        cin >> r[i];
    }
    f[1] = t[1];
    f[2] = min(f[1] + t[2], r[1]);
    FOR(i, 3, n) {
        f[i] = min(f[i - 1] + t[i], f[i - 2] + r[i - 1]);
    }
    cout << f[n] << endl;
    return (0);
}