#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

int query, a, b, c;

main() {
    fileInput("ac1");
    cin >> query;
    while (query--) {
        cin >> a >> b >> c;
        int ans = min(a + b + c, min(2 * (a + b), min(2 * (a + c), 2 * (b + c))));
        cout << ans << endl;
    }
}