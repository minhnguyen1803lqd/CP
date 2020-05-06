/*

 */
#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

int n;
int a[N][N];
int l = 0, r = 0, ans = 0;

main() {
    FileOpen;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) l += a[i][i];
    for (int i = 1; i <= n; i++) r += a[n + 1 - i][i];
    ans = abs(l - r);
    cout << ans << endl;
}
