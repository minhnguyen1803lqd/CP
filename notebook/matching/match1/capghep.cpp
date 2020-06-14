#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e4 + 7;

struct bipartiteGraph {
    int nX, nY, m;
    int parent[N];
    int mX[N], mY[N];
    vector < int > g[N];

    void init() {
        cin >> nX >> nY;
        int u, v;
        while (cin >> u >> v) {
            g[u].pb(v);
        }
    }

    int BFS() {
        queue < int > q;
        FOR(u, 1, nX) {
            if (!mX[u]) {
                q.push(u);
            }
        }
        memset(parent, 0, sizeof(parent));
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            REP(i, g[u].size()) {
                int v = g[u][i];
                if (!parent[v]) {
                    parent[v] = u;
                    if (!mY[v]) {
                        return (v);
                    } else {
                        q.push(mY[v]);
                    }
                }
            }
        }
        return (0);
    }

    int getMatching() {
        memset(mX, 0, sizeof(mX));
        memset(mY, 0, sizeof(mY));

        while (int f = BFS()) {
            do {
                int _x = parent[f];
                int _y = mX[_x];
                mX[_x] = f;
                mY[f] = _x;
                f = _y;
            } while (f);
        }
        vector < ii > ans;
        FOR(i, 1, nX) {
            if (mX[i]) {
                ans.pb(ii(i, mX[i]));
            }
        }
        cout << ans.size() << endl;
        REP(i, ans.size()) {
            cout << ans[i].fi << " " << ans[i].se << endl;
        }
        return (ans.size());
    }
};

int main() {
    fileInput("capghep");
    fast;
    bipartiteGraph capghep;
    capghep.init();
    capghep.getMatching();
    return (0);
}