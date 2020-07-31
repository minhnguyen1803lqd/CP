#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

int n, m, k;

main() {
    fileInput("chiaqua");
    cin >> n >> m >> k;
    int a = k / 2, b = k - k / 2;
    cout << (a + 1) * (b + 1) << endl;
}