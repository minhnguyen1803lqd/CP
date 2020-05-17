#include <bits/stdc++.h>

#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);

const int inf = 1e9 + 7;

using namespace std;

int query, n, k;

int main() {
    fileInput("b");
    fast;
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> n >> k;
        if (n == k) {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) {
                cout << 1 << " ";
            }
        } else if (n % 2 != 0 and k % 2 == 0) {
            cout << "NO";
        } else if (n < k or (n % 2 == 0 and (2 * k > n))) {
            cout << "NO";
        } else {
            cout << "YES\n";
            if (n % 2 == 0) {
                cout << n - (2 * (k - 1)) << " ";
                for (int i = 1; i <= k - 1; i++) {
                    cout << 2 << " ";
                }
            } else {
                cout << n - (k - 1) << " ";
                for (int i = 1; i <= k - 1; i++) {
                    cout << 1 << " ";
                }
            }
        }
        cout << endl;
    }
    return (0);
}