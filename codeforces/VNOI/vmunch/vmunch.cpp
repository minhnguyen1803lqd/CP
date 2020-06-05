#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
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

int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void BFS(ii source) {
    queue < ii > q;
    int color[N][N];
    memset(color, 0, sizeof(color));
    q.push(source);
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        REP(k, 4) {
            if (!color[u.fi + dx[k]][u.se + dy[k]]) {
                
            }
        }
    }
}

int main() {
    fileInput("vmunch");
    fast;
    cin >> n >> m;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            chat tmp;
            cin >> tmp;
            if (tmp == 'B') source = ii(i, j);
            if (tmp == 'C') sink = ii(i, j);
            if (tmp == '*') color[i][j] = 1;
        }
    }
    BFS(source);
    return (0);
}