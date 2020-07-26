#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 7;

int n, k, a[N], f[N];

main() {
    fileInput("frog-2");
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) f[i] = inf;
    f[1] = 0;
    f[2] = abs(a[2] - a[1]);
    for (int i = 3; i <= n; i++) {
        for (int j = i - 1, counter = 0; j >= 1 and counter < k; j--, counter++) {
            f[i] = min(f[i], f[j] + abs(a[i] - a[j]));
        }
    }
    // for (int i = 1; i <= n; i++) cout << f[i] << " ";
    // cout << endl;
    cout << f[n] << endl;
}