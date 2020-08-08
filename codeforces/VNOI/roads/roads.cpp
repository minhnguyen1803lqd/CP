#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define ii pair < int, int >
#define iii pair < int, ii >
#define fi first
#define se second

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e3 + 7;

int k, n, m;
vector < iii > adj[N];

void dijsktra() {
    
}

main() {
    fileInput("roads");
    int query = 0;
    cin >> query;
    while (query--) {
        cin >> k >> n >> m;
        for (int i = 1; i <= m; ++i) {
            int u, v, w, c;
            cin >> u >> v >> w >> c;
            adj[u].push_back(make_pair(v, make_pair(w, c)));
        }
    }
}