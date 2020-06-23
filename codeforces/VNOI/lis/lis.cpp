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
const int N = 3e4 + 7;

int n;
int a[N];
int ans = -inf;

int main() {
    fileInput("lis");
    fast;
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
    }
    vector < int > f(n + 1, inf);
    f[0] = -inf;
    FOR(i, 1, n) {
        int k = lower_bound(f.begin(), f.end(), a[i]) - f.begin();
        f[k] = a[i];
        ans = max(ans, k);
    }
    cout << ans << endl;
    return (0);
}