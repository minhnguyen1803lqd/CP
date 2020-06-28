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
#define ci pair < char, int >

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e6 + 7;

string s;
stack < ci > st;
int f[N], g[N], d[N];

int main() {
    fileInput("bracket");
    fast;
    cin >> s;
    memset(f, 0, sizeof(f));
    REP(i, s.length()) {
        if (s[i] == '(') {
            st.push(mp('(', i));
        } else {
            if (!st.empty()) {
                if (st.top().fi == '(') {
                    ci tmp = st.top();
                    st.pop();
                    f[tmp.se] = 1;
                    f[i] = 1;
                }
            }
        }
    }
    int n = 0;
    REP(i, s.length()) if (f[i] == 1) d[++n] = i;
    g[1] = 1;
    FOR(i, 2, n) {
        if (d[i] == d[i - 1] + 1) {
            g[i] = g[i - 1] + 1;
        } else {
            g[i] = 1;
        }
    }
    int ans = -inf;
    FOR(i, 1, n) ans = max(ans, g[i]);
    int cnt = 0;
    FOR(i, 1, n) if (g[i] == ans) cnt++;
    if (ans != -inf) cout << ans << " " << cnt << endl;
    else cout << -1 << endl;
    return (0);
}