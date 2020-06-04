#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e4 + 7;
const int esf = 1e-9;

int n;
int a[N][N], f[N];

int main() {
    fileInput("colorec");
    fast;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        a[x + 200][y + 200] = 1 << (c - 1);
    }

    ll res = 0;
    for (int i = 0; i <= 400; i++) {
        for (int j = 0; j <= i; j++) {
            for (int i = 0; i <= 17; i++) f[i] = 0;
            for (int k = 0; k <= 400; k++) {
                if (a[i][k] && a[j][k] && a[i][k] != a[j][k]) {
                    int c = a[i][k] | a[j][k];
                    res += f[15 - c];
                    f[c]++;
                }
            }
        }
    }
    cout << res << endl;

    return (0);
}