#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define vi vector < int >

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

int n, ans = 0;
vi a;

main() {
    fileInput("lancan");
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    //for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    for (int i = 0; i < n; i++) {
        int j = i - 1, k = i + 1, res = inf;
        if (0 <= j and j < n) res = min(res, abs(a[i] - a[j]));
        if (0 <= k and k < n) res = min(res, abs(a[i] - a[k]));
        ans += res;
    }
    cout << ans << endl;
}
