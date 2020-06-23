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
const int MOD = 2111992;

int n, k;

int main() {
    fileInput("ctnbulls");
    fast;
    cin >> n >> k;
    int f[N];
    f[0] = 1;
    FOR(i, 1, n) {
        f[i] = f[i - 1];
        if (i > k) {
            f[i] += f[i - k - 1];
        } else {
            f[i]++;
        }
        f[i] %= MOD;
    }
    cout << f[n] << endl;
    return (0);
}