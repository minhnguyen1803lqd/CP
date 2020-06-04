#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int esf = 1e-9;

ll n, R, r;

int main() {
    fileInput("table");
    fast;

    cin >> n >> R >> r;
    if (r >= R) cout << "NO\n", exit(0);
    if ((2 * round((2 * R) / (2 * r))) >= n) cout << "YES\n";
    else cout << "NO\n";

    return (0);
}