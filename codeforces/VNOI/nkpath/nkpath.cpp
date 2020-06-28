#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e4 + 7;

int GCD(int a, int b) {
    if (b == 0) return (a);
    else GCD(b, a % b);
}

int n, m;
int a[N][N];
int f[N][N];

int main() {
    fileInput("nkpath");
    fast;
    cin >> n >> m;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> a[i][j];
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m - 1) {
            FOR(p, 1, n) {
                FOR(q, 1, m) {
                    if (i + j < p + q and GCD(a[i][j], a[p][q]) > 1) {
                        f[i][j]++;
                    }
                }
            }
        }
    }
    FOR(i, 1, n) {
        FOR(p, 1, n) {
            FOR(q, 1, m) {
                if (i + m > p + q and GCD(a[i][m], a[p][q]) > 1) {
                    f[i][m] = a[p][q] + 1;
                }
            }
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

    return (0);
}