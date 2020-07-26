#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 7;

int n, a[N], f[N];

main() {
    fileInput("frog-1");
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    f[1] = 0;
    f[2] = abs(a[2] - a[1]) + f[1];
    for (int i = 3; i <= n; i++) {
    	f[i] = min(f[i - 2] + abs(a[i] - a[i - 2]), f[i - 1] + abs(a[i] - a[i - 1]));
    }
    cout << f[n] << endl;
}