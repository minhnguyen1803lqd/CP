#include <bits/stdc++.h>

#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

using namespace std;

int query, n, k, f[N], g[N], a[N];

int main() {
    fileInput("d");
    fast;
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        f[0] = 0, g[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + a[i];
        }
        for (int i = n; i >= 1; i--) {
            g[i] = g[i + 1] + a[i];
        }

        int ans1 = 0, ans2 = 0, cnt = 0, curr = 0;
        int L = 0, R = n + 1;
        do {
            int l = L, r = R;
            while (f[l] - f[L] <= curr and l <= R) l++;
            if (l >= r)
                break;
            if (f[l] - f[L] > curr) {
                ans1 += f[l] - f[L];
                curr = f[l] - f[L];
                cnt++;
                L = l;
            } else if (f[l] - f[L] <= curr) {
                cnt++;
                ans1 += f[l] - f[L];
                break;
            }
            while (g[r] - g[R] <= curr and L <= r) r--;
            if (l >= r)
                break;
            if (g[r] - g[R] > curr) {
                ans2 += g[r] - g[R];
                curr = g[r] - g[R];
                cnt++;
                R = r;
            } else if (g[r] - g[R] <= curr) {
                cnt++;
                ans2 += g[r] - g[R];
                break;
            }
        } while (true);
        cout << cnt << " " << ans1 << " " << ans2 << endl;
    }
    return (0);
}