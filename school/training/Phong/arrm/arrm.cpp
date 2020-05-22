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
    ll lazy, val;
};

ll n, query;
node ST[4 * N];

void down(ll id) {
    ll t = ST[id].lazy;
    ST[id * 2].lazy += t;
    ST[id * 2].val += t;
    ST[id * 2 + 1].lazy += t;
    ST[id * 2 + 1].val += t;
    ST[id].lazy = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val) {
    if (v < l or r < u) {
        return;
    } else if (u <= l and r <= v) {
        ST[id].val += val;
        ST[id].lazy += val;
        return;
    }
    ll mid = (l + r) / 2;
    down(id);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    ST[id].val = max(ST[id * 2].val , ST[id * 2 + 1].val);
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    if (v < l or r < u) {
        return -inf;
    }
    if (u <= l and r <= v) {
        return ST[id].val;
    }
    ll mid = (l + r) / 2;
    down(id);
    return (max(get(2 * id, l, mid, u, v), get(2 * id + 1, mid + 1, r, u, v)));
}

int main() {
    fileInput("arrm");
    fast;
    cin >> n >> query;
    memset(ST, 0, sizeof(ST));
    for (int qq = 1; qq <= query; qq++) {
        ll u, v, val;
        cin >> u >> v >> val;
        update(1, 1, n, u, v, val);
    }
    ll ans = get(1, 1, n, 1, n);
    cout << ans << endl;
    return (0);
}