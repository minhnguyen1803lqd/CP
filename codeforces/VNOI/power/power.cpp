#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

int query;
ll L, R;

main() {
    fileInput("power");
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> L >> R;
        for (int k = 40; k >= 1; k--) {
            ll left = 0, right = (ll)(pow(R, 1.0 / k) + 10);
            while (left < right) {
                ll mid = (left + right) / 2;
                ll tmp = 1;
                for (int i = 1; i <= k; i++) {
                    tmp *= mid;
                    if (tmp >= L) break;
                }
                if (tmp >= L) right = mid;
                else left = mid + 1;
            }
            ll tmp = 1;
            for (int i = 1; i <= k; i++) {
                tmp *= left;
                if (tmp > R) break;
            }
            if (L <= tmp and tmp <= R) {
                cout << "Case #" << qq << ": " << k << "\n";
                break;
            }
        }
    }
}