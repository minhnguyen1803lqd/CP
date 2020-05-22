#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define union Union
#define rank Rank

const int inf = 1e9 + 7;
const int N = 1e3 + 7;

struct edge {
    int u, v, cap, flow;
};

int n, m;
int graph[N][N];
int root[N], rank[N];
edge edgeList[N];

void init() {
    for (int i = 1; i <= n; i++) {
        rank[i] = 0;
        root[i] = i;
    }
    return;
}

int findRoot(int u) {
    if (root[u] = u) return (root[u]);
    else {
        root[u] = findRoot(root[u]);
        return (root[u]);
    }
}

void union(int u, int v) {
    int uu = findRoot(u);
    int vv = findRoot(v);
    if (uu == vv) {
        return;
    } else {
        if (rank[uu] < rank[vv]) {
            swap(uu, vv);
        }
        root[vv] = uu;
        if (rank[uu] == rank[vv]) {
            rank[uu]++;
        }
    }
    return;
}

int countComponents() {
    int cnt[N];
    int ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        cnt[root[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) ans++;
    }
    return (ans);
}

void Karger() {
    int ok[N];
    memset(ok, 0, sizeof(ok));
    while (countComponents() > 2) {
        int id;
        do {
            id = rand() % m + 1;
        } while (ok[id]);

        edge _edge = edgeList[id];

        int _u = findRoot(u);
        int _v = findRoot(v);

        if (_u == _v) {
            return;
        } else {
            union(u, v);
            for (int i = 1; i <= n; i++) {
                cerr << root[i] << " ";
            }
            cerr << endl;
            n--;
        }
    }
}

int main() {
    fileInput("bombing");
    fast;
    srand(time(NULL));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edge _edge;
        _edge.u = u;
        _edge.v = v;
        _edge.cap = c;
        graph[u][v] = c;
        edgeList[i] = _edge;
    }

    Karger();

    return (0);
}