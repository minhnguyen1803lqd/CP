#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e5 + 7;

int n, m, k, col[N], row[N];

int main() {
    fileInput("denon");
    fast;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        row[x] = 1;
        col[y] = 1;
    }
    int freeRow = 0, freeCol = 0;
    for (int i = 1; i <= n; i++) {
        // cerr << row[i] << " ";
        if (!row[i]) freeRow++;
    }
    // cerr << endl;
    for (int i = 1; i <= m; i++) {
        // cerr << col[i] << " ";
        if (!col[i]) freeCol++;
    }
    // cerr << endl;
    // cerr << freeCol << " " << freeRow << endl;
    cout << freeCol * freeRow << endl;

    return (0);
}