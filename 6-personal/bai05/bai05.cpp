#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int oo = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

int n, a[N], ans = oo, f[N];

int main() {
    FileOpen;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
    f[0] = 0;
    for (int i = 1; i <= 2 * n; i++) f[i] = f[i - 1] + a[i];
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            int s = f[j] - f[i - 1];
            ans = min(ans, s);
        }
    }
    cout << ans << endl;
}
