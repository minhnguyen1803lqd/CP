#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define SET(x, val) memset(x, val, sizeof(x))
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e3 + 7;
const int M = 1e5 + 7;

int n, m, k;
int a[N][N], cnt[M];

int main() {
    fileInput("izone");
    fast;
    cin >> n >> m >> k;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> a[i][j];
        }
    }
    SET(cnt, 0);
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            int s = a[i + 1][j + 1] + a[i - 1][j - 1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j] + a[i - 1][j] + a[i + 1][j - 1] + a[i - 1][j + 1];
            cnt[s] = 1;
        }
    }
    FOR(i, 1, k) {
        int tmp;
        cin >> tmp;
        cout << cnt[tmp] << endl;
    }
    return (0);
}