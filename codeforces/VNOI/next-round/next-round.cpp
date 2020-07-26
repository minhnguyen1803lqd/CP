#include <bits/stdc++.h>

using namespace std;

int n, k;
vector < int > a;

main() {
    freopen ("next-round.inp", "r", stdin);
    freopen ("next-round.out", "w", stdout);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    k = a[k - 1];
    //cout << "bug k: " << k << endl;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0 and a[i] >= k) {
            ans++;
        }
    }
    cout << ans << endl;
}
