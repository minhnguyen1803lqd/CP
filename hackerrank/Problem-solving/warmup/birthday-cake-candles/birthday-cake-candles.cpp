/*

 */
#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e5 + 10;
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

int n;
int a[N], maxNum = -inf, ans = 0;

int main() {
    FileOpen;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxNum = max(maxNum, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == maxNum) ans++;
    }
    cout << ans << endl;
}
