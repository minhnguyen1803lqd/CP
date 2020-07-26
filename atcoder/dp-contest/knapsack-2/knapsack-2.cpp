#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define ii pair < int, int >
#define weight first
#define val second

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 7;

int n, w, sumVal = 0;
int f[107][N];
ii a[N];

bool cmp(ii a, ii b) {
    return (a.val < b.val);
}

main() {
    fileInput("knapsack-2");
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].weight >> a[i].val;
        sumVal += a[i].val;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sumVal; j++) {
            f[i][j] = inf;
        }
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 0; i <= n; i++) f[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sumVal; j++) {
            if (a[i].val <= j) {
                f[i][j] = min(f[i - 1][j], f[i - 1][j - a[i].val] + a[i].weight);
            } else f[i][j] = f[i - 1][j];
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= sumVal; j++) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = sumVal; i >= 1; i--) {
        if (f[n][i] <= w) {
            cout << i << endl;
            return (0);
        }
    }
    cout << "nothing\n";
}