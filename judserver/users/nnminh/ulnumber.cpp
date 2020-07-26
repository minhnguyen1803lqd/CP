#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define vi vector < int >
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

int n;
set < int > s;

void BFS(int u, int v) {
    queue < int > q;
    set < int > st;
    q.push(u);
    q.push(v);
    st.insert(0);
    s.insert(0);

    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        if (x * 10 + u <= n and st.find(x * 10 + u) == st.end()) {
            s.insert(x * 10 + u);
            st.insert(x * 10 + u);
            q.push(x * 10 + u);
        }
        if (x * 10 + v <= n and st.find(x * 10 + v) == st.end()) {
            s.insert(x * 10 + v);
            st.insert(x * 10 + v);
            q.push(x * 10 + v);
        }
    }
}

int main() {
    fileInput("ulnumber");
    fast;
    cin >> n;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            BFS(i, j);
        }
    }
    cout << s.size() - 1 << endl;
    return (0);
}