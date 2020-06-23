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
const int N = 1e5 + 7;
const int MOD = 14062008;

int n, k;
ll f[N], a[N];

int main() {
    fileInput("vsteps");
    fast;
    cin >> n >> k;
    SET(a, 0);
    FOR(i, 1, k) {
        int tmp;
        cin >> tmp;
        a[tmp] = 1;
    }

    f[0] = 0;
    f[1] = 1;
    FOR(i, 2, n) {
        if (a[i]) {
            f[i] = 0;
        } else {
            f[i] = (f[i - 1] + f[i - 2]) % MOD;
        }
    }

    cout << f[n] << endl;

    return (0);
}