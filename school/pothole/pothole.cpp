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

int n, source, sink;
int graph[N][N], revGraph[N][N];

int main() {
    fileInput("pothole");
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            graph[i][x] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return (0);
}