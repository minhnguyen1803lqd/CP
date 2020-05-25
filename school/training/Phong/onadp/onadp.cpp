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

int n, ans = 0;
int f[4 * N];

int DFS(int id) {
    if (2 * id >= n) {
        return 0;
    }
    DFS(2 * id);
    DFS(2 * id + 1);
    ans += abs(f[2 * id] - f[2 * id + 1]);
    f[id] += max(f[2 * id], f[2 * id + 1]);
}

int main() {
    fileInput("onadp");
    fast;
    cin >> n;
    n = pow(2, n + 1);
    memset(f, 0, sizeof(f));
    for (int i = 2; i <= n - 1; i++) {
        cin >> f[i];
    }

    DFS(1);
    cout << ans << endl;

    return (0);
}