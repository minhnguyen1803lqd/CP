/*

 */
#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e200;
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define ll long long

ll n, x, ans;

int main() {
    FileOpen;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        ans += x;
    }
    cout << ans << endl;
}
