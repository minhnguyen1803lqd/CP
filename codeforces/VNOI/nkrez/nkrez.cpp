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

int n;
ii a[N];
int f[N];

bool cmp(ii a, ii b) {
    return (a.se < b.se);
}

int Search(int l, int r, int val) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid].se <= val) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return (r);
}

int main() {
    fileInput("nkrez");
    fast;
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n, cmp);
    f[0] = 0;
    f[1] = a[1].se - a[1].fi;
    FOR(i, 2, n) {
        int k = Search(1, i - 1, a[i].fi);
        f[i] = max(f[i - 1], f[k] + a[i].se - a[i].fi);
    }
    // FOR(i, 1, n) {
    //     cout << f[i] << endl;
    // }
    cout << f[n] << endl;

    return (0);
}