#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define ii pair < int, int >

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e2 + 7;

int n;
int a[N][N];
int color[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int minVal = inf;

bool Try(int limit) {
    queue < ii > q;
    q.push(make_pair(1, 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            color[i][j] = 0;
        }
    }

    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        for (int k = 0; k <= 4; k++) {
            int x = u.first + dx[k];
            int y = u.second + dy[k];
            if (1 <= x and x <= n and 1 <= y and y <= n and !color[x][y] and a[x][y] <= minVal + limit) {
                q.push(make_pair(x, y));
                color[x][y] = 1;
            }
        }
    }
    return (color[n][n]);
}

main() {
    fileInput("mtwalk");
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            minVal = min(minVal, a[i][j]);
        }
    }
    int left = 1, right = 110;
    int ans = inf;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (Try(mid)) {
            //cout << "mid: " << mid << endl;
            ans = min(ans, mid);
            right = mid - 1;
        } else left = mid + 1;
    }
    cout << ans << endl;
}
