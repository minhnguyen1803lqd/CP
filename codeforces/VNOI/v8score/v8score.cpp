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
const int N = 1e3 + 7;

int n, s, k;
int a[N][N];
int x[N], ans[N];

void backTrack(int id) {
    if (id == k + 1) {
        FOR(i, 1, k) {
            cout << x[i] << " ";
        }
        cout << endl;
        exit(0);
    } else {
        FOR(i, 1, n) {
            if (a[id][i] >= x[id - 1] and a[id][i] + x[id - 1] <= s) {
                x[id] = a[id][i];
                backTrack(id + 1);
            }
        }
    }
}

int main() {
    fileInput("v8score");
    fast;
    cin >> s >> k >> n;
    FOR(i, 1, n) {
        FOR(j, 1, k) {
            cin >> a[i][j];
        }
    }
    x[0] = 0;
    backTrack(1);

    cout << "NO\n";

    return (0);
}