#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

int n;
vector < int > s, f, g;

main() {
    fileInput("nkseq");
    cin >> n;
    s.resize(n + 1);
    f.resize(n + 1);
    g.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> s[i], s[i] += s[i - 1];

    for (int i = n, smin = s[n]; i >= 1; --i) {
        f[i] = s[i - 1] < smin;
        smin = min(smin, s[i - 1]);
    }

    for (int i = 1, smin = s[n]; i <= n; ++i) {
        g[i] = s[i - 1] < smin;
        smin = min(smin, s[n] + s[i - 1]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += f[i] & g[i];
    cout << ans << endl;
}