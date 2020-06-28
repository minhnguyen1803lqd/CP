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

int n, m;
int a[N][N];
int color[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int ans = 0;

void BFS(int x, int y) {
    queue < ii > q;
    color[x][y] = 1;
    q.push(mp(x, y));
    int cnt = 0;
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        cnt++;
        for (int k = 0; k < 4; k++) {
            int i = u.fi + dx[k];
            int j = u.se + dy[k];
            if (color[i][j] == 0 and a[i][j] == 1) {
                color[i][j] = 1;
                q.push(mp(i, j));
            }
        }
    }
    //cout << cnt << endl;
    ans = max(ans, cnt);
}

int main() {
    fileInput("chuot");
    fast;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char tmp;
            cin >> tmp;
            a[i][j] = int(tmp) - '0';
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        a[i][0] = a[i][m + 1] = 0;
    }
    for (int i = 0; i <= m + 1; i++) {
        a[0][i] = a[n + 1][i] = 0;
    }

    // for (int i = 0; i <= n + 1; i++) {
    //     for (int j = 0; j <= m + 1; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1 and color[i][j] == 0) {
                BFS(i, j);
            }
        }
    }
    cout << ans << endl;

    return (0);
}