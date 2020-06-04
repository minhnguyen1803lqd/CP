#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ll long long
#define ii pair < ll, ll >
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e5 + 7;

ll n, s;
ii a[N];
ll ans = 0;

int main() {
    fileInput("buying");
    fast;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n);
    int i = 1;
    while (s - a[i].fi * a[i].se >= 0 and i <= n) {
        s -= a[i].fi * a[i].se;
        ans += a[i].se;
        i++;
    }
    ans += (min(a[i].se, s / a[i].fi));
    cout << ans << endl;
    return (0);
}