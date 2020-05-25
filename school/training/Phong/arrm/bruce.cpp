#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".ans").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e7 + 7;

int n, query;
int u, v, val;
int f[N];
int ans = -inf;

void bruceLevel1() {
    cin >> n >> query;
    memset(f, 0, sizeof(f));
    for (int qq = 1; qq <= query; qq++) {
        cin >> u >> v >> val;
        for (int i = u; i <= v; i++) {
            f[i] += val;
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;
}

void bruceLevel2() {
    cin >> n >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> u >> v >> val;
        f[u] += val;
        f[v] -= val;
    }
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i];
    }
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;
}

int main() {
    fileInput("arrm");
    fast;
    
    bruceLevel1();
    
    return(0);
}