#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define pll pair < ll, ll >

const int inf = 1e9 + 7;
const int N = 1e5 + 7;

ll n, m;
pll a[N];

int main() {
    fileInput("buying");
    fast;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n);

    ll id = 1;
    ll ans = 0;
    while (m - (a[id].fi * a[id].se) >= 0 and id <= n) {
        m -= a[id].fi * a[id].se;
        ans += a[id].se;
        id++;
    }
    if (id <= n) {
        ans += min(m / a[id].fi, a[id].se);
    }
    cout << ans << endl;

    return (0);
}