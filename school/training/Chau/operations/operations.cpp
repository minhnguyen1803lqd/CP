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
const int N = 1e4 + 7;

int query, n;
int f[N];

int main() {
    fileInput("operations");
    fast;
    cin >> query;
    f[1] = 1;
    f[0] = 0;
    f[2] = 2;
    for (int i = 3; i <= int(1e4); i++) {
        if (i % 2 == 0) f[i] = min(f[i - 1] + 1, f[i / 2] + 1);
        else f[i] = f[i - 1] + 1;
    }
    // for (int i = 1; i <= 10; i++) {
    //     cout << f[i] << " ";
    // }
    // cout << endl;
    for (int qq = 1; qq <= query; qq++) {
        cin >> n;
        cout << f[n] << endl;
    }
    return (0);
}