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
const int N = 1e7 + 7;

struct node {
    int power, val, id;
};

int n, k;
node a[N];
vector < node > ls[N];

bool cmp(node a, node b) {
    return (a.val > b.val);
}

int main() {
    fileInput("kill");
    fast;
    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> a[i].power;
        a[i].id = i;
    }
    FOR(i, 1, n) {
        cin >> a[i].val;
    }

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (a[i].power > a[j].power) {
                ls[i].pb(a[j]);
            }
        }
    }
    FOR(i, 1, n) {
        sort(ls[i].begin(), ls[i].end(), cmp);
    }
    FOR(i, 1, n) {
        ll s = a[i].val;
        int cnt = 0;
        REP(j, ls[i].size()) {
            s += ls[i][j].val;
            cnt++;
            if (cnt == k) break;
        }
        cout << s << " ";
    }

    return (0);
}