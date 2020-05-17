#include <bits/stdc++.h>

#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define union Union
#define rank Rank
#define iii pair < ii, int >

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

using namespace std;

struct edgeType {
    int u, v, w;
    bool enable;
};

int n, m;
edgeType edgeList[N];
int root[N], rank[N];

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

void makeDSU() {
    init(n);
    for (int i = 1; i <= m; i++) {
        edgeType edge = edgeList[i];
        if (edge.enable) {
            union(edge.u, edge.v);
        }
    }
    return;
}

void disableEdge(int id) {
    edgeList[id].enable = false;
}

int main() {
    fileInput("DSU");
    fast;

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        edgeType newEdge;
        cin >> newEdge.u >> newEdge.v;
        newEdge.enable = true;
        edgeList[i] = newEdge;
    }

    makeDSU();
    for (int i = 1; i <= n; i++) {
        cout << root[i] << " ";
    }
    cout << endl;
    int query;
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        char type;
        int u, v;
        cin >> type >> u >> v;
        if (type == '?') {
            cout << u << " " << v << ": " << sameComponent(u, v) << endl;
            cout << "number of component: " << countConnectedComponent() << endl;
        } else {
            for (int i = 1; i <= m; i++) {
                edgeType edge = edgeList[i];
                cout << edge.u << " "  << edge.v << " " << edge.enable << endl;
            }
            for (int i = 1; i <= n; i++) {
                cout << root[i] << " ";
            }
            cout << endl;
            for (int i = 1; i <= m; i++) {
                edgeType edge = edgeList[i];
                if ((edge.u == u && edge.v == v) || (edge.u == v && edge.v == u)) {
                    edgeList[i].enable = 0;
                }
            }
            makeDSU();

            for (int i = 1; i <= m; i++) {
                edgeType edge = edgeList[i];
                cout << edge.u << " "  << edge.v << " " << edge.enable << endl;
            }
            for (int i = 1; i <= n; i++) {
                cout << root[i] << " ";
            }
            cout << endl;
        }
        
    }

    return (0);
}