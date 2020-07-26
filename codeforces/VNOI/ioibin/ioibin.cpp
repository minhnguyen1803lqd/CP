#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define rank Rank

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e4 + 7;

int query;
int parent[N], rank[N];

void init() {
    for (int i = 1; i <= (int)1e4 + 7; i++) parent[i] = i, rank[i] = 0;
}

int find_set(int v) {
    if (parent[v] == v) return (v);
    return (parent[v] = find_set(parent[v]));
}

main() {
    fileInput("ioibin");

    init();

    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        int x, y, type;
        cin >> x >> y >> type;
        x = find_set(x);
        y = find_set(y);
        if (type == 1) {
            if (x != y) {
                if (rank[x] < rank[y]) swap(x, y);
                parent[y] = x;
                if (rank[x] == rank[y]) rank[x]++;
            }
        } else {
            cout << (x == y) << endl;
        }
    }
}
