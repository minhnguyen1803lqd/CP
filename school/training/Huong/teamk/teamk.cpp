#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define iii pair < ii, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 5e4 + 7;

int n, k;
iii a[N];
int f[N];

bool cmp(iii a, iii b) {
    return (a.se < b.se);
}

int main() {
    fileInput("teamk");
    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].se;
        a[i].fi.fi = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    int id = 1;
    for (int i = 1; i <= n / k; i++) {
        for (int j = 1; j <= k; j++) {
            a[id++].fi.se = i;
        }
    }
    sort(a + 1, a + 1 + n);
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i].fi.se >= a[j].fi.se) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    int ans = -inf;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i]);
    }
    cout << n - ans << endl;

    return (0);
}