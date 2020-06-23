#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define ii pair < int, int >
#define iii pair < ii, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e4 + 7;

int n;
iii a[N];
int f[N];

bool cmp(iii a, iii b) {
    return(a.fi.se < b.fi.se);
}

int main() {
    fileInput("dq");
    fast;
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
    }
    sort(a + 1, a + 1 + n, cmp);
    f[0] = 0;
    f[1] = a[1].se;
    FOR(i, 2, n) {
        f[i] = f[i - 1];
        FOR(j, 0, i - 1) {
            if (a[i].fi.fi >= a[j].fi.se) {
                f[i] = max(f[i], f[j] + a[i].se);
            }
        }
    }
    // FOR(i, 1, n) {
    //     cout << f[i] << " ";
    // }
    // cout << endl;
    cout << f[n] << endl;
    return (0);
}