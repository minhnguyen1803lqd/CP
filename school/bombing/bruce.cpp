#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".ans").c_str(), "w", stdout);
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
    int u, v, w;
    bool enable;
    void show() {
        cout << u << " " << v << " " << w << " " << enable << endl;
    }
};

int n, m;
edge edgeList[N];
int rank[N], root[N];

bool cmp(edge a, edge b) {
    return (a.w < b.w);
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        rank[i] = 0;
        root[i] = i;
    }
    return;
}

int findRoot(int u) {
    if (root[u] == u) {
        return (root[u]);
    } else {
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
}

int countConnectedComponent() {
    int cnt[N];
    int ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        cnt[root[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > 0) ++ans;
    }
    return (ans);
}

bool sameComponent(int u, int v) {
    return (root[u] == root[v]);
}

void DSU() {
    init(n);
    for (int i = 1; i <= m; i++) {
        edge _edge = edgeList[i];
        if (_edge.enable) {
            union(_edge.u, _edge.v);
            union(_edge.v, _edge.u);
        }
    }
    return;
}

void disableEdge(int id) {
    edgeList[id].enable = false;
}

int main() {
    fileInput("bombing");
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        edge newEdge;
        cin >> newEdge.u >> newEdge.v >> newEdge.w;
        newEdge.enable = true;
        edgeList[i] = newEdge;
    }
    DSU();
    sort(edgeList + 1, edgeList + 1 + m, cmp);
    // for (int i = 1; i <= n; i++) {
    //     cout << root[i] << " ";
    // }
    // cout << endl;
    int id = 1;
    int ans = 0;
    while (countConnectedComponent() == 1 and id <= m) {
        disableEdge(id);
        ans += edgeList[id++].w;
        DSU();
    }
    cout << ans << endl;


    return (0);
}