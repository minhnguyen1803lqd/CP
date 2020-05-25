#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e7 + 7;

struct node {
    ll lazy;
    ll val;
};

node ST[4 * N];
ll n, query;

void down(ll id) {
    ll tmp = ST[id].lazy;
    ST[2 * id].val += tmp;
    ST[2 * id + 1].val += tmp;
    ST[2 * id].lazy += tmp;
    ST[2 * id + 1].lazy += tmp;
    ST[id].lazy = 0;
    return;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l or r < u) {
        return;
    } else if (u <= l and r <= v) {
        ST[id].val += val;
        ST[id].lazy += val;
        return;
    }
    int mid = (l + r) / 2;
    down(id);
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    ST[id].val = max(ST[2 * id].val, ST[2 * id + 1].val);
    return;
}

ll get(int id, int l, int r, int u, int v) {
    if (v < l or r < u) {
        return (-inf);
    } else if (u <= l and r <= v) {
        return (ST[id].val);
    }
    int mid = (l + r) / 2;
    down(id);
    return (max(get(2 * id, l, mid, u, v), get(2 * id + 1, mid + 1, r, u, v)));
}

int main() {
    fileInput("arrm");
    fast;

    // cin >> n >> query;
    scanf("%lld%lld", &n, &query);
    memset(ST, 0, sizeof(ST));
    for (int qq = 1; qq <= query; qq++) {
        ll u, v, val;
        // cin >> u >> v >> val;
        scanf("%lld%lld%lld", &u, &v, &val);
        update(1, 1, n, u, v, val);
    }
    ll ans = get(1, 1, n, 1, n);
    cout << ans << endl;

    return (0);
}