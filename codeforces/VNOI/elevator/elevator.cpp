//  TODO: This problems isn't accept
#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
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

struct node {
    int h, a, c;
}p[N];
int n;
bool f[N];

bool cmp(node x, node y) {
    return (x.a < y.a);
}

int main() {
    fileInput("elevator");
    fast;
    cin >> n;
    FOR(i, 1, n) {
        cin >> p[i].h >> p[i].a >> p[i].c;
    }

    sort(p + 1, p + 1 + n, cmp);
    int limitH = 0;
    FOR(i, 1, n) {
        limitH += p[i].a;
    }
    f[0] = true;
    FOR(i, 1, limitH) {
        FOR(j, 1, n) {
            FOR(k, 1, p[j].c) {
                //if (i - p[j].h * k >= 0) {
                    f[i] = f[i] | f[i - p[j].h * k];
                //}
            }
        }
    }
    int ans = -inf;
    FOR(i, 1, limitH) {
        if (f[i]) ans = max(ans, i);
    }
    cout << ans << endl;

    return (0);
}