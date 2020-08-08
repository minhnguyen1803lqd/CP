#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e3 + 7;

int n, query;
int a[N][N];
int black[N][N], white[N][N];

main() {
    fileInput("vboard");
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            black[i][j] = white[i][j] = 0;
        }
    }



    cin >> query;
    while (query--) {
        int u1, v1, u2, v2;
        cin >> u1 >> v1 >> u2 >> v2;
    }
}