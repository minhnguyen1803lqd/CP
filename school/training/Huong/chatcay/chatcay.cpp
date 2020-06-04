#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

int n, w;
ii a[N];
int f[N][N];

int main() {
    fileInput("chatcay");
    fast;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    for (int i = 1; i <= w; i++) {
        if (a[1].fi <= i) f[1][i] = a[1].se;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i].fi > j) {
                f[i][j] = f[i - 1][j];
            } else {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i].fi] + a[i].se);
            }
        }
    }

    cout << f[n][w] << endl;

    return (0);
}