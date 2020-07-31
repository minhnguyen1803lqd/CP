#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

vector < int > a;

main() {
    fileInput("capso");
    a.resize(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int p = min(a[2] - a[1], a[1] - a[0]);
    if (a[2] - a[1] == a[1] - a[0]) {
        cout << a[0] - p << " " << a[2] + p << endl;
    } else {
        if (a[2] - a[1] > a[1] - a[0]) cout << a[1] + p << endl;
        else cout << a[1] - p << endl;
    }

}