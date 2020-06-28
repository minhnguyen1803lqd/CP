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

int n, m;
ii a[N];

bool cmp(ii a, ii b) {
    return (a.se > b.se);
}

int main() {
    fileInput("burglar");
    fast;
    cin >> n >> m;
    FOR(i, 1, m) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + m, cmp);
    int i = 1, ans = 0;
    while (i <= m) {
        if (a[i].fi <= n) {
            n -= a[i].fi;
            ans += (a[i].fi * a[i].se);
        } else {
            break;
        }
        i++;
    }
    if (n != 0) {
        ans += n * a[i].se;
    }
    cout << ans << endl;
    return (0);
}