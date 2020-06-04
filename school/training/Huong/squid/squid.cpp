#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e6 + 7;

int n, k, ans = -inf;
int f[N];

int main() {
    fileInput("squid");
    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x, tmp;
        cin >> tmp >> x;
        f[x] += tmp;
    }
    f[0] = 0;
    for (int i = 1; i <= N - 2; i++) {
        f[i] = f[i - 1] + f[i];
    }
    k = min(int(1e6), 2 * k + 1);
    for (int i = k; i <= N - 2; i++) {
        ans = max(ans, f[i] - f[i - k]);
    }
    cout << ans << endl;
    return (0);
}